(function ($) {

  /**
   * The recommended way for producing HTML markup through JavaScript is to write
   * theming functions. These are similiar to the theming functions that you might
   * know from 'phptemplate' (the default PHP templating engine used by most
   * Drupal themes including Omega). JavaScript theme functions accept arguments
   * and can be overriden by sub-themes.
   *
   * In most cases, there is no good reason to NOT wrap your markup producing
   * JavaScript in a theme function.
   */
  Drupal.theme.prototype.fldc14DiverBubble = function (path, index) {
    // Create an image element with jQuery.
    return $('<img class="bubble' + index + '" src="/' + path + '" />');
  };




  /**
   * Behaviors are Drupal's way of applying JavaScript to a page. The advantage
   * of behaviors over simIn short, the advantage of Behaviors over a simple
   * document.ready() lies in how it interacts with content loaded through Ajax.
   * Opposed to the 'document.ready()' event which is only fired once when the
   * page is initially loaded, behaviors get re-executed whenever something is
   * added to the page through Ajax.
   *
   * You can attach as many behaviors as you wish. In fact, instead of overloading
   * a single behavior with multiple, completely unrelated tasks you should create
   * a separate behavior for every separate task.
   *
   * In most cases, there is no good reason to NOT wrap your JavaScript code in a
   * behavior.
   *
   * @param context
   *   The context for which the behavior is being executed. This is either the
   *   full page or a piece of HTML that was just added through Ajax.
   * @param settings
   *   An array of settings (added through drupal_add_js()). Instead of accessing
   *   Drupal.settings directly you should use this because of potential
   *   modifications made by the Ajax callback that also produced 'context'.
   */
  Drupal.behaviors.fldc14BrowserClass = {
    attach: function ( context, settings ) {
      if ($.browser.msie && $.browser.version == 10) { // Detects IE10
        $("html").addClass("ie10");
      }
      if (!!navigator.userAgent.match(/Trident\/7\./)) { // Detects IE11
        $("html").addClass("ie11");
      }   
    }
  };

  Drupal.behaviors.fldc14iesvg = {
    attach: function ( context, settings ) {
      // Detects IE9,10, & 11
      if (($.browser.msie && $.browser.version >= 9) || (!!navigator.userAgent.match(/Trident\/7\./))) {
        var img = document.getElementById('main-img'); 
        var width = img.clientWidth;
        var height = width * 0.906;  // the ratio of width to height of the drupal diver svg
        $('#main-img').css("height", height);
      }
    }
  };
  
  Drupal.behaviors.explodeShit = {
    attach: function ( context, settings ) {
      // By using the 'context' variable we make sure that our code only runs on
      // the relevant HTML. Furthermore, by using jQuery.once() we make sure that
      // we don't run the same piece of code for an HTML snippet that we already
      // processed previously. By using .once('foo') all processed elements will
      // get tagged with a 'foo-processed' class, causing all future invocations
      // of this behavior to ignore them.
      $('.diver-bubble', context).click(function() {
        $(this).addClass('explode-this-shit-for-dave')
               .attr('src', '/sites/all/themes/fldc14/images/explosion.svg')
               .removeClass('bubble1')
               .removeClass('bubble2')
               .removeClass('bubble3')
               .removeClass('bubble4')
               .removeClass('bubble5');
      });


    }
  };
  
  Drupal.behaviors.fldc14MobileMenu = {
    attach: function ( context, settings ) {
      $('#block-system-main-menu').after($('<div id="mobile-menu"></div>'));
      $('#mobile-menu', context).once('mobile', function () {
        $(this).click( function () {
          $(this).toggleClass('header-menu-active');
          $('#block-system-main-menu').toggleClass('header-menu-active');
        });
      });
    }
  };

  Drupal.behaviors.sessionSchedule = {
    attach: function ( context, settings ) {
      // Toggle the views-row class on the session sched to expand.
      $('.view-session-schedule .views-row.Session').click(function () {
        $(this).toggleClass('session-view');
      });
    }
  };
  
  Drupal.behaviors.headingHeightOnScroll = {
    attach: function ( context, settings ) {
      $('body', context).once('scroll', function () {
        $(window).scroll( function (){
          var heading = $('.z-navigation'),
              scrollTop = $(window).scrollTop();
          
          // Resize the header on scroll
          if ( scrollTop >= 100 ) {
            $(heading).addClass( "scroll-down" );
            $('#block-system-main-menu').addClass( "scroll-down" );
          } else if ( scrollTop < 100 ) {
            $(heading).removeClass( "scroll-down" );
            $('#block-system-main-menu').removeClass( "scroll-down" );
          }
        });
      });
    }
  };
 
  Drupal.behaviors.coolShitOnScroll = {
    attach: function ( context, settings ) {
      $(window).scroll( function (){
        // Featured Speaker Pop
        if($(window).scrollTop() + $(window).height() >= $('.speaker').offset().top) {
          $( ".speaker" ).addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('.speaker').offset().top) {
          $( ".speaker" ).removeClass( "scroll-down" );
        } 
        // Location Slide in
        if($(window).scrollTop() + $(window).height() >= $('#location-info').offset().top) {
          $( "#location-info" ).addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('#location-info').offset().top) {
          $( "#location-info" ).removeClass( "scroll-down" );
        } 

        // todo Refactor this mess

        // Platinum Sponsor Pop
        if($(window).scrollTop() + $(window).height() >= $('.view-cod-sponsors > .view-content .wrap').offset().top) {
          $('.view-cod-sponsors > .view-content .wrap').addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('.view-cod-sponsors > .view-content .wrap').offset().top) {
          $('.view-cod-sponsors > .view-content .wrap').removeClass( "scroll-down" );
        }  

        // Gold Sponsor Pop
        if($(window).scrollTop() + $(window).height() >= $('.view-cod-sponsors .view-display-id-attachment_1 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_1 .wrap').addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('.view-cod-sponsors .view-display-id-attachment_1 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_1 .wrap').removeClass( "scroll-down" );
        }

        // Silver Sponsor Pop
        if($(window).scrollTop() + $(window).height() >= $('.view-cod-sponsors .view-display-id-attachment_2 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_2 .wrap').addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('.view-cod-sponsors .view-display-id-attachment_2 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_2 .wrap').removeClass( "scroll-down" );
        }

        // Bronze Sponsor Pop
        if($(window).scrollTop() + $(window).height() >= $('.view-cod-sponsors .view-display-id-attachment_3 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_3 .wrap').addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('.view-cod-sponsors .view-display-id-attachment_3 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_3 .wrap').removeClass( "scroll-down" );
        }

        // In-kind Sponsor Pop
        if($(window).scrollTop() + $(window).height() >= $('.view-cod-sponsors .view-display-id-attachment_4 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_4 .wrap').addClass( "scroll-down" );
        }

        if($(window).scrollTop() + $(window).height() < $('.view-cod-sponsors .view-display-id-attachment_4 .wrap').offset().top) {
          $('.view-cod-sponsors .view-display-id-attachment_4 .wrap').removeClass( "scroll-down" );
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
  
  // Drupal.behaviors.stickyFooter = {
  //   attach: function ( context, settings ) {
  //     $('.z-footer', context).once('sticky-footer', function () {
  //       var t = $(this),
  //           th = t.outerHeight(),
  //           zPrev = t.prev('.zone');
        
  //       zPrev.css( 'padding-bottom', th );
  //     });
  //   }
  // };
  
  // Constructors
  $.fn.areYouIE = function () {
    if ($.browser.msie) {
      $(this).addClass('ie-' + $.browser.version);
    } else if ($.browser.msie && $.browser.version <= 8) {
      alert('Your browser is a bit outdated. For the best user experience, it is recommended that you upgrade from Internet Exporer ' + $.browser.version + ' to IE 10 or to another browser all together, like Firefox, Chrome, Safari or Opera. <a href="http://blogs.technet.com/b/security/archive/2013/08/15/the-risk-of-running-windows-xp-after-support-ends.aspx" target="_blank">Win XP Support ends April 2014</a>');
    } else {
      console.log('You\'re AWESOME! Thanks for not using Internet Explorer!');
    }
  };

})(jQuery);
