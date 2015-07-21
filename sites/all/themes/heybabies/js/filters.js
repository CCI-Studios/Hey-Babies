(function($){
    $(function(){
        $(".view-products .show-filters").on("click", function(){
            $(this).toggleClass("open");
            $(".view-products .view-filters").slideToggle();
            return false;
        });
    });
})(jQuery);
