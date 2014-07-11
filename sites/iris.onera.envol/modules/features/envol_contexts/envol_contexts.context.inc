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
