<?php
if ($component['nid'] == 5):
    $idKey = str_replace('_', '-', $component['form_key']); 
    ?>
    <div id="webform-datepicker-text">
        <input type="text" placeholder="preferred pick-up date*" id="edit-submitted-<?php print $idKey ?>" class="form-text <?php print implode(' ', $calendar_classes); ?>" alt="<?php print t('Open popup calendar'); ?>" title="<?php print t('Open popup calendar'); ?>" />
    </div>
    <?php 
else:
    ?>
    <input type="image" src="<?php print base_path() . drupal_get_path('module', 'webform') . '/images/calendar.png'; ?>" class="<?php print implode(' ', $calendar_classes); ?>" alt="<?php print t('Open popup calendar'); ?>" title="<?php print t('Open popup calendar'); ?>" />
    <?php 
endif;
?>
