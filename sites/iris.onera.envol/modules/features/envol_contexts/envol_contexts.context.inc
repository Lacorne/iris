<?php
/**
 * @file
 * envol_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function envol_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agenda';
  $context->description = 'Gestion des blocks de la home Agenda';
  $context->tag = 'Pages Agenda';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agenda' => 'agenda',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean---esp----test' => array(
          'module' => 'bean',
          'delta' => '--esp----test',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gestion des blocks de la home Agenda');
  t('Pages Agenda');
  $export['agenda'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_agenda';
  $context->description = 'Blocks communs aux pages agenda';
  $context->tag = 'Pages Agenda';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'agenda' => 'agenda',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages agenda');
  t('Pages Agenda');
  $export['common_agenda'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_analyse';
  $context->description = 'Blocks communs aux pages analyse';
  $context->tag = 'Pages Analyse';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'analyse' => 'analyse',
      ),
      'options' => array(
        'node_form' => '1',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages analyse');
  t('Pages Analyse');
  $export['common_analyse'] = $context;

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
        'menu-menu-menu-haut' => array(
          'module' => 'menu',
          'delta' => 'menu-menu-haut',
          'region' => 'navigation',
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
