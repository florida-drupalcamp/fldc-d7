<?php

/**
 * This is the sub-view for the session-schedule. Its function is to group all speakers together
 */
?>
<?php if ($rows): ?>
    <?php print $rows; ?>
<?php elseif ($empty): ?>
    <?php print $empty; ?>
<?php endif; ?>
