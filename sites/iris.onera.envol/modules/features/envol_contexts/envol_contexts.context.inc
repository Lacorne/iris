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
        'views-rubriques-other_analyse_home' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_analyse_home',
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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nodeblock-17' => array(
          'module' => 'nodeblock',
          'delta' => '17',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
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
        'envol_blocks-header_links' => array(
          'module' => 'envol_blocks',
          'delta' => 'header_links',
          'region' => 'header',
          'weight' => '-10',
        ),
        'menu-menu-menu-haut' => array(
          'module' => 'menu',
          'delta' => 'menu-menu-haut',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'envol_blocks-footer_links' => array(
          'module' => 'envol_blocks',
          'delta' => 'footer_links',
          'region' => 'footer',
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_invite';
  $context->description = 'Gestion des blocks de la home Invité';
  $context->tag = 'Pages Invité';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'invite' => 'invite',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_invite' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_invite',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gestion des blocks de la home Invité');
  t('Pages Invité');
  $export['common_invite'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_lefil';
  $context->description = '';
  $context->tag = 'Pages le fil';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'story' => 'story',
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
  t('Pages le fil');
  $export['common_lefil'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Blocks de la page d\'accueil d\'Envol';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-d00fbfc7faa9315747951b002c2e55be' => array(
          'module' => 'views',
          'delta' => 'd00fbfc7faa9315747951b002c2e55be',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'views-listescontenus-lefil_home' => array(
          'module' => 'views',
          'delta' => 'listescontenus-lefil_home',
          'region' => 'second_content',
          'weight' => '-10',
        ),
        'views-listescontenus-agenda_home' => array(
          'module' => 'views',
          'delta' => 'listescontenus-agenda_home',
          'region' => 'second_content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks de la page d\'accueil d\'Envol');
  t('Home');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'invite';
  $context->description = 'Blocks communs aux pages invité';
  $context->tag = 'Pages Invité';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'invite' => 'invite',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_invite_home' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_invite_home',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'nodeblock-17' => array(
          'module' => 'nodeblock',
          'delta' => '17',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages invité');
  t('Pages Invité');
  $export['invite'] = $context;

  return $export;
}
