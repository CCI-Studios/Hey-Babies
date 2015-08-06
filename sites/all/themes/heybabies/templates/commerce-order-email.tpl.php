<style>
.view
{
    text-align: center;
    font-size: 0;
}
.views-row
{
    width: 30.33%;
    margin: 10px 1.5%;
    display: inline-block;
    font-size: 16px;
}
.views-field-commerce-unit-price
{
    color: #96d2b7;
    font-weight: bold;
    font-size: 0.85em;
}

@media screen and (max-width: 480px)
{
    .views-row
    {
        width: auto;
        float: none;
    }
}
</style>

<h2>order placed</h2>
<p>Your order has been placed. You will receive another email when your order has been shipped along with a tracking number. Below is a summary of order #<?php print $order->order_number; ?>:</p>
<p><a class="button" href="<?php global $base_url; print $base_url.'/user/'.$order->uid.'/orders/'.$order->order_id; ?>">view order online</a></p>
<p>Thank you for shopping with Hey Babies!</p>
<p>&nbsp;</p>
<hr>
<p>&nbsp;</p>
<h2>you purchased</h2>
<?php
print views_embed_view('commerce_email_line_items', 'default', $order->order_id);
?>
