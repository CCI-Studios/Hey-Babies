(function($){
    $(function(){
        $(".menu-main-menu > ul > li.expanded > a").on("click", function(){
            $(".menu-main-menu .open").not($(this).parent()).removeClass("open").find("> ul").hide();
            $(this).parent().toggleClass("open").find("> ul").slideToggle(200);
            return false;
        });
    });
})(jQuery);
