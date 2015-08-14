<div class="entity-commerce-order">
<?php
print '<div class="order-status"><h2>status: '.$commerce_order->status.'</h2></div>';

print '<div class="tracking-info"><h2>tracking info</h2>';
if (isset($commerce_order->field_tracking_number[LANGUAGE_NONE][0]))
{
    foreach ($commerce_order->commerce_order_total[LANGUAGE_NONE][0]['data']['components'] as $line_item)
    {
        if ($line_item['name'] == 'shipping')
        {
            $carrier_code = $line_item['price']['data']['carrier_code'];
            $carrier = $line_item['price']['data']['carrier_label'];
            break;
        }
    }
    if ($carrier)
    {
        $tracking_url = FALSE;
        switch ($carrier_code)
        {
            case 'UPS':
                $tracking_url = 'http://wwwapps.ups.com/WebTracking/track?track.x=Track&trackNums=';
                break;
            case 'CanadaPost':
                $tracking_url = 'http://www.canadapost.ca/cpotools/apps/track/personal/findByTrackNumber?trackingNumber=';
                break;
        }
        foreach ($commerce_order->field_tracking_number[LANGUAGE_NONE] as $tracking_number)
        {
            print '<div class="tracking-number '.strtolower($carrier_code).'">';
            print '<a href="'.$tracking_url.$tracking_number['value'].'" target="_blank">'.$tracking_number['value'].'</a>';
            print '</div>';
        }
    }
}
else
{
    print '<p>no tracking info available</p>';
}
print '</div>';

print views_embed_view('products_in_an_order', 'default', $commerce_order->order_id);
?>
</div>
