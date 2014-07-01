<?php
/**
 * @file
 * iris_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function iris_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_blocks';
  $context->description = 'Configuration générale des blocks du site.';
  $context->tag = 'Commun';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-28' => array(
          'module' => 'block',
          'delta' => '28',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'block-22' => array(
          'module' => 'block',
          'delta' => '22',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'block-23' => array(
          'module' => 'block',
          'delta' => '23',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Commun');
  t('Configuration générale des blocks du site.');
  $export['common_blocks'] = $context;

  return $export;
}
