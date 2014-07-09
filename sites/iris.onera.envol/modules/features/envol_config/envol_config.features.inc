<?php
/**
 * @file
 * envol_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function envol_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function envol_config_node_info() {
  $items = array(
    'agenda' => array(
      'name' => t('Agenda'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Agenda'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'analyse' => array(
      'name' => t('Analyse'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Analyse'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Utilisez les <em>articles</em> pour des contenus possédant une temporalité tels que des actualités, des communiqués de presse ou des billets de blog.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'focus' => array(
      'name' => t('Focus'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Focus'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'invite' => array(
      'name' => t('Invité'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Invité'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page de base'),
      'base' => 'node_content',
      'description' => t('Utilisez les <em>pages de base</em> pour votre contenu statique, tel que la page \'Qui sommes-nous\'.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'story' => array(
      'name' => t('Actualité'),
      'base' => 'node_content',
      'description' => t('Pour poster de l\'actualité sur la page d\'accueil d\'envol.onera'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
