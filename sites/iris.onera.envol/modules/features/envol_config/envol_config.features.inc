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
 * Implements hook_image_default_styles().
 */
function envol_config_image_default_styles() {
  $styles = array();

  // Exported image style: 232.
  $styles[232] = array(
    'name' => 232,
    'label' => 232,
    'effects' => array(
      2 => array(
        'label' => 'Mise à l’échelle et recadrage',
        'help' => 'La mise à l\'échelle et le recadrage maintiendront les proportions originales de l\'image puis recadreront la dimension la plus large. C\'est très utile pour créer des vignettes carrées sans étirer les images.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 232,
          'height' => 155,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 484.
  $styles[484] = array(
    'name' => 484,
    'label' => 484,
    'effects' => array(
      1 => array(
        'label' => 'Échelle',
        'help' => 'La mise à l\'échelle maintiendra les proportions originales de l\'image. Si une seule dimension est précisée, l\'autre dimension sera calculée automatiquement.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 484,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
