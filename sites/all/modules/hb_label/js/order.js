(function($){
    $(function(){
        $(".page-admin .entity-commerce-order").before("<form action='' method='post' id='order_product_scan' style='display:block; margin-bottom:1em;'><label>Scan products in this order: <input type='text' class='form-text' /></label></form>");
        $(".page-admin form#order_product_scan").on("submit", scanProductSubmit).find("input").focus();
        $("#hb-label-shipping-label-form").on("submit", shippingLabelSubmit);
    });
    
    function scanProductSubmit()
    {
        var pid = $(this).find("input").val();
        $(this).find(".message").remove();
        if ($(".view-line-items-admin [data-pid="+pid+"]").length)
        {
            $(".view-line-items-admin [data-pid="+pid+"]").html("<img src='/misc/message-16-ok.png' title='Scanned' />")
            .parents(".views-row").addClass("scanned").css("background-color","#C9EFC9");
            playSound("accept");
            
            if ($(".view-line-items-admin .views-row").length == $(".view-line-items-admin .views-row.scanned").length)
            {
                $("#hb-label-shipping-label-form").removeClass("element-invisible");
            }
        }
        else
        {
            playSound("reject");
            $(this).append("<div class='message'>Wrong/unknown product</div>");
        }
        
        $(this).find("input").val("").focus();
        return false;
    }
    function playSound(soundFile)
    {
        $("body").append("<audio autoplay src='/sites/all/modules/hb_label/media/"+soundFile+".mp3' style='position:absolute; left:-999999px;' />");
    }
    
    function shippingLabelSubmit()
    {
        return confirm("This will generate and pay for a new shipping label.\nAn email will be sent to the customer with a tracking number.\nAre you sure?");
    }
})(jQuery);
