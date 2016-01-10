<?php

/**
 * @file
 * Contains all the context exports.
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_omega_test_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_omega_test';
  $context->description = 'Omega test';
  $context->tag = 'context_omega_test';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'custom-omega-test' => 'custom-omega-test',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'context_omega_test-custom_block' => array(
          'module' => 'context_omega_test',
          'delta' => 'custom_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export[$context->name] = $context;

  return $export;
}
