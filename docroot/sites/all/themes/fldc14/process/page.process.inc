<?php

/**
 * Implements hook_process_page().
 */
function fldc14_process_page(&$vars) {
  // You can use process hooks to modify the variables before they are passed to
  // the theme function or template file.
  $vars['logo'] = '/' . drupal_get_path('theme', 'fldc14') . '/logo.svg';
}
