<script src="//use.typekit.net/asn7cpl.js"></script>
<script>try{Typekit.load();}catch(e){}</script>
<link rel="stylesheet" type="text/css" href="/<?php print drupal_get_path('module','hb_label');?>/css/label.css" />
<div class="inventory_label">
    <div class="logo">
        <img src="/<?php print drupal_get_path('module', 'hb_label');?>/img/hb-logo.svg" />
    </div>
    <div class="info">
        <div class="title"><?php print $title;?></div>
        <div class="clothing_type"><label>Type: </label><span><?php print $clothing_type;?></span></div>
        <div class="sex"><label>Gender: </label><span><?php print $sex;?></span></div>
        <div class="age"><label>Age: </label><span><?php print $age;?></span></div>
        <div class="id"><label>ID: </label><span><?php print $pid;?></span></div>
        <div class="sku"><?php print $sku;?></div>
        <div class="barcode">*<?php print $pid;?>*</div>
    </div>
</div>