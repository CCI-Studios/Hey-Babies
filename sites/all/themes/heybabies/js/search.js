(function($){
    $(function(){
        if ($("body").hasClass("page-search"))
        {
            toggleSearch();
        }
        
        $(".search-button a, .search-close a").on("click", function(){
            toggleSearch();
            if ($(".search-container").hasClass("open"))
            {
                $(".search-container .form-text").focus();
            }
            return false;
        });
        
        $(".search-container .form-text").on("keyup", function(e){
            if (e.keyCode == 27) //esc
            {
                toggleSearch();
            }
        });
    });
    
    function toggleSearch()
    {
        $(".search-container").toggleClass("open").slideToggle(150);
    }
})(jQuery);
