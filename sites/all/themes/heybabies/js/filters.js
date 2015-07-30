(function($){
    $(function(){
        $(".view-child-terms .view-content a").each(function(){
            var term = $(this).data("term").toLowerCase();
            var parent = $(this).data("parent");
            if (parent) parent = parent.toLowerCase()+"/";
            var path = window.location.pathname.split("/");
            $(this).attr("href", "/"+path[1]+"/"+parent+term);
        });
        $(".view-products .view-child-terms.view-display-id-filter_2").prependTo(".view-products .view-filters");
        
        $(".view-products [name='size[]']").on("change", function(){
            var values = [];
            $(".view-products input[name='size[]']:checked").each(function(){
                values.push(this.value);
            });
            $.cookie("SESSsize", values.join("+"), {"path":"/"});
        });
    });
})(jQuery);
