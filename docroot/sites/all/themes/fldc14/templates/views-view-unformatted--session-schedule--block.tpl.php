<?php

/**
 * @file
 * This is the sub-view for the session-schedule. Its function is to group all speakers together
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>