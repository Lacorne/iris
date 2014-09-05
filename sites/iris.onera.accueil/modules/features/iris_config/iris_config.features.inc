<?php
/**
 * @file
 * iris_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function iris_config_ctools_plugin_api($module = NULL, $api = NULL) {
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
function iris_config_node_info() {
  $items = array(
    'page2' => array(
      'name' => t('page2'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'story' => array(
      'name' => t('Actualité'),
      'base' => 'node_content',
      'description' => t('Pour poster de l\'actualité sur la page d\'accueil d\'iris.onera'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
