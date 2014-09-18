<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <a href="<?php print $content['field_link']['#items'][0]['value'];?>" class="link-insitu">
    <div class="wrapper-center"><?php print $content['field_center']['#items'][0]['value']; ?> : </div>
    <div class="wrapper-titlelink"><?php print $content['body']['#items'][0]['value']; ?></div>
  </a>
</article>
