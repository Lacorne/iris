<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"

  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language ?>" lang="<?php print $language ?>">

  <head>

    <title><?php print $head_title ?></title>

    <?php print $head ?>

    <?php print $styles ?>

    <?php print $scripts ?>

    <style type="text/css" media="print">@import "<?php print base_path() . path_to_theme() ?>/print.css";</style>

    <!--[if lt IE 7]>

    <style type="text/css" media="all">@import "<?php print base_path() . path_to_theme() ?>/fix-ie.css";</style>

    <![endif]-->

    <style type="text/css">

<!--

.Style11 {font-family: Arial, Helvetica, sans-serif}

-->

    </style>

  </head>

  <body<?php print phptemplate_body_class($sidebar_left, $sidebar_right); ?>>



<!-- Layout -->

  <div id="header-region" class="clear-block"><?php print $header; ?></div>



    <div id="wrapper">

    <div id="container" class="clear-block">



      <div id="header">

        <div id="logo-floater">

        <?php

          // Prepare header

          $site_fields = array();

          if ($site_name) {

            $site_fields[] = check_plain($site_name);

          }

          if ($site_slogan) {

            $site_fields[] = check_plain($site_slogan);

          }

          $site_title = implode(' ', $site_fields);

          $site_fields[0] = '<span>'. $site_fields[0] .'</span>';

          $site_html = implode(' ', $site_fields);



          if ($logo || $site_title) {

            print '<h1><a href="'. check_url($base_path) .'" title="'. $site_title .'">';

            if ($logo) {

              print '<img src="'. check_url($logo) .'" alt="'. $site_title .'" id="logo" />';

            }

            print $site_html .'</a></h1>';

          }

        ?>

        </div>



        <?php if (isset($primary_links)) : ?>

          <?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>

        <?php endif; ?>

        <?php if (isset($secondary_links)) : ?>

          <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')) ?>

        <?php endif; ?>



      </div> <!-- /header -->



      <?php if ($sidebar_left): ?>

	      <div id="sidebar-left" class="sidebar"><h3 class="dqo-special">SYST&Egrave;ME DE MANAGEMENT DE LA QUALIT&Eacute;</h3>

          <?php if ($search_box): ?><div class="block block-theme"><?php print $search_box ?></div><?php endif; ?>

          <?php print $sidebar_left ?>

        </div>

      <?php endif; ?>



      <div id="center"><div id="squeeze"><div class="right-corner"><div class="left-corner">

          <?php if ($breadcrumb): print $breadcrumb; endif; ?>

          <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>

            <?php if ($specialhome): print '<div id="special-home">'. $specialhome .'</div>'; endif; ?>

          <?php if ($tabs): print '<div id="tabs-wrapper" class="clear-block">'; endif; ?>

          <?php if ($title): print '<h2'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h2>'; endif; ?>

          <?php if ($tabs): print $tabs .'</div>'; endif; ?>



          <?php if (isset($tabs2)): print $tabs2; endif; ?>



          <?php if ($help): print $help; endif; ?>

          <?php if ($messages): print $messages; endif; ?>

          <?php #print $content ?>
          <img src="http://iris.onera/services/DQO/sites/iris.onera.services.DQO/files/docs/organigramme.png" alt="Organigramme" usemap="#Map" title="Organigramme" />
          <map name="Map">
            <area shape="rect" coords="2,1,126,54" href="http://iris.onera/services/AC/" />
            <area shape="rect" coords="222,0,349,55" href="Controleur_d_Etat" />
            <area shape="rect" coords="434,0,586,49" href="DG" />
            <area shape="rect" coords="607,0,732,52" href="Conseil_d_administration" />
            <area shape="rect" coords="749,1,871,58" href="HCS" />
            <area shape="rect" coords="155,103,251,150" href="CST" />
            <area shape="rect" coords="300,75,393,135" href="Centres" />
            <area shape="rect" coords="413,75,497,136" href="CCG" />
            <area shape="rect" coords="469,147,470,148" href="#" />
            <area shape="rect" coords="533,77,619,140" href="COM" />
            <area shape="rect" coords="643,76,726,137" href="DAI" />
            <area shape="rect" coords="757,77,841,138" href="DSSE" />
            <area shape="rect" coords="176,185,312,370" href="DSG" />
            <area shape="rect" coords="335,175,567,462" href="DTG" />
            <area shape="rect" coords="723,188,908,395" href="DCV" />
            <area shape="rect" coords="4,146,134,464" href="Services_administratifs" />
            <area shape="rect" coords="153,345,154,346" href="Services_administratifs" />
            <area shape="rect" coords="670,478,910,514" href="repertoire-documents-organisation" />
            <area shape="rect" coords="9,478,185,512" href="delegation-signature" />
          <area shape="rect" coords="567,177,697,275" href="DGMT" alt="" />
          </map>
          <?php print $feed_icons ?><span class="clear"></span>
          <div id="footer"><?php print $footer_message ?></div>

      </div></div></div></div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->



      <?php if ($sidebar_right): ?>

        <div id="sidebar-right" class="sidebar">

          <?php if (!$sidebar_left && $search_box): ?><div class="block block-theme"><?php print $search_box ?></div><?php endif; ?>

          <?php print $sidebar_right ?>

        </div>

      <?php endif; ?>



    </div> <!-- /container -->

  </div>

<!-- /layout -->

  <?php print $closure ?>

  </body>

</html>

