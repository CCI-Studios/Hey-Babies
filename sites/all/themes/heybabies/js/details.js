(function($){
    $(function(){
        $(".view-product-node .views-field-field-image-1 ul").slick({
            slide: 'li',
            dots: false,
            arrows: false,
            slidesToShow: 1,
            slidesToScroll: 1,
            fade: true,
            speed: 250,
            swipe: false
        });
        $(".view-product-node .views-field-field-image ul").slick({
            slide: 'li',
            dots: false,
            arrows: false,
            slidesToShow: 8,
            slidesToScroll: 1,
            focusOnSelect: true,
            vertical: true,
            swipe: false,
            asNavFor: '.view-product-node .views-field-field-image-1 ul'
        });
        
        $(".view-product-node .views-field-field-image-1 li").zoom();
        
        $(".view-product-node .views-field-field-image-1")
        .append("<div class='cover'><div class='click-to-zoom'>click to zoom</div></div>")
        .on("click", ".cover", function(event){
            $(".cover").remove();
            var e = $.Event('mouseover');
            e.pageX = event.pageX;
            e.pageY = event.pageY;
            $(".view-product-node .slick-current").trigger(e);
        });
    });
})(jQuery);
