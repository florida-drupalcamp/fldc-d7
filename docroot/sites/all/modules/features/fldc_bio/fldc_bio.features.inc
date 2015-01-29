<?php
/**
 * @file
 * fldc_bio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fldc_bio_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function fldc_bio_node_info() {
  $items = array(
    'bio' => array(
      'name' => t('Bio'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'bioty' => array(
      'name' => t('Bio Type'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
