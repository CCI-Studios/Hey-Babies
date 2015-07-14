(function($){
    $(function(){
        $(".search-button a, .search-close a").on("click", function(){
            $(".search-container").toggleClass("open").slideToggle();
            if ($(".search-container").hasClass("open"))
            {
                $(".search-container .form-text").focus();
            }
            return false;
        });
        
        $(".search-container .form-text").on("keyup", function(e){
            if (e.keyCode == 27) //esc
            {
                $(".search-container").toggleClass("open").slideToggle();
            }
        });
    });
})(jQuery);
