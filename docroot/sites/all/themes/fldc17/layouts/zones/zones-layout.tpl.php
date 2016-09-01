<div<?php print $attributes; ?>>

  <div class="zone z-navigation">
    <div class="l-navigation">
      <?php print render($page['navigation']); ?>
    </div>
  </div>

    <div class="zone z-header">
      <header class="l-header" role="banner">
        <div class="l-branding">
          <?php if ($logo): ?>
            <div class="site-logo ie8-hide">
              <img id="main-img" class="site-logo__img" src="/<?php print path_to_theme(); ?>/images/drupal-diver-no-bubble.svg" alt="<?php print t('FLorida DrupalCamp Logo'); ?>" title="Florida DrupalCamp 2015" />
              <div class="diver-bubble bubble1"><img src="/sites/all/themes/fldc17/images/bubbles.svg"></div>
              <div class="diver-bubble bubble2"><img src="/sites/all/themes/fldc17/images/bubbles.svg"></div>
              <div class="diver-bubble bubble3"><img src="/sites/all/themes/fldc17/images/bubbles.svg"></div>
              <div class="diver-bubble bubble4"><img src="/sites/all/themes/fldc17/images/bubbles.svg"></div>
              <div class="diver-bubble bubble5"><img src="/sites/all/themes/fldc17/images/bubbles.svg"></div>
            </div>
            <!--[if lte IE 8]>
            <div class="site-logo"><img class="site-logo__img" src="/<?php print $directory ?>/images/drupal-diver-no-bubble.png" title="Florida DrupalCamp 2014" /></div>
            <![endif]-->
          <?php endif; ?>

          <?php print render($page['branding']); ?>
        </div>
        <?php print render($page['header']); ?>
        <?php if (!$is_front): ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1 class="page__title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
        <?php endif; ?>
      </header>
    </div>

  <?php if ($page['preface']): ?>
    <div class="zone z-preface">
      <div class="l-preface">
        <?php print render($page['preface']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($page['preface2']): ?>
    <div class="zone z-preface2">
      <div class="l-preface2">
        <?php print render($page['preface2']); ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="zone z-content">
    <div class="l-main">
      <div class="l-content" role="main">
        <?php print render($page['highlighted']); ?>
        <a id="main-content"></a>
        <?php /* print render($title_prefix); ?>
        <?php if ($title): ?>
          <!-- <h1 class="page__title"><?php print $title; ?></h1> -->
        <?php endif; ?>
        <?php print render($title_suffix); */ ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </div>

      <?php print render($page['sidebar_first']); ?>
      <?php print render($page['sidebar_second']); ?>
    </div>
  </div>

  <?php if ($page['postscript']): ?>
    <div class="zone z-postscript">
      <div class="l-postscript">
        <?php print render($page['postscript']); ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="zone z-footer">
    <footer class="l-footer" role="contentinfo">
      <?php print render($page['footer']); ?>
    </footer>
  </div>

</div>
