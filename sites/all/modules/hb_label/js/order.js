(function($){
    $(function(){
        $(".entity-commerce-order").before("<form action='' method='post' id='order_product_scan' style='display:block; margin-bottom:1em;'><label>Scan products in this order: <input type='text' class='form-text' /></label></form>");
        $("form#order_product_scan").on("submit", formSubmit).find("input").focus();
    });
    
    function formSubmit()
    {
        var pid = $(this).find("input").val();
        $(this).find(".message").remove();
        if ($(".view-commerce-line-item-table [data-pid="+pid+"]").length)
        {
            $(".view-commerce-line-item-table [data-pid="+pid+"]").html("<img src='/misc/message-16-ok.png' title='Scanned' />")
            .parents(".views-row").css("background-color","#C9EFC9");
            $("body").append("<audio autoplay src='/sites/all/modules/hb_label/media/accept.mp3' style='position:absolute; left:-999999px;' />");
        }
        else
        {
            $("body").append("<audio autoplay src='/sites/all/modules/hb_label/media/reject.mp3' style='position:absolute; left:-999999px;' />");
            $(this).append("<div class='message'>Wrong/unknown product</div>");
        }
        
        $(this).find("input").val("").focus();
        return false;
    }
})(jQuery);
