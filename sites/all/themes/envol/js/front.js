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
          console.log(t);
        }

        el.html(t.html());
        t.remove();
      }
    });
  };

  
  $(document).ready(function() {
    var containerShortNew = $('.front .view-display-id-home .views-row-1, .front .view-display-id-home .views-row-2');
    var containerHomeHighlight = $('.front .view-display-id-first_article_home_envol');
    var 
      fieldBodyShortNew,
      titleShortNew,
      titleNodeType,
      imgShortNew,
      catShortNew,
      heightFieldBody,
      linkReadMore,
      linksShortNew
    ;

    containerShortNew.each(function(){

      titleShortNew = $(this).find('.node__title');
      titleNodeType = $(this).find('.node-type-title');
      imgShortNew = $(this).find('.field-name-field-visuel');
      catShortNew = $(this).find('.field-name-field-thematique');
      linkReadMore = $(this).find('.readmore');
      linksShortNew = $(this).find('.links');
      fieldBodyShortNew = $(this).find('.field-name-body');

      heightFieldBody = $(this).height() - titleShortNew.outerHeight(true) - titleNodeType.outerHeight(true) - imgShortNew.outerHeight(true) - catShortNew.outerHeight(true) - linksShortNew.outerHeight(true) - linkReadMore.outerHeight(true);
      console.log(heightFieldBody);
      fieldBodyShortNew.css({'height':heightFieldBody + 'px'}).ellipsis();
    });

    containerHomeHighlight.each(function(){

      titleNodeType = $(this).find('.wrapper-big-title');
      linkReadMore = $(this).find('.readmore');
      linksShortNew = $(this).find('.links');
      fieldBodyShortNew = $(this).find('.field-name-body');

      heightFieldBody = $(this).height() - titleNodeType.outerHeight(true) - catShortNew.outerHeight(true) - linksShortNew.outerHeight(true) - linkReadMore.outerHeight(true) - 40;
      console.log(heightFieldBody);
      fieldBodyShortNew.css({'height':heightFieldBody + 'px'}).ellipsis();
    });
  });

})(jQuery, Drupal, this, this.document);

