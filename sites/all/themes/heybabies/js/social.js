(function($){
    $(function(){
        $(".view-social .views-field-field-photo a").on("click", openPopup);
        $(".view-social .popup-cover, .view-social .popup-close").on("click", closePopup);
        $(".view-social .popup-prev").on("click", clickPrevPopup);
        $(".view-social .popup-next").on("click", clickNextPopup);
    });
    
    function openPopup()
    {
        var popup = $(this).parents(".views-row").find(".popup").addClass("current").fadeIn();
        var slider = popup.find(".slick-slider");
        if (slider.length)
        {
            slider.get(0).slick.refresh();
        }
        $(".view-social").find(".popup-cover, .popup-button").fadeIn();
        return false;
    }
    
    function closePopup()
    {
        $(".view-social").find(".popup, .popup-cover, .popup-button").fadeOut();
        return false;
    }
    
    function clickPrevPopup()
    {
        var current = $(".view-social .popup.current");
        if (current)
        {
            current.removeClass("current");
            var next = current.parents(".views-row").prev().find(".popup");
            if (next.length == 0)
            {
                next = $(".view-social .views-row-last .popup");
            }
            current.fadeOut(function(){
                next.fadeIn(function(){
                    next.addClass("current");
                });
                var slider = next.find(".slick-slider");
                if (slider.length) slider.get(0).slick.refresh();
            });
        }
        return false;
    }
    function clickNextPopup()
    {
        var current = $(".view-social .popup.current");
        if (current)
        {
            current.removeClass("current");
            var next = current.parents(".views-row").next().find(".popup");
            if (next.length == 0)
            {
                next = $(".view-social .views-row-first .popup");
            }
            current.fadeOut(function(){
                next.fadeIn(function(){
                    next.addClass("current");
                });
                var slider = next.find(".slick-slider");
                if (slider.length) slider.get(0).slick.refresh();
            });
        }
        return false;
    }
})(jQuery);
