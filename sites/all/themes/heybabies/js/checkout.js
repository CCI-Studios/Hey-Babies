(function($){
    $(function(){
        init_checkout_items();
        
        $(".view-commerce-cart-summary .view-content").on("click", ".cart-show-more", function(){
            $(".view-commerce-cart-summary .views-row.hidden").slideDown().removeClass("hidden");
            $(this).remove();
            return false;
        });
    });
    
    function init_checkout_items()
    {
        (function($){
            var maxRows = 5;
            var minHidden = 2;
            var numRows = $(".view-commerce-cart-summary .views-row").length;
            if (numRows > maxRows)
            {
                $(".view-commerce-cart-summary .views-row").slice(maxRows-minHidden+1).addClass("hidden");
                $(".view-commerce-cart-summary .view-content").append("<a class='cart-show-more' href='#'>show "+(numRows-maxRows+minHidden-1)+" more items</a>");
            }
        })(jQuery);
    }

})(jQuery);
