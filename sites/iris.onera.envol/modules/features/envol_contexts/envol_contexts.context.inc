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
        'nodeblock-1460' => array(
          'module' => 'nodeblock',
          'delta' => '1460',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--ej---pour-battlelab' => array(
          'module' => 'bean',
          'delta' => '-ej---pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean--cp---pour-battlelab' => array(
          'module' => 'bean',
          'delta' => '-cp---pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-7',
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
  $context->name = 'chroniques';
  $context->description = 'Gestion des blocks de la home Chroniques';
  $context->tag = 'Pages Chroniques';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'chroniques' => 'chroniques',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_chroniques_home' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_chroniques_home',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean---esp----test' => array(
          'module' => 'bean',
          'delta' => '--esp----test',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gestion des blocks de la home Chroniques');
  t('Pages Chroniques');
  $export['chroniques'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_agenda';
  $context->description = 'Blocks communs aux pages Agenda';
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
  t('Blocks communs aux pages Agenda');
  t('Pages Agenda');
  $export['common_agenda'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_analyse';
  $context->description = 'Blocks communs aux pages Analyse';
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
  t('Blocks communs aux pages Analyse');
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
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-9',
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
  $context->name = 'common_chroniques';
  $context->description = 'Blocks communs aux pages Chroniques';
  $context->tag = 'Pages Chroniques';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'chroniques' => 'chroniques',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_chroniques' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_chroniques',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages Chroniques');
  t('Pages Chroniques');
  $export['common_chroniques'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_ensemble';
  $context->description = 'Blocks communs aux pages Ensemble';
  $context->tag = 'Pages Ensemble';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ensemble' => 'ensemble',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_ensemble' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_ensemble',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages Ensemble');
  t('Pages Ensemble');
  $export['common_ensemble'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'common_focus';
  $context->description = 'Blocks communs aux pages Focus';
  $context->tag = 'Pages Focus';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'focus' => 'focus',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_focus' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_focus',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages Focus');
  t('Pages Focus');
  $export['common_focus'] = $context;

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
  $context->name = 'common_unejourneeavec';
  $context->description = 'Blocks communs aux pages Une journée avec';
  $context->tag = 'Pages Une journée avec';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'une_journee_avec' => 'une_journee_avec',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_unejourneeavec' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_unejourneeavec',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages Une journée avec');
  t('Pages Une journée avec');
  $export['common_unejourneeavec'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ensemble';
  $context->description = 'Gestion des blocks de la home Ensemble';
  $context->tag = 'Pages Ensemble';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'ensemble' => 'ensemble',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_ensemble_home' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_ensemble_home',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean--octobre-2014---ensemble-le-cont' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---ensemble-le-cont',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--octobre-2014---ensemble-les-enj' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---ensemble-les-enj',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gestion des blocks de la home Ensemble');
  t('Pages Ensemble');
  $export['ensemble'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'focus';
  $context->description = 'Gestion des blocks de la home Focus';
  $context->tag = 'Pages Focus';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'focus' => 'focus',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-rubriques-other_focus_home' => array(
          'module' => 'views',
          'delta' => 'rubriques-other_focus_home',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean--octobre-2014---focus-le-context' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---focus-le-context',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--octobre-2014---focus-les-enjeux' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---focus-les-enjeux',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gestion des blocks de la home Focus');
  t('Pages Focus');
  $export['focus'] = $context;

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
  $context->description = 'Blocks communs aux pages Invité';
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
        'bean--linvite-octobre-2014-pour-en-sa' => array(
          'module' => 'bean',
          'delta' => '-linvite-octobre-2014-pour-en-sa',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages Invité');
  t('Pages Invité');
  $export['invite'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_analyse-teledetection';
  $context->description = 'Octobre 2014 - Analyse - Télédétection';
  $context->tag = 'Pages Analyse';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'analyse/les-nouveaux-horizons-de-la-teledetection' => 'analyse/les-nouveaux-horizons-de-la-teledetection',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nodeblock-1460' => array(
          'module' => 'nodeblock',
          'delta' => '1460',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean-le-contexte' => array(
          'module' => 'bean',
          'delta' => 'le-contexte',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--ej---pour-battlelab' => array(
          'module' => 'bean',
          'delta' => '-ej---pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'bean--cp---pour-battlelab' => array(
          'module' => 'bean',
          'delta' => '-cp---pour-battlelab',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - Analyse - Télédétection');
  t('Pages Analyse');
  $export['octobre_2014_analyse-teledetection'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_chroniques_rias';
  $context->description = 'Octobre 2014 - Chroniques - RIAS';
  $context->tag = 'Pages Chroniques';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'chroniques/1988-le-radar-rias-est-operationnel' => 'chroniques/1988-le-radar-rias-est-operationnel',
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
        'bean--chroniques-octobre-2014-cette-a' => array(
          'module' => 'bean',
          'delta' => '-chroniques-octobre-2014-cette-a',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - Chroniques - RIAS');
  t('Pages Chroniques');
  $export['octobre_2014_chroniques_rias'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_ensemble_contrats_conquete';
  $context->description = 'Octobre 2014 - Ensemble - conquête nouveaux clients';
  $context->tag = 'Pages Ensemble';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'ensemble/a-la-conquete-de-nouveaux-clients' => 'ensemble/a-la-conquete-de-nouveaux-clients',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean--octobre-2014---ensemble-le-cont' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---ensemble-le-cont',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean--octobre-2014---ensemble-les-enj' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---ensemble-les-enj',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - Ensemble - conquête nouveaux clients');
  t('Pages Ensemble');
  $export['octobre_2014_ensemble_contrats_conquete'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_focus_investir';
  $context->description = 'Octobre 2014 - Focus - Investir';
  $context->tag = 'Pages Focus';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'focus/investir-pour-preparer-avenir' => 'focus/investir-pour-preparer-avenir',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean--octobre-2014---focus-le-context' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---focus-le-context',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean--octobre-2014---focus-les-enjeux' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---focus-les-enjeux',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - Focus - Investir');
  t('Pages Focus');
  $export['octobre_2014_focus_investir'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_invite_bruno-sainjon';
  $context->description = 'Octobre 2014 - L\'invité - Bruno Sainjon';
  $context->tag = 'Pages Invité';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'invite/edito-du-president-octobre-2014' => 'invite/edito-du-president-octobre-2014',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean--linvite-octobre-2014-pour-en-sa' => array(
          'module' => 'bean',
          'delta' => '-linvite-octobre-2014-pour-en-sa',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - L\'invité - Bruno Sainjon');
  t('Pages Invité');
  $export['octobre_2014_invite_bruno-sainjon'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_lefil_mem';
  $context->description = 'Octobre 2014 - Le Fil - MEM';
  $context->tag = 'Pages le fil';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'lefil/MEM-proteger-les-satellites-des-orages-magnetiques' => 'lefil/MEM-proteger-les-satellites-des-orages-magnetiques',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean--octobre-2014---le-fil-mem---pro' => array(
          'module' => 'bean',
          'delta' => '-octobre-2014---le-fil-mem---pro',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - Le Fil - MEM');
  t('Pages le fil');
  $export['octobre_2014_lefil_mem'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'octobre_2014_une_journee_avec_nightglow';
  $context->description = 'Octobre 2014 - Une journée avec - Nightglow';
  $context->tag = 'Pages Une journée avec';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'une-journee-avec/nightglow' => 'une-journee-avec/nightglow',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean--une-journee-avec-octobre-2014-l' => array(
          'module' => 'bean',
          'delta' => '-une-journee-avec-octobre-2014-l',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean--une-journee-avec-octobre-2014-0' => array(
          'module' => 'bean',
          'delta' => '-une-journee-avec-octobre-2014-0',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Octobre 2014 - Une journée avec - Nightglow');
  t('Pages Une journée avec');
  $export['octobre_2014_une_journee_avec_nightglow'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'une_journee_avec';
  $context->description = 'Blocks communs aux pages Une journée avec';
  $context->tag = 'Pages Une journée avec';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'une-journee-avec' => 'une-journee-avec',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f9ea6b484a15f591cdfdf0b114940810' => array(
          'module' => 'views',
          'delta' => 'f9ea6b484a15f591cdfdf0b114940810',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'bean--une-journee-avec-octobre-2014-l' => array(
          'module' => 'bean',
          'delta' => '-une-journee-avec-octobre-2014-l',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--une-journee-avec-octobre-2014-0' => array(
          'module' => 'bean',
          'delta' => '-une-journee-avec-octobre-2014-0',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks communs aux pages Une journée avec');
  t('Pages Une journée avec');
  $export['une_journee_avec'] = $context;

  return $export;
}
