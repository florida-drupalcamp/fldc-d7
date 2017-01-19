<?php

/**
 * @file
 * Default theme implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top
 *     class.
 * - $region: The name of the region variable as defined in the theme's .info
 *   file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see template_process()
 */
?>
<?php if ($content): ?>
  <div<?php print $attributes; ?>>
  <div class="header-diver-container">
    <a href="/"><img class="header-diver" src="/sites/all/themes/fldc17/images/drupal-diver-new.svg" alt="Drupal Diver Logo"></a>
    <div class="header-bubble bubble1"><img src="/sites/all/themes/fldc17/images/bubbles.svg" alt="Bubble"></div>
    <div class="header-bubble bubble2"><img src="/sites/all/themes/fldc17/images/bubbles.svg" alt="Bubble"></div>
    <div class="header-bubble bubble3"><img src="/sites/all/themes/fldc17/images/bubbles.svg" alt="Bubble"></div>
    <div class="header-bubble bubble4"><img src="/sites/all/themes/fldc17/images/bubbles.svg" alt="Bubble"></div>
    <div class="header-bubble bubble5"><img src="/sites/all/themes/fldc17/images/bubbles.svg" alt="Bubble"></div>
  </div>

    <h1 class="site-name">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
    </h1>



    <?php print $content; ?>
  </div>
<?php endif; ?>
