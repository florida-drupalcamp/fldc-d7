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
        $(this).parent().toggleClass('js-expanded').find('.session-description').slideToggle(200);
      });
    }
  };


  Drupal.behaviors.coolShitOnScroll = {
    attach: function ( context, settings ) {
      var $locationInfo = $('#location-info', context);

      if ($locationInfo.length) {
        $(window).scroll( function (){
          // Location Slide in
          if($(window).scrollTop() + $(window).height() >= $locationInfo.offset().top) {
            $locationInfo.addClass('scroll-down');
          }
          if($(window).scrollTop() + $(window).height() < $locationInfo.offset().top) {
            $locationInfo.removeClass('scroll-down');
          }
        });
      }
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
      alert('Your browser is a bit outdated. For the best user experience, it is recommended that you upgrade from Internet Exporer ' + $.browser.version + ' to IE 11 or to another browser all together, like Firefox, Chrome, Safari or Opera. <a href="http://blogs.technet.com/b/security/archive/2013/08/15/the-risk-of-running-windows-xp-after-support-ends.aspx" target="_blank">Win XP Support ends April 2014</a>');
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

  // Truncate long sponsor descriptions
  Drupal.behaviors.sponsorHelper = {
    attach: function ( context, settings ) {
      $sponsorText =  $('.view-sponsors .wrap-back', context);

      if ($sponsorText.length && $(window).width() >= 1200) {
        $sponsorText.dotdotdot();
      }
    }
  };

  // Mailing list modal - only opens on non-webform pages and viewports > 800px
  Drupal.behaviors.closingModal = {
    attach: function ( context, settings ) {
      var $modal = '<div class="modal modal-post-camp">' +
        '<div class="modal-inner"><button type="button" class="modal-close modal-close-x">Close</button>' +
        '<h2 class="modal-title">Florida Drupalcamp was held in February 2017</h2>' +
        '<p>Our next annual camp will be winter/spring 2018. Sign up to our mailing list to stay updated.</p>' +
        '<a class="button button-action" href="http://eepurl.com/bUXSmP" target="_blank">Sign up for Mailing List</a>' +
        '<button type="button" class="modal-close modal-close-text">Close</button>' +
        '</div></div>';

      if ($.cookie('fldc17.modal') != 'modaldisabled' && !$('body', context).hasClass('node-type-webform') && $(window).width() > 800) {
        $('body', context).append($modal);
        $('.modal .button-action', context).focus();

        $('.modal-close', context).on('click', function() {
          closeModal();
        });

        $(document).on('keyup', function (e) {
          if (e.keyCode == 27) {
            closeModal();
          }
        });
      }

      function closeModal() {
        $('.modal', context).remove();
        $.cookie('fldc17.modal', 'modaldisabled', { expires: 1, path: '/' });
        $('.site-name a', context).focus();
      }

    }
  };

})(jQuery);
