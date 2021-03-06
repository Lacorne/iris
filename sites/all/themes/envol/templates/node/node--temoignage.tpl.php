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

  <div class="wrapper-image">
    <?php print render($content['field_image']);?>
  </div>

  <div class="wrapper-info">
    <div class="wrapper-print">
      <?php print render($content['print_links']);?>
    </div>
    <?php print render($title_prefix); ?>
      <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php print render($title_suffix); ?>
    <?php print render($content['field_fonction_titre']);?>
    <?php print render($content['field_chapo']);?>
    <?php print render($content['body']);?>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
