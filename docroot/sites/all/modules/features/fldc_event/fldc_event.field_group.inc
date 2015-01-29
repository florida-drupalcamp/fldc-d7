<?php
/**
 * @file
 * fldc_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fldc_event_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_buildout2_wtab|node|even|form';
  $field_group->group_name = 'group_even_buildout2_wtab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buildout2',
    'weight' => '2',
    'children' => array(
      0 => 'group_even_sche_htab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-even-buildout2-wtab field-group-htabs',
      ),
    ),
  );
  $export['group_even_buildout2_wtab|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_descr_htab|node|even|form';
  $field_group->group_name = 'group_even_descr_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_even_htg';
  $field_group->data = array(
    'label' => 'Descriptives',
    'weight' => '8',
    'children' => array(
      0 => 'field_even_body',
      1 => 'field_even_eventy_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-even-descr-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_even_descr_htab|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_htg|node|even|form';
  $field_group->group_name = 'group_even_htg';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buildout',
    'weight' => '1',
    'children' => array(
      0 => 'group_even_slot_htab',
      1 => 'group_even_spea_htab',
      2 => 'group_even_venu_htab',
      3 => 'group_even_spon_htab',
      4 => 'group_even_descr_htab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-even-htg field-group-htabs',
      ),
    ),
  );
  $export['group_even_htg|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_sche_htab|node|even|form';
  $field_group->group_name = 'group_even_sche_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_even_buildout2_wtab';
  $field_group->data = array(
    'label' => 'Schedule Items',
    'weight' => '7',
    'children' => array(
      0 => 'field_even_sche_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Schedule Items',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-even-sche-htab field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_even_sche_htab|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_slot_htab|node|even|form';
  $field_group->group_name = 'group_even_slot_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_even_htg';
  $field_group->data = array(
    'label' => 'Time Slots',
    'weight' => '5',
    'children' => array(
      0 => 'field_even_slot_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-even-slot-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_even_slot_htab|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_spea_htab|node|even|form';
  $field_group->group_name = 'group_even_spea_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_even_htg';
  $field_group->data = array(
    'label' => 'Featured Speakers',
    'weight' => '7',
    'children' => array(
      0 => 'field_even_bio_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-even-spea-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_even_spea_htab|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_spon_htab|node|even|form';
  $field_group->group_name = 'group_even_spon_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_even_htg';
  $field_group->data = array(
    'label' => 'Sponsors',
    'weight' => '6',
    'children' => array(
      0 => 'field_even_spon_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-even-spon-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_even_spon_htab|node|even|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_even_venu_htab|node|even|form';
  $field_group->group_name = 'group_even_venu_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'even';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_even_htg';
  $field_group->data = array(
    'label' => 'Venue',
    'weight' => '4',
    'children' => array(
      0 => 'field_even_venu_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-even-venu-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_even_venu_htab|node|even|form'] = $field_group;

  return $export;
}
