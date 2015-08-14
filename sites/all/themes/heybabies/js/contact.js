(function($){
    var map;
    var geocoder;
    var address = "136 Christina St N, Sarnia, ON";
    
    $(function(){
        if ($("body").hasClass("path-contact"))
        {
            $(".region-content").append("<div id='contact-map'></div>");
            mapInit();
        }
    });

    function mapInit()
    {
        geocoder = new google.maps.Geocoder();
        var mapOptions = {
            zoom: 16,
            scrollwheel: false,
            disableDefaultUI: true,
            styles: [
                {
                    "stylers": [
                        { "saturation": -100 }
                    ]
                }
            ]
        }
        map = new google.maps.Map(document.getElementById('contact-map'), mapOptions);

        showMap(address);
        showMarker();
    }

    function showMarker()
    {
        getAddressLatLng(address, showMarkerLatLng);
    }
    function showMarkerLatLng(latlng, address)
    {
        var marker = new google.maps.Marker({
            map: map,
            position: latlng,
            icon: {
                url: "/sites/all/themes/heybabies/img/map-marker.svg",
                size: new google.maps.Size(67, 67),
                origin: new google.maps.Point(0, 0),
                anchor: new google.maps.Point(34, 66)
            },
            optimized: false
        });
    }
    function showMap(address)
    {
        getAddressLatLng(address, showMapLatLng);
    }
    function showMapLatLng(latlng)
    {
        map.setCenter(latlng);
    }

    function getAddressLatLng(address, callback)
    {
        geocoder.geocode( {'address':address}, function(results, status) {
            if (status == google.maps.GeocoderStatus.OK)
            {
                callback(results[0].geometry.location, address);
            }
        });
    }
})(jQuery);
