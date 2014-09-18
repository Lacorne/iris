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

  $.fn.ellipsis = function()
  {
    return this.each(function() {
      var el = $(this);

      if(el.css("overflow") == "hidden") {
        var text = el.html();
        //var multiline = el.hasClass('multiline');
        var multiline = true;
        var t = $(this.cloneNode(true))
                .hide()
                .css('position', 'absolute')
                .css('overflow', 'visible')
                .width(multiline ? el.width() : 'auto')
                .height(multiline ? 'auto' : el.height());

        el.after(t);

        function height() { return t.height() > el.height(); };
        function width() { return t.width() > el.width(); };

        //var func = multiline ? height : width;
        var func = multiline ? height : width;
        
        while (text.length > 0 && func()) {
          text = text.substr(0, text.length - 1);
          t.html(text + "...");
        }

        el.html(t.html());
        t.remove();
      }
    });
  };

  
  $(document).ready(function() {

    //find first node of Envol
    var
      envolNews = $('.envol-last-news');
      firstNodeEnvol = envolNews.find('.node:first')
    ;
    if(firstNodeEnvol.length) {
      envolNews.addClass(firstNodeEnvol.attr('class').split(' ')[2]);
    }

    /*
    //Cut chapô
    var containerShortNew = $('.front .view-listescontenus:not(.view-display-id-first_news) .view-mode-teaser_small_img');
    var 
      fieldBodyShortNew,
      titleShortNew,
      imgShortNew,
      catShortNew,
      heightFieldBody,
      linkReadMore,
      linksShortNew
    ;

    containerShortNew.each(function(){

      titleShortNew = $(this).find('.node__title');
      imgShortNew = $(this).find('.field-type-image');
      catShortNew = $(this).find('.field-name-field-category');
      linkReadMore = $(this).find('.readmore');
      linksShortNew = $(this).find('.links');
      fieldBodyShortNew = $(this).find('.field-name-field-chapo');

      heightFieldBody = $(this).height() - titleShortNew.outerHeight(true) - imgShortNew.outerHeight(true) - catShortNew.outerHeight(true) - linksShortNew.outerHeight(true) - linkReadMore.outerHeight(true);
      console.log(heightFieldBody);
      fieldBodyShortNew.css({'height':heightFieldBody + 'px'}).ellipsis();
    });
    */
  });

})(jQuery, Drupal, this, this.document);

