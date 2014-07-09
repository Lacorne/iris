<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_paroles_experts']);
    if (isset($content['experts'])) {
      foreach ($content['experts'] as $key => $value) {
        $name_exp = $content['experts'][$key]['name'];
        $function_epx = $content['experts'][$key]['function'];
        $localisation_epx = $content['experts'][$key]['localisation'];
        $visuel_epx = file_create_url($content['experts'][$key]['visuel']);
        $li_elm .= '<li>
                    <span class="visuel-exp"><img src="' . $visuel_epx . '" class="visuel-exp-thumbnail" /></span>
                    <span class="name-exp">' . $name_exp . '</span>
                    <span class="function-exp">' . $function_epx . '</span>
                    <span class="localisation-exp">' . $localisation_epx . '</span>
                   </li>';
      }
    }

  ?>
  <?php print render($content); ?>

  <div class="block-experts">
    <ul>
      <?php print $li_elm; ?>
    </ul>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
