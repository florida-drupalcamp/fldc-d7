<?php

/**
 * Implements hook_preprocess_page().
 */
function fldc17_preprocess_page(&$variables) {
  if (drupal_is_front_page()) {
    drupal_add_js(drupal_get_path('theme', 'fldc17') . '/js/vendor/vector_battle_regular.typeface.js', 'file');
    drupal_add_js(drupal_get_path('theme', 'fldc17') . '/js/asteroid.js', 'file');
  }
}
