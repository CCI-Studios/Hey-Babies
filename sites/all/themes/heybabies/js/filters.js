(function($){
    $(function(){
        $(".view-products .show-filters").on("click", function(){
            $(this).toggleClass("open");
            $(".view-products .view-filters").slideToggle();
            return false;
        });
        
        $(".view-child-terms .view-content a").each(function(){
            var term = $(this).data("term").toLowerCase();
            var parent = $(this).data("parent");
            if (parent) parent = parent.toLowerCase()+"/";
            var path = window.location.pathname.split("/");
            $(this).attr("href", "/"+path[1]+"/"+parent+term);
        });
        $(".view-products .view-child-terms.view-display-id-filter_2").prependTo(".view-products .view-filters");
    });
})(jQuery);
