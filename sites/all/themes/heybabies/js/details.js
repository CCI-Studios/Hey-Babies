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
            swipe: false,
            asNavFor: ".view-product-node .views-field-field-image ul",
            responsive: [
                {
                    breakpoint: 680,
                    settings: {
                        swipe: true
                    }
                }
            ]
        });
        $(".view-product-node .views-field-field-image ul").slick({
            slide: 'li',
            dots: false,
            arrows: false,
            slidesToShow: 5,
            slidesToScroll: 1,
            focusOnSelect: true,
            vertical: true,
            swipe: false,
            asNavFor: '.view-product-node .views-field-field-image-1 ul',
            responsive: [
                {
                    breakpoint: 680,
                    settings: {
                        vertical: false,
                        centerMode: true
                    }
                },
                {
                    breakpoint: 480,
                    settings: {
                        vertical: false,
                        slidesToShow: 3,
                        centerMode: true
                    }
                }
            ]
        });
        
        if ($(window).width() > 680)
        {
            $(".view-product-node .views-field-field-image-1 li").zoom();
            
            $(".view-product-node .views-field-field-image-1")
            .append("<div class='cover'><div class='click-to-zoom'>click to zoom</div></div>")
            .on("click", ".cover", function(event){
                
                $(".view-product-node .cover").remove();
                var e = $.Event('mouseover');
                e.pageX = event.pageX;
                e.pageY = event.pageY;
                $(".view-product-node .slick-current").trigger(e);
            });
        }
    });
})(jQuery);
