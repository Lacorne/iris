<?php
/**
 * @file
 * Contains Links display on footer site
 */
?>
<p class="copyright">&copy; Onera</p>
<div class="wrapper-footer-links">
  <p class="mail">Remarques et suggestions : <a href="mailto:intranet@onera.fr">intranet@onera.fr</a></p>
  <ul>
    <li class="icone facebook"><?php print l('<span>Facebook</span>', 'http://www.facebook.fr/thefrenchaerospacelab', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
    <li class="icone twitter"><?php print l('<span>Twitter</span>', 'http://www.twitter.com/@onera_fr', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
    <li class="icone linkedin"><?php print l('<span>linkedIn</span>', 'http://www.linkedin.com/company/onera', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
  </ul>
</div>