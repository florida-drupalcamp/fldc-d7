<div<?php print $attributes; ?>>

  <div class="zone z-navigation">
    <div class="l-navigation">
      <?php print render($page['navigation']); ?>
    </div>
  </div>

    <div class="zone z-header">
      <header class="l-header" role="banner">
        <div class="l-branding">
        <video autoplay="" class="layout-homepage__hi__video" loop="" muted="" poster="" preload="auto">
          <source src="/sites/default/files/FLDC17%20Promo-high.mp4" type="video/mp4">
        </video>
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
