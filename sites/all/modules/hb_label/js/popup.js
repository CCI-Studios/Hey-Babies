(function($){
    $(function(){
        $(".view-commerce-backoffice-products a.print_label").click(printLabelClick);
    });
    
    function printLabelClick()
    {
        var pid = $(this).data("pid");
        var url = "/admin/commerce/products/label/"+pid;
        var newwindow = window.open(url, 'name', 'height=140,width=332');
        return false;
    }
})(jQuery);
