(function($){
    $(function(){
        resize_headers();
        $(window).on("load resize", resize_headers);
    });
    
    function resize_headers()
    {
        var height = $(window).height() - $(".navigation").height() - $(".view-front-features").height();
        $(".view-front-headers .background").height(height);
    }
})(jQuery);
