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
        'views-rubriques-other_analyse' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_analyse',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'nodeblock-16' => array(
          'module' => 'nodeblock',
          'delta' => '16',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--ej---pour-battlelab' => array(
          'module' => 'bean',
          'delta' => '-ej---pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean-lessentiel-pour-battlelab' => array(
          'module' => 'bean',
          'delta' => 'lessentiel-pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean--cp---pour-battlelab' => array(
          'module' => 'bean',
          'delta' => '-cp---pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-6',
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
