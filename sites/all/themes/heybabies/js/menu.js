(function($){
    $(function(){
        $(".menu-main-menu > ul > li.expanded > a").on("click touchend", function(){
            if ($(window).width() > 680)
            {
                $(".menu-main-menu .open").not($(this).parent()).removeClass("open").find("> ul").hide();
            }
            $(this).parent().toggleClass("open").find("> ul").slideToggle(200);
            return false;
        });
        
        $(".block-system-user-menu li.expanded > a").on("click touchend", function(){
            $(".menu-main-menu .open").not($(this).parent()).removeClass("open").find("> ul").hide();
            $(this).parent().toggleClass("open");
            return false;
        });
        
        $(".mobile-menu-btn").on("click touchend", function(){
            $(".menu-main-menu").slideToggle(200);
            return false;
        });
    });
    
    $(window).on("load", function(){
        if (window.location.pathname == "/" && window.location.hash == "#contributions")
        {
            $("body").scrollTop($(".contributions").position().top - $(".navigation").height());
        }
    });
})(jQuery);
