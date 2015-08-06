<?php
$base = $GLOBALS['base_url'];
$theme = $base.'/'.drupal_get_path('theme', 'heybabies');
?>

<div class="htmlmail-body" style="color:#707070;">
    <style>
        @media only screen and (max-width:480px)
        {
            table[class="container"]
            {
                width: 100%;
            }
        }
        
        a
        {
            color: #96d2b7;
        }
        h1, h2
        {
            color: #96d2b7;
            text-align:center;
            margin: 0 0 0.5em 0;
            font-weight: normal;
            font-size: 2.5em;
        }
        hr
        {
            height: 0;
            border: 0;
            border-bottom: 1px solid #e6e6e6;
        }
        .button
        {
            color: white;
            background: #96d2b7;
            display:block;
            padding:16px 0;
            text-align:center;
            text-decoration:none;
            border-radius: 4px;
        }
    </style>
    
    
    <a href="<?php print $base;?>" style="display:block; text-align:center; padding: 20px 0; border-bottom: 1px solid #e6e6e6;">
        <img src='<?php print $theme;?>/img/hb-logo2.png' width='160' height='117' alt='Hey Babies' />
    </a>
    <table class="container" width="600" style="margin:30px auto;font-size:14px;" border="0" cellpadding="0"><tr><td>
        <?php print $body; ?>
    </td></tr></table>
    
    <p style="text-align:center;font-size:12px;margin:40px 0 0.5em 0;padding-top:40px;border-top:1px solid #e6e6e6;">Have a question? Contact us at <a href="mailto:support@heybabies.ca" style="color: #96d2b7;">support@heybabies.ca</a></p>
    <p style="text-align:center;font-size:12px;margin:0 0 0.5em 0;">136 Christina St N, Sarnia, ON</p>
    <p style="text-align:center;font-size:12px;margin:0 0 0.5em 0;"><a href="mailto:support@heybabies.ca?subject=Unsubscribe" style="color: #96d2b7;">unsubscribe</a></p>
    <p style="text-align:center;margin: 30px 0;">
        <a href="https://www.facebook.com/heybabiesinc"><img src="<?php print $theme;?>/img/icon-fb2.png" alt="HeyBabies on Facebook" /></a>&nbsp;
        <a href="https://twitter.com/heybabiesinc"><img src="<?php print $theme;?>/img/icon-tw2.png" alt="HeyBabies on Twitter" /></a>&nbsp;
        <a href="https://instagram.com/heybabiesinc/"><img src="<?php print $theme;?>/img/icon-ig2.png" alt="HeyBabies on Instagram" /></a>&nbsp;
        <a href="<?php print $base;?>"><img src="<?php print $theme;?>/img/icon-pin2.png" alt="HeyBabies on Pinterest" /></a></p>
    <div style="background: #96d2b7; text-align:center; padding: 24px 0;"><img src="<?php print $theme;?>/img/hb-logo-white.png" alt="" /></div>
</div>