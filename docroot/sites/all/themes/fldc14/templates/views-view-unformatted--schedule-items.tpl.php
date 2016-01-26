<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="session-wrapper">
  <?php if (!empty($title)): ?>
    <h3 class="session-slot--title"><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
      <?php print $row; ?>
      <div class="session-expand"></div>
    </div>
  <?php endforeach; ?>
</div>