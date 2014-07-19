<div class="fake-img">
  <img src="<?php print '/' . drupal_get_path('theme', 'envol'); ?>/images/demo22/fake-home.jpg" />
  <div class="fake-nav">
    <a href="/envol/home" class="fake-button0"></a>
    <a href="/envol/lefil" class="fake-button1"></a>
    <a href="/envol/invite" class="fake-button2"></a>
    <a href="/envol/analyse" class="fake-button3"></a>
    <a href="/envol/standby" class="fake-button4"></a>
    <a href="/envol/standby" class="fake-button5"></a>
    <a href="/envol/standby" class="fake-button6"></a>
    <a href="/envol/standby" class="fake-button7"></a>
    <a href="/envol/agenda" class="fake-button8"></a>
    <a href="/" class="fake-button9"></a>
  </div>
  <a href="/envol/analyse" class="inpage fake-button10"></a>
  <a href="/envol/invite" class="inpage fake-button11"></a>
  <a href="/envol/lefil" class="inpage fake-button12"></a>
  <a href="/envol/agenda" class="inpage fake-button13"></a>
</div>

<div class="fake-header"></div>
<div class="fake-footer"></div>

<style>
body { position: relative; }
img {
  margin: 0 auto;
  display: block;
  z-index: 100;
  position: relative;
}
.fake-img {
  width: 1200px;
  margin: 0 auto;
  position: relative;
}
.fake-nav {
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  height: 195px;
  z-index: 120;
}
.fake-nav a {
  position: absolute;
  display:block;
  width: 65px;
  height: 20px;
  top: 85px;
}
.fake-button0 {
  left: 105px;
  width: 197px!important;
  height: 89px!important;
  top: 25px!important;
}
.fake-button1 {
  left: 347px;
}
.fake-button2 {
  left: 424px;
}
.fake-button3 {
  left: 513px;
}
.fake-button4 {
  left: 596px;
}
.fake-button5 {
  left: 684px;
}
.fake-button6 {
  left: 784px;
  width: 112px!important;
}
.fake-button7 {
  left: 928px;
  width: 85px!important;
}
.fake-button8 {
  left: 1032px;
}
.fake-button9 {
  left: 105px;
  top: 0!important;
}
.inpage {
  position: absolute;
  display:block;
  /*background: rgba(0,0,0,.5);*/
  z-index: 120;
}
.fake-button10 {
  top: 167px;
  left: 108px;
  width: 980px;
  height: 480px;
}
.fake-button11 {
  top: 668px;
  left: 109px;
  width: 313px;
  height: 421px;
}
.fake-button12 {
  top: 668px;
  left: 776px;
  width: 313px;
  height: 523px;
}
.fake-button13 {
  top: 1212px;
  left: 776px;
  width: 313px;
  height: 477px;
}
.fake-header {
  position: absolute;
  left: 0;
  right: 0;
  top: 0;
}
.fake-header:before {
  content: " ";
  display: block;
  -webkit-box-sizing: border-box;
  -moz-box-sizing: border-box;
  box-sizing: border-box;
  position: absolute;
  top: 0;
  left: 0;
  right: 0;
  z-index: -1;
  height: 196px;
  border-top: solid 24px #303133;
  background: -webkit-linear-gradient(top, #fff, #fff 91px, #000 91px);
  background: -moz-linear-gradient(top, #fff, #fff 91px, #000 91px);
  background: -o-linear-gradient(top, #fff, #fff 91px, #000 91px);
  background: -ms-linear-gradient(top, #fff, #fff 91px, #000 91px);
  background: linear-gradient(to bottom, #fff, #fff 91px, #000 91px);
}
.fake-header:after {
  content: " ";
  display: block;
  -webkit-box-sizing: border-box;
  -moz-box-sizing: border-box;
  box-sizing: border-box;
  position: absolute;
  top: 0;
  left: 40%;
  right: 0;
  z-index: -1;
  height: 196px;
  border-top: solid 24px #303133;
  background: -webkit-linear-gradient(top, #fff, #fff 91px, #64747d 91px);
  background: -moz-linear-gradient(top, #fff, #fff 91px, #64747d 91px);
  background: -o-linear-gradient(top, #fff, #fff 91px, #64747d 91px);
  background: -ms-linear-gradient(top, #fff, #fff 91px, #64747d 91px);
  background: linear-gradient(to bottom, #fff, #fff 91px, #64747d 91px);
}
.fake-footer {
  position: absolute;
  bottom: 0;
  left: 0;
  right: 0;
  height: 46px;
  background: #1c1c1b;
}
</style>