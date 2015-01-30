<?php
/**
 * @file
 * fldc_bio.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fldc_bio_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_buildout_wtab|node|bio|form';
  $field_group->group_name = 'group_bio_buildout_wtab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bio';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buildout',
    'weight' => '1',
    'children' => array(
      0 => 'group_bio_descr_htab',
      1 => 'group_bio_fullbio_htab',
      2 => 'group_bio_images_htab',
      3 => 'group_bio_registraion_htab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-bio-buildout-wtab field-group-htabs',
      ),
    ),
  );
  $export['group_bio_buildout_wtab|node|bio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_descr_htab|node|bio|form';
  $field_group->group_name = 'group_bio_descr_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_buildout_wtab';
  $field_group->data = array(
    'label' => 'Descriptives',
    'weight' => '11',
    'children' => array(
      0 => 'field_bio_firstname',
      1 => 'field_bio_lastname',
      2 => 'field_bio_worktitle',
      3 => 'field_bio_bioty_ref',
      4 => 'field_bio_web_site',
      5 => 'field_bio_co_org_name',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-descr-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_bio_descr_htab|node|bio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_fullbio_htab|node|bio|form';
  $field_group->group_name = 'group_bio_fullbio_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_buildout_wtab';
  $field_group->data = array(
    'label' => 'Full Bio',
    'weight' => '12',
    'children' => array(
      0 => 'field_bio_body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-fullbio-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_bio_fullbio_htab|node|bio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_images_htab|node|bio|form';
  $field_group->group_name = 'group_bio_images_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_buildout_wtab';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '13',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-images-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_bio_images_htab|node|bio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_registraion_htab|node|bio|form';
  $field_group->group_name = 'group_bio_registraion_htab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_buildout_wtab';
  $field_group->data = array(
    'label' => 'Registration',
    'weight' => '14',
    'children' => array(
      0 => 'field_bio_portrait',
      1 => 'field_bio_eventbrite',
      2 => 'field_bio_meal',
      3 => 'field_bio_tshirt_size',
      4 => 'field_bio_do_profile',
      5 => 'field_bio_twitter_profile',
      6 => 'field_bio_my_interest',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-registraion-htab field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_bio_registraion_htab|node|bio|form'] = $field_group;

  return $export;
}
