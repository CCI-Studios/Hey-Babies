<?php
drupal_add_library('slick', 'slick');
drupal_add_js(drupal_get_path('theme', 'heybabies').'/js/jquery.zoom.min.js');
drupal_add_js(drupal_get_path('theme', 'heybabies').'/js/details.js');

$title = strtolower($title);
$product_id = $node->field_product['und'][0]['product_id'];
$product = commerce_product_load($product_id);
$sex = $product->field_sex['und'][0]['taxonomy_term'];
$clothing_type = $product->field_clothing_type['und'][0]['taxonomy_term'];
$clothing_type_parents = taxonomy_get_parents($clothing_type->tid);
$clothing_type_parent = (empty($clothing_type_parents)) ? FALSE : current($clothing_type_parents);
$clothing_type_parent_tid = $clothing_type_parent ? $clothing_type_parent->tid : $clothing_type->tid;
$clothing_type_path = '/'.drupal_clean_css_identifier(strtolower($sex->name));
?>

<ul class="breadcrumbs">
    <li class="first"><a href="<?php print $clothing_type_path;?>"><?php print strtolower($sex->name);?></a></li><?php
foreach (array($clothing_type_parent, $clothing_type) as $term)
{
    if (!$term) continue;
    $name = strtolower($term->name);
    $clothing_type_path .= '/' . drupal_clean_css_identifier($name);
    print '<li>';
    print '<a href="'.$clothing_type_path.'">'.$name.'</a>';
    print '</li>';
}
?><li class="last"><a href=""><?php print $title;?></a></li>
</ul>

<div class="social-share">
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.4";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>
<div class="fb-share-button" data-layout="button"></div>

<a href="https://twitter.com/share" class="twitter-share-button" data-via="heybabies" data-count="none" data-hashtags="heybabies" data-dnt="true">Tweet</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+'://platform.twitter.com/widgets.js';fjs.parentNode.insertBefore(js,fjs);}}(document, 'script', 'twitter-wjs');</script>

<a href="//www.pinterest.com/pin/create/button/" data-pin-do="buttonBookmark" ><img src="//assets.pinterest.com/images/pidgets/pinit_fg_en_rect_gray_20.png" /></a>
<script type="text/javascript" async defer src="//assets.pinterest.com/js/pinit.js"></script>
</div>

<?php
print views_embed_view('product_node', 'block', $node->nid);
print views_embed_view('related_products', 'block', $node->nid, $sex->tid, $clothing_type_parent_tid);
?>
