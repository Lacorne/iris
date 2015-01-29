/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  $(document).ready(function() {

    var minExperts = $('.wrapper-experts'),
        wPage = $('.wrapper-focus, wrapper-analyse, wrapper-invite, wrapper-ensemble, wrapper-journee'),
        hWPage = wPage.outerHeight(true),
        allExperts = $('.wrapper-experts-complete'),
        close = $('.close'),
        isHeightFocusModified = false,
        hAllExperts
    ;

    minExperts.on('click', function(e) {
      e.preventDefault();
      allExperts.fadeIn('slow', function(){
        hAllExperts = allExperts.find('.field-collection-container').outerHeight(true) + allExperts.find('.node-title').outerHeight(true) + allExperts.find('.wrapper-close-button').outerHeight(true);
        if (hAllExperts > hWPage) {
          isHeightFocusModified = true;
          wPage.css({'height': hAllExperts + 'px'});
        }
        $("html, body").animate({ scrollTop: 0 }, "slow");
      });
    });

    close.on('click', function(e) {
      e.preventDefault();
      allExperts.fadeOut('slow');
      if (isHeightFocusModified) {
        wPage.css({'height':''});
      }
    });

  });

})(jQuery, Drupal, this, this.document);

