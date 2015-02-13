<?php

/**
 * Implements hook_preprocess_region().
 */
function fldc14_preprocess_region(&$vars) {
  if ( $vars['region'] == 'navigation' ) {
    $vars['site_name'] = ( theme_get_setting('toggle_name') ? variable_get('site_name', 'Florida DrupalCamp 2014') : '' );
    $vars['base_path'] = base_path();
    $vars['front_page'] = url();
    $vars['primary_nav'] = menu_tree_output(menu_tree_all_data('main-menu'));
  }
}
