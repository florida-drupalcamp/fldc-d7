<?php
/**
 * @file
 * Administration functionality for Eventbrite Integration.
 */

/**
 * Form builder callback.
 *
 * Builds a form for mapping between Eventbrite fields and Bio fields.
 */
function eventbrite_integration_bio_field_mapping($form, &$form_state) {
  $form['help_text'] = array(
    '#markup' =>
      "<p>" . t("Create mappings between Eventbrite order form fields and Bio fields.") . "</p>" .
      "<p>" . t("Each select field is a field on the event's Eventbrite order form, and the options in the field are fields on the Bio content type.") . "</p>",
  );

  // Load the V3 Eventbrite API.
  $api = new EventbriteV3();

  // Default profile questions.
  $default_questions = array(
    'first_name' => 'First Name',
    'last_name' => 'Last Name',
    'email' => 'Email Address',
    'cell_phone' => 'Cell Phone',
    'job_title' => 'Job Title',
    'company' => 'Company / Organization',
    'website' => 'Website',
  );

  // Build a list of all Bio fields, for a select list.
  $fields_info = field_info_instances('node', 'bio');
  $field_options = array(
    '' => t('- Select -'),
  );
  foreach ($fields_info as $name => $field_info) {
    $field_options[$name] = $field_info['label'];
  }

  // Get a list of all events.
  $events = eventbrite_integration_get_events();
  if (empty($events)) {
    drupal_set_message(t('Unable to load any events.'), 'error');
    return $form;
  }

  // For each event, build a fieldset of fields to map.
  foreach ($events as $event) {
    // Start with the default questions.
    $event_questions = $default_questions;
    $event = node_load($event->nid);
    // Store the NID for convenience, since it will be re-used often.
    $nid = $event->nid;
    $event_id = field_get_items('node', $event, 'field_even_eventbrite');
    if (!empty($event_id[0]['value'])) {
      $eventbrite_id = $event_id[0]['value'];
    }
    else {
      // Skip the event if it doesn't have an Eventbrite ID.
      continue;
    }

    // Load custom Eventbrite questions.
    $questions = $api->get_event_questions($eventbrite_id);
    foreach ($questions->questions as $question) {
      $question_id = $question->id;
      $question_text = $question->question->text;
      $event_questions[$question_id] = $question_text;
    }

    // Build the fieldset for the event.
    $event_fieldset_id = EVENTBRITE_INTEGRATION_MAPPING_PREFIX . $nid;
    $form[$event_fieldset_id] = array(
      '#type' => 'fieldset',
      '#title' => $event->title,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
    );
    // Store the fieldset as a reference for convenience.
    $fieldset = &$form[$event_fieldset_id];
    // Create each Eventbrite field as a select list. The options are the fields
    //from the Bio content type.
    $default_form_values = variable_get($event_fieldset_id, array());
    foreach ($event_questions as $question_id => $question_label) {
      $fieldset[$question_id] = array(
        '#type' => 'select',
        '#options' => $field_options,
        '#title' => $question_label,
        '#default_value' => array_key_exists($question_id, $default_form_values) ? $default_form_values[$question_id] : '',
      );
    }
  }

  $form = system_settings_form($form);
  // Remove the system_settings_form_submit() submit handler.
  $form['#submit'] = array(
    'eventbrite_integration_bio_field_mapping_submit',
  );
  return $form;
}

/**
 * Form submission handler.
 *
 * @see eventbrite_integration_bio_field_mapping()
 */
function eventbrite_integration_bio_field_mapping_submit($form, &$form_state) {
  // Get a list of all events.
  $events = eventbrite_integration_get_events();
  // Easy access to the values.
  $values = $form_state['values'];
  foreach ($events as $event) {
    // Store the form values per event as an array.
    $field_id = EVENTBRITE_INTEGRATION_MAPPING_PREFIX . $event->nid;
    if (!empty($values[$field_id])) {
      variable_set($field_id, $values[$field_id]);
    }
  }
}
