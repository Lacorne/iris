<?php
/**
 * @file
 * Contains functions to alter Drupal's markup for the Envol theme.
 *
 * IMPORTANT WARNING: DO NOT MODIFY THIS FILE.
 *
 */

/**
 * Return a themed breadcrumb trail.
 *
 * @param $variables
 *   - title: An optional string to be used as a navigational heading to give
 *     context for breadcrumb links to screen-reader users.
 *   - title_attributes_array: Array of HTML attributes for the title. It is
 *     flattened into a string within the theme function.
 *   - breadcrumb: An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function envol_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';

  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('envol_breadcrumb');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {

    // Optionally get rid of the homepage link.
    $show_breadcrumb_home = theme_get_setting('envol_breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }

    // Return the breadcrumb with separators.
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = filter_xss_admin(theme_get_setting('envol_breadcrumb_separator'));
      $trailing_separator = $title = '';
      if (theme_get_setting('envol_breadcrumb_title')) {
        $item = menu_get_item();
        if (!empty($item['tab_parent'])) {
          // If we are on a non-default tab, use the tab's title.
          $breadcrumb[] = check_plain($item['title']);
        }
        else {
          $breadcrumb[] = drupal_get_title();
        }
      }
      elseif (theme_get_setting('envol_breadcrumb_trailing')) {
        $trailing_separator = $breadcrumb_separator;
      }

      // Provide a navigational heading to give context for breadcrumb links to
      // screen-reader users.
      if (empty($variables['title'])) {
        $variables['title'] = t('You are here');
      }
      // Unless overridden by a preprocess function, make the heading invisible.
      if (!isset($variables['title_attributes_array']['class'])) {
        $variables['title_attributes_array']['class'][] = 'element-invisible';
      }

      // Build the breadcrumb trail.
      $output = '<nav class="breadcrumb" role="navigation">';
      $output .= '<h2' . drupal_attributes($variables['title_attributes_array']) . '>' . $variables['title'] . '</h2>';
      $output .= '<ol><li>' . implode($breadcrumb_separator . '</li><li>', $breadcrumb) . $trailing_separator . '</li></ol>';
      $output .= '</nav>';
    }
  }

  return $output;
}

/**
 * Override or insert variables into the html template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered. This is usually "html", but can
 *   also be "maintenance_page" since envol_preprocess_maintenance_page() calls
 *   this function to have consistent variables.
 */
function envol_preprocess_html(&$variables, $hook) {
  // Add variables and paths needed for HTML5 and responsive support.
  $variables['base_path'] = base_path();
  $variables['path_to_envol'] = drupal_get_path('theme', 'envol');
  // Get settings for HTML5 and responsive support. array_filter() removes
  // items from the array that have been disabled.
  $html5_respond_meta = array_filter((array) theme_get_setting('envol_html5_respond_meta'));
  $variables['add_respond_js']          = in_array('respond', $html5_respond_meta);
  $variables['add_html5_shim']          = in_array('html5', $html5_respond_meta);
  $variables['default_mobile_metatags'] = in_array('meta', $html5_respond_meta);

  // Attributes for html element.
  $variables['html_attributes_array'] = array(
    'lang' => $variables['language']->language,
    'dir' => $variables['language']->dir,
  );

  // Send X-UA-Compatible HTTP header to force IE to use the most recent
  // rendering engine or use Chrome's frame rendering engine if available.
  // This also prevents the IE compatibility mode button to appear when using
  // conditional classes on the html tag.
  if (is_null(drupal_get_http_header('X-UA-Compatible'))) {
    drupal_add_http_header('X-UA-Compatible', 'IE=edge,chrome=1');
  }

  $variables['skip_link_anchor'] = check_plain(theme_get_setting('envol_skip_link_anchor'));
  $variables['skip_link_text']   = check_plain(theme_get_setting('envol_skip_link_text'));

  // Return early, so the maintenance page does not call any of the code below.
  if ($hook != 'html') {
    return;
  }

  // Serialize RDF Namespaces into an RDFa 1.1 prefix attribute.
  if ($variables['rdf_namespaces']) {
    $prefixes = array();
    foreach (explode("\n  ", ltrim($variables['rdf_namespaces'])) as $namespace) {
      // Remove xlmns: and ending quote and fix prefix formatting.
      $prefixes[] = str_replace('="', ': ', substr($namespace, 6, -1));
    }
    $variables['rdf_namespaces'] = ' prefix="' . implode(' ', $prefixes) . '"';
  }

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  if (!$variables['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each website section.
    list($section, ) = explode('/', $path, 2);
    $arg = explode('/', $_GET['q']);
    if ($arg[0] == 'node' && isset($arg[1])) {
      if ($arg[1] == 'add') {
        $section = 'node-add';
      }
      elseif (isset($arg[2]) && is_numeric($arg[1]) && ($arg[2] == 'edit' || $arg[2] == 'delete')) {
        $section = 'node-' . $arg[2];
      }
    }
    $variables['classes_array'][] = drupal_html_class('section-' . $section);
  }
  // Store the menu item since it has some useful information.
  $variables['menu_item'] = menu_get_item();
  if ($variables['menu_item']) {
    switch ($variables['menu_item']['page_callback']) {
      case 'views_page':
        // Is this a Views page?
        $variables['classes_array'][] = 'page-views';
        // Check if analyse, we set a special head title
        $head_title = $variables['head_title'];
        if ($variables['menu_item']['path'] == 'analyse') $variables['head_title'] = ucfirst($variables['menu_item']['path']) . ' | ' . $head_title;
        break;
      case 'page_manager_blog':
      case 'page_manager_blog_user':
      case 'page_manager_contact_site':
      case 'page_manager_contact_user':
      case 'page_manager_node_add':
      case 'page_manager_node_edit':
      case 'page_manager_node_view_page':
      case 'page_manager_page_execute':
      case 'page_manager_poll':
      case 'page_manager_search_page':
      case 'page_manager_term_view_page':
      case 'page_manager_user_edit_page':
      case 'page_manager_user_view_page':
        // Is this a Panels page?
        $variables['classes_array'][] = 'page-panels';
        break;
    }
  }

  //Special for multisie views
  if ( isset($_GET['ajax']) && $_GET['ajax'] == 1 ) {
        // Add suggestions for page
        $variables['theme_hook_suggestions'][] = 'html__ajax';
  }

}

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function envol_process_html(&$variables, $hook) {
  // Flatten out html_attributes.
  $variables['html_attributes'] = drupal_attributes($variables['html_attributes_array']);
}

/**
 * Override or insert variables in the html_tag theme function.
 */
function envol_process_html_tag(&$variables) {
  $tag = &$variables['element'];

  if ($tag['#tag'] == 'style' || $tag['#tag'] == 'script') {
    // Remove redundant type attribute and CDATA comments.
    unset($tag['#attributes']['type'], $tag['#value_prefix'], $tag['#value_suffix']);

    // Remove media="all" but leave others unaffected.
    if (isset($tag['#attributes']['media']) && $tag['#attributes']['media'] === 'all') {
      unset($tag['#attributes']['media']);
    }
  }
}

/**
 * Implement hook_html_head_alter().
 */
function envol_html_head_alter(&$head) {
  // Simplify the meta tag for character encoding.
  if (isset($head['system_meta_content_type']['#attributes']['content'])) {
    $head['system_meta_content_type']['#attributes'] = array('charset' => str_replace('text/html; charset=', '', $head['system_meta_content_type']['#attributes']['content']));
  }
}

/**
 * Implement hook_preprocess().
 */
function envol_preprocess(&$variables, $hook) {
  global $base_url;
  global $theme;
  $path_to_theme = drupal_get_path('theme', $theme);
  $variables['base_url'] = $base_url;
  $variables['current_theme'] = $theme;
  $variables['path_to_theme'] = $path_to_theme;
}

/**
 * Override or insert variables into the page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function envol_preprocess_page(&$variables, $hook) {
  global $base_url;
  
  // Find the title of the menu used by the secondary links.
  $secondary_links = variable_get('menu_secondary_links_source', 'user-menu');
  if ($secondary_links) {
    $menus = function_exists('menu_get_menus') ? menu_get_menus() : menu_list_system_menus();
    $variables['secondary_menu_heading'] = $menus[$secondary_links];
  }
  else {
    $variables['secondary_menu_heading'] = '';
  }

  // Special for multisie views
  if ( isset($_GET['ajax']) && $_GET['ajax'] == 1 ) {
    // Add suggestions for page
    $variables['theme_hook_suggestions'][] = 'page__ajax';
  }

  // Create suggestion with node tpe
  if (isset($variables['node'])) {
    $node = $variables['node'];
    // Add suggestions for page
    $variables['theme_hook_suggestions'][] = 'page__' . $node->type;
  }

  // Set a variable to return to Iris
  ($base_url == 'http://iris.onera') ? $back_to_iris = $base_url : $back_to_iris = 'http://iris.local';
  $variables['page']['back_to_iris'] = $back_to_iris;

}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
function envol_preprocess_maintenance_page(&$variables, $hook) {
  envol_preprocess_html($variables, $hook);
  // There's nothing maintenance-related in envol_preprocess_page(). Yet.
  //envol_preprocess_page($variables, $hook);
}

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
function envol_process_maintenance_page(&$variables, $hook) {
  envol_process_html($variables, $hook);
  // Ensure default regions get a variable. Theme authors often forget to remove
  // a deleted region's variable in maintenance-page.tpl.
  foreach (array('header', 'navigation', 'highlighted', 'help', 'content', 'sidebar_first', 'sidebar_second', 'footer', 'bottom') as $region) {
    if (!isset($variables[$region])) {
      $variables[$region] = '';
    }
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */

function _nbJours($debut, $fin, $limit) {
  $nbSecondes= 60*60*24;
  $debut_ts = $debut;
  $fin_ts = $fin;
  $diff = $fin_ts - $debut_ts;
  if (round($diff / $nbSecondes) + 1 <= $limit) {
    return true;
  } else { return false; }
}

function envol_preprocess_node(&$variables, $hook) {

  // Add diff between created date and now
  $variables['diffcreatednow'] = _nbJours($variables['created'], strtotime(date('Y-m-d')), 7);

  // Add $title_type variable
  $listoftypes = array('invite', 'analyse', 'une_journee_avec', 'focus', 'chroniques', 'ensemble');

  if (in_array($variables['type'], $listoftypes)) {
    if ($variables['view_mode'] == 'teaser_short' || $variables['view_mode'] == 'teaser_big_img' || $variables['view_mode'] == 'teaser_small_img' || $variables['is_front']) {
      $variables['content']['title_type'] = str_replace('_', ' ', $variables['type']);
      $variables['content']['set_title'] = true;
    }
  }
  // Add $unpublished variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;
  // Add pubdate to submitted variable.
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['node']->created, 'custom', 'c') . '">' . $variables['date'] . '</time>';
  if ($variables['display_submitted']) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['pubdate']));
  }

  // Add a class for the view mode.
  if (!$variables['teaser']) {
    $variables['classes_array'][] = 'view-mode-' . $variables['view_mode'];
  }

  // Add a class to show node is authored by current user.
  if ($variables['uid'] && $variables['uid'] == $GLOBALS['user']->uid) {
    $variables['classes_array'][] = 'node-by-viewer';
  }

  $variables['title_attributes_array']['class'][] = 'node__title';
  $variables['title_attributes_array']['class'][] = 'node-title';

  // Add suggestions for node
  $variables['theme_hook_suggestions'][] = 'node' . '__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node' . '__' . $variables['view_mode'] . '__' . $variables['type'];

  // Add node_url for template node
  $node_url_noenvol = explode('/envol', $variables['node_url']);
  (count($node_url_noenvol) > 1) ? $variables['node_url'] = $node_url_noenvol[1] : $variables['node_url'] = $node_url_noenvol[0];

  // Check if analyse or focus, so we create a array of parole experts in content
  if(in_array($variables['type'], array('analyse', 'focus'))){

    if (isset($variables['content']['field_paroles_experts'])) {

      $paroles_experts = $variables['content']['field_paroles_experts'];
      $nb_pe = count($paroles_experts['#items']);

      foreach ($paroles_experts['#items'] as $key => $value) {

        $item = $paroles_experts['#items'][$key]['value'];
        $variables['content']['experts'][$key]['name'] = $paroles_experts[$key]['entity']['field_collection_item'][$item]['field_nom_prenom'][0]['#markup'];
        $variables['content']['experts'][$key]['function'] = $paroles_experts[$key]['entity']['field_collection_item'][$item]['field_fonction_titre'][0]['#markup'];
        $variables['content']['experts'][$key]['localisation'] = $paroles_experts[$key]['entity']['field_collection_item'][$item]['field_localisation'][0]['#markup'];
        $variables['content']['experts'][$key]['visuel'] = $paroles_experts[$key]['entity']['field_collection_item'][$item]['field_visuel'][0]['#item']['uri'];

      }

    }

  }

}

/**
 * Override or insert variables into the search results.
 *
 */
/*
function envol_preprocess_search_results(&$variables) {
}
*/
/**
 * Override or insert variables into the search result.
 *
 */
function envol_preprocess_search_result(&$variables) {

  $display = array(
    'label' => 'hidden',
    'type' => 'image',
    'settings' => array(
      'size' => '232',
      'image_style' => '232',
    ),
  );

  if (isset($variables['result']['node']->field_image_actu) && !empty($variables['result']['node']->field_image_actu)) {
    $variables['content']['vignette_' . $display['settings']['size']] = field_view_field('node', $variables['result']['node'], 'field_image_actu', $display);
  }
  if (isset($variables['result']['node']->field_visuel) && !empty($variables['result']['node']->field_visuel)) {
    $variables['content']['vignette_' . $display['settings']['size']] = field_view_field('node', $variables['result']['node'], 'field_visuel', $display);
  }
  if (isset($variables['result']['node']->field_image) && !empty($variables['result']['node']->field_image)) {
    $variables['content']['vignette_' . $display['settings']['size']] = field_view_field('node', $variables['result']['node'], 'field_image', $display);
  }
  if (isset($variables['result']['node']->field_thematique) && !empty($variables['result']['node']->field_thematique)) {
    $variables['content']['thematique'] = $variables['result']['node']->field_thematique['und'][0]['taxonomy_term']->name;
  }

}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function envol_preprocess_comment(&$variables, $hook) {
  // If comment subjects are disabled, don't display them.
  if (variable_get('comment_subject_field_' . $variables['node']->type, 1) == 0) {
    $variables['title'] = '';
  }

  // Add pubdate to submitted variable.
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '">' . $variables['created'] . '</time>';
  $variables['submitted'] = t('!username replied on !datetime', array('!username' => $variables['author'], '!datetime' => $variables['pubdate']));

  // Zebra striping.
  if ($variables['id'] == 1) {
    $variables['classes_array'][] = 'first';
  }
  if ($variables['id'] == $variables['node']->comment_count) {
    $variables['classes_array'][] = 'last';
  }
  $variables['classes_array'][] = $variables['zebra'];

  $variables['title_attributes_array']['class'][] = 'comment__title';
  $variables['title_attributes_array']['class'][] = 'comment-title';
}

/**
 * Preprocess variables for region.tpl.php
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
function envol_preprocess_region(&$variables, $hook) {
  // Sidebar regions get some extra classes and a common template suggestion.
  if (strpos($variables['region'], 'sidebar_') === 0) {
    $variables['classes_array'][] = 'column';
    $variables['classes_array'][] = 'sidebar';
    // Allow a region-specific template to override envol's region--sidebar.
    array_unshift($variables['theme_hook_suggestions'], 'region__sidebar');
  }
  // Use a template with no wrapper for the content region.
  elseif ($variables['region'] == 'content') {
    // Allow a region-specific template to override envol's region--no-wrapper.
    array_unshift($variables['theme_hook_suggestions'], 'region__no_wrapper');
  }
  // Add a SMACSS-style class for header region.
  elseif ($variables['region'] == 'header') {
    array_unshift($variables['classes_array'], 'header__region');
  }
  // Add a SMACSS-style class for footer region.
  elseif ($variables['region'] == 'footer') {
    array_unshift($variables['classes_array'], 'footer__region');
  }
}

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function envol_preprocess_block(&$variables, $hook) {
  // Use a template with no wrapper for the page's main content.
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'][] = 'block__no_wrapper';
  }

  // Classes describing the position of the block within the region.
  if ($variables['block_id'] == 1) {
    $variables['classes_array'][] = 'first';
  }
  // The last_in_region property is set in envol_page_alter().
  if (isset($variables['block']->last_in_region)) {
    $variables['classes_array'][] = 'last';
  }
  $variables['classes_array'][] = $variables['block_zebra'];

  $variables['title_attributes_array']['class'][] = 'block__title';
  $variables['title_attributes_array']['class'][] = 'block-title';
  // Add Aria Roles via attributes.
  switch ($variables['block']->module) {
    case 'system':
      switch ($variables['block']->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;
        case 'help':
        case 'powered-by':
          $variables['attributes_array']['role'] = 'complementary';
          break;
        default:
          // Any other "system" block is a menu block.
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;
    case 'menu':
    case 'menu_block':
    case 'blog':
    case 'book':
    case 'comment':
    case 'forum':
    case 'shortcut':
    case 'statistics':
      $variables['attributes_array']['role'] = 'navigation';
      break;
    case 'search':
      $variables['attributes_array']['role'] = 'search';
      break;
    case 'help':
    case 'aggregator':
    case 'locale':
    case 'poll':
    case 'profile':
      $variables['attributes_array']['role'] = 'complementary';
      break;
    case 'node':
      switch ($variables['block']->delta) {
        case 'syndicate':
          $variables['attributes_array']['role'] = 'complementary';
          break;
        case 'recent':
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;
    case 'user':
      switch ($variables['block']->delta) {
        case 'login':
          $variables['attributes_array']['role'] = 'form';
          break;
        case 'new':
        case 'online':
          $variables['attributes_array']['role'] = 'complementary';
          break;
      }
      break;
    case 'block':
      if ($variables['block']->region == 'sidebar_first') {
        $variables['attributes_array']['role'] = 'navigation';
        if ( $variables['block']->subject != '') $variables['classes_array'][] = 'block-' . strtolower(str_replace(array(' ', '/', '\''), '-', $variables['block']->subject));
      }
      break;
    case 'views':
      if ($variables['block']->region == 'sidebar_second') {
        $class_rub_to_check = 'rubriques-other';
        $check_view_type_other_article = strpos($variables['block']->delta, $class_rub_to_check);
        if ($check_view_type_other_article !== false) {
          $variables['classes_array'][] = 'block-' . $class_rub_to_check;
        }
      }
      break;
    case 'nodeblock':
      if (isset($variables['elements'])) {
        // Add classes bundle and view mode
        $variables['classes_array'][] = 'block-type-' . '-' . $variables['elements']['#bundle'];
        $variables['classes_array'][] = 'block-view-mode-' . '-' . $variables['elements']['#view_mode'];
        // Add bundle hook theme suggestion
        $variables['theme_hook_suggestions'][] = 'block__' . $variables['elements']['#bundle'];
        switch ($variables['elements']['#bundle']) {
          case 'regards_exterieurs':
            $variables['block']->subject = str_replace('_', ' ', $variables['elements']['#bundle']);
            break;
          case 'temoignage':
            $variables['block']->subject = str_replace('_', ' ', $variables['elements']['#bundle']);
            break;
        }
      }
    case 'bean':
      if (isset($variables['elements']['bean'])) {
        $delta = $variables['block']->delta;
        // Add classes bundle
        $variables['classes_array'][] = 'block-type-' . '-' . $variables['elements']['bean'][$delta]['#bundle'];
        // Add bundle hook theme suggestion
        $variables['theme_hook_suggestions'][] = 'block__' . $variables['elements']['bean'][$delta]['#bundle'];
      }
      break;
  }
}

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function envol_process_block(&$variables, $hook) {
  // Drupal 7 should use a $title variable instead of $block->subject.
  $variables['title'] = isset($variables['block']->subject) ? $variables['block']->subject : '';
}

/**
 * Implements hook_page_alter().
 *
 * Look for the last block in the region. This is impossible to determine from
 * within a preprocess_block function.
 *
 * @param $page
 *   Nested array of renderable elements that make up the page.
 */
function envol_page_alter(&$page) {
  // Look in each visible region for blocks.
  foreach (system_region_list($GLOBALS['theme'], REGIONS_VISIBLE) as $region => $name) {
    if (!empty($page[$region])) {
      // Find the last block in the region.
      $blocks = array_reverse(element_children($page[$region]));
      while ($blocks && !isset($page[$region][$blocks[0]]['#block'])) {
        array_shift($blocks);
      }
      if ($blocks) {
        $page[$region][$blocks[0]]['#block']->last_in_region = TRUE;
      }
    }
  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 *
 * Prevent user-facing field styling from screwing up node edit forms by
 * renaming the classes on the node edit form's field wrappers.
 */
function envol_form_node_form_alter(&$form, &$form_state, $form_id) {
  // Remove if #1245218 is backported to D7 core.
  foreach (array_keys($form) as $item) {
    if (strpos($item, 'field_') === 0) {
      if (!empty($form[$item]['#attributes']['class'])) {
        foreach ($form[$item]['#attributes']['class'] as &$class) {
          // Core bug: the field-type-text-with-summary class is used as a JS hook.
          if ($class != 'field-type-text-with-summary' && strpos($class, 'field-type-') === 0 || strpos($class, 'field-name-') === 0) {
            // Make the class different from that used in theme_field().
            $class = 'form-' . $class;
          }
        }
      }
    }
  }
}

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function envol_menu_local_tasks(&$variables) {
  $output = '';

  // Add theme hook suggestions for tab type.
  foreach (array('primary', 'secondary') as $type) {
    if (!empty($variables[$type])) {
      foreach (array_keys($variables[$type]) as $key) {
        if (isset($variables[$type][$key]['#theme']) && ($variables[$type][$key]['#theme'] == 'menu_local_task' || is_array($variables[$type][$key]['#theme']) && in_array('menu_local_task', $variables[$type][$key]['#theme']))) {
          $variables[$type][$key]['#theme'] = array('menu_local_task__' . $type, 'menu_local_task');
        }
      }
    }
  }

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs-primary tabs primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs-secondary tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Returns HTML for a single local task link.
 *
 * @ingroup themeable
 */
function envol_menu_local_task($variables) {
  $type = $class = FALSE;

  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  // Check for tab type set in envol_menu_local_tasks().
  if (is_array($variables['element']['#theme'])) {
    $type = in_array('menu_local_task__secondary', $variables['element']['#theme']) ? 'tabs-secondary' : 'tabs-primary';
  }

  // Add SMACSS-style class names.
  if ($type) {
    $link['localized_options']['attributes']['class'][] = $type . '__tab-link';
    $class = $type . '__tab';
  }

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = ' <span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));

    if (!$type) {
      $class = 'active';
    }
    else {
      $link['localized_options']['attributes']['class'][] = 'is-active';
      $class .= ' is-active';
    }
  }

  return '<li' . ($class ? ' class="' . $class . '"' : '') . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/**
 * Implements hook_preprocess_menu_link().
 */
function envol_preprocess_menu_link(&$variables, $hook) {
  foreach ($variables['element']['#attributes']['class'] as $key => $class) {
    switch ($class) {
      // Menu module classes.
      case 'expanded':
      case 'collapsed':
      case 'leaf':
      case 'active':
      // Menu block module classes.
      case 'active-trail':
        array_unshift($variables['element']['#attributes']['class'], 'is-' . $class);
        break;
      case 'has-children':
        array_unshift($variables['element']['#attributes']['class'], 'is-parent');
        break;
    }
  }
  array_unshift($variables['element']['#attributes']['class'], 'menu__item');
  if (empty($variables['element']['#localized_options']['attributes']['class'])) {
    $variables['element']['#localized_options']['attributes']['class'] = array();
  }
  else {
    foreach ($variables['element']['#localized_options']['attributes']['class'] as $key => $class) {
      switch ($class) {
        case 'active':
        case 'active-trail':
          array_unshift($variables['element']['#localized_options']['attributes']['class'], 'is-' . $class);
          break;
      }
    }
  }
  array_unshift($variables['element']['#localized_options']['attributes']['class'], 'menu__link');
}

/**
 * Returns HTML for status and/or error messages, grouped by type.
 */
function envol_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages--$type messages $type\">\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul class=\"messages__list\">\n";
      foreach ($messages as $message) {
        $output .= '  <li class=\"messages__item\">' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Returns HTML for a marker for new or updated content.
 */
function envol_mark($variables) {
  $type = $variables['type'];

  if ($type == MARK_NEW) {
    return ' <mark class="new">' . t('new') . '</mark>';
  }
  elseif ($type == MARK_UPDATED) {
    return ' <mark class="updated">' . t('updated') . '</mark>';
  }
}

/**
 * Alters the default Panels render callback so it removes the panel separator.
 */
function envol_panels_default_style_render_region($variables) {
  return implode('', $variables['panes']);
}

/**
 * Implements hook_url_outbound_alter().
 */
function envol_url_outbound_alter(&$path, &$options, $original_path) {
  // Special for print module... alter url printemail and change to mailto
  $findme   = 'printmail';
  $pos = strpos($path, $findme);
  if ($pos !== false) {
    $nid = explode("/", $original_path);
    $node = node_load($nid[1]);
    $path = 'mailto:intranet@onera.fr?subject=Réagir à l\'article ['. $node->title . ']&body=Réaction à l\'article: http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    $options['external'] = TRUE;
  }
}

/**
 * Implements hook_preprocess_pager().
 */
function envol_preprocess_pager(&$variables, $hook) {
  $variables['tags'][0] = '◄◄';
  $variables['tags'][1] = '◄';
  $variables['tags'][3] = '►';
  $variables['tags'][4] = '►►';
}
