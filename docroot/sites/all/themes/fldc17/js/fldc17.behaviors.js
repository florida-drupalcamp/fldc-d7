(function ($) {

  Drupal.behaviors.fldc14BrowserClass = {
    attach: function ( context, settings ) {
      if ($.browser.msie && $.browser.version === 10) { // Detects IE10
        $('html', context).addClass('ie10');
      }
      if (!!navigator.userAgent.match(/Trident\/7\./)) { // Detects IE11
        $('html', context).addClass('ie11');
      }
    }
  };

  // Drupal.behaviors.fldc14iesvg = {
  //   attach: function ( context, settings ) {
  //     // Detects IE9,10, & 11
  //     if (($.browser.msie && $.browser.version >= 9) || (!!navigator.userAgent.match(/Trident\/7\./))) {
  //       var img = document.getElementById('main-img');
  //       var width = img.clientWidth;
  //       var height = width * 1.29;  // the ratio of width to height of the drupal diver svg
  //       $('#main-img', context).css('height', height);
  //     }
  //   }
  // };

  // // Moving exploding animation to JS because nested animation doesn't work properly in FF
  // Drupal.behaviors.explodeShit = {
  //   attach: function ( context, settings ) {
  //     $('.diver-bubble > img', context).click(function() {
  //       $(this).addClass('explode-this-shit')
  //              .attr('src', '/sites/all/themes/fldc14/images/explosion.svg')
  //              .animate({
  //                height: '300%',
  //                width: '300%'
  //              }, 300, function () {
  //               $(this).parent().css({ 'display' : 'none'});
  //              });
  //     });
  //   }
  // };

  Drupal.behaviors.fldc14MobileMenu = {
    attach: function ( context, settings ) {
      $('#block-system-main-menu', context).after($('<div id="mobile-menu"></div>'));
      $('#mobile-menu', context).once('mobile', function () {
        $(this).click( function () {
          $(this).toggleClass('header-menu-active');
          $('#block-system-main-menu', context).toggleClass('header-menu-active');
        });
      });
    }
  };

  Drupal.behaviors.sessionExpand = {
    attach: function ( context, settings ) {
      $('.session-expand', context).click(function() {
        // $('.session', context).removeClass('js-expanded');
        $(this).parent().toggleClass('js-expanded');
      });
    }
  };

  // Drupal.behaviors.headingHeightOnScroll = {
  //   attach: function ( context, settings ) {
  //     $('body', context).once('scroll', function () {
  //       var $nav = $('#block-system-main-menu', context);
  //       var $heading = $('.z-navigation', context);
  //       $(window).scroll( function (){
  //         var scrollTop = $(window, context).scrollTop();
  //         if ( scrollTop >= 100 ) {
  //           $heading.addClass('scroll-down');
  //           $nav.addClass('scroll-down');
  //         }
  //         else if (scrollTop < 100) {
  //           $heading.removeClass('scroll-down');
  //           $nav.removeClass('scroll-down');
  //         }
  //       });
  //     });
  //   }
  // };

  Drupal.behaviors.coolShitOnScroll = {
    attach: function ( context, settings ) {
      // var $speaker = $('.speaker', context);
      var $locationInfo = $('#location-info', context);
      $(window).scroll( function (){
        // Featured Speaker Pop
        // if($(window).scrollTop() + $(window).height() >= $speaker.offset().top) {
        //   $speaker.addClass('scroll-down');
        // }
        // if($(window).scrollTop() + $(window).height() < $speaker.offset().top) {
        //   $speaker.removeClass('scroll-down');
        // }
        // Location Slide in
        if($(window).scrollTop() + $(window).height() >= $locationInfo.offset().top) {
          $locationInfo.addClass('scroll-down');
        }
        if($(window).scrollTop() + $(window).height() < $locationInfo.offset().top) {
          $locationInfo.removeClass('scroll-down');
        }
      });
    }
  };

  Drupal.behaviors.expandedMenuItems = {
    attach: function ( context, settings ) {
      $('#block-system-main-menu > .menu li.expanded', context).once('expanded-active', function () {
        $(this).each( function () {
          var windowWidth = $(window).width();

          if ( windowWidth <= 1025 ) {
            $('> a', this).click( function ( e ) {
              e.preventDefault();
            });

            $(this).click( function () {
              $(this).siblings('.expanded:not(.expanded-active-processed)').addClass('expanded-active-processed').children('.menu').slideToggle('fast');
              $(this).toggleClass('expanded-active-processed');
              $('.menu', this).slideToggle();
            });
          }
        });
      });
    }
  };

  // Constructors
  $.fn.areYouIE = function () {
    if ($.browser.msie) {
      $(this).addClass('ie-' + $.browser.version);
    }
    else if ($.browser.msie && $.browser.version <= 8) {
      alert('Your browser is a bit outdated. For the best user experience, it is recommended that you upgrade from Internet Exporer ' + $.browser.version + ' to IE 10 or to another browser all together, like Firefox, Chrome, Safari or Opera. <a href="http://blogs.technet.com/b/security/archive/2013/08/15/the-risk-of-running-windows-xp-after-support-ends.aspx" target="_blank">Win XP Support ends April 2014</a>');
    }
  };

  // Helena will be proud of this
  Drupal.behaviors.a11yNavHelper = {
    attach: function ( context, settings ) {
      $('#block-system-main-menu a', context).focus(function() {
        $(this).closest('.expanded').addClass('js-tabbed-expanded');
      });

      $('#block-system-main-menu a', context).blur(function() {
        $(this).closest('.expanded').removeClass('js-tabbed-expanded');
      });
    }
  };

})(jQuery);
