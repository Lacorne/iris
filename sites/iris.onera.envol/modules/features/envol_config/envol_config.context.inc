<?php
/**
 * @file
 * envol_config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function envol_config_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'analyse';
  $context->description = 'Gestion des blocks de la home Analyse';
  $context->tag = 'Pages Analyse';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'analyse' => 'analyse',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nodeblock-16' => array(
          'module' => 'nodeblock',
          'delta' => '16',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gestion des blocks de la home Analyse');
  t('Pages Analyse');
  $export['analyse'] = $context;

  return $export;
}
