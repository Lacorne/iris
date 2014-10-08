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

  <a href="<?php print $base_url . $node_url; ?>" class="left mr20"><?php print render($content['field_image']); ?></a>
  <div class="wrapper-info-block-node">
    <?php print render($content); ?>
  </div>
  <a href="<?php print $base_url . $node_url; ?>" class="left readmore"><span>►►</span> Lire la suite</a>

</article>
