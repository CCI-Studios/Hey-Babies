<?php
drupal_add_library('slick', 'slick');
drupal_add_js(drupal_get_path('theme', 'heybabies').'/js/jquery.zoom.min.js');
drupal_add_js(drupal_get_path('theme', 'heybabies').'/js/details.js');

$title = strtolower($title);
$product_id = $node->field_product['und'][0]['product_id'];
$product = commerce_product_load($product_id);
$sex = strtolower($product->field_sex['und'][0]['taxonomy_term']->name);
$clothing_type = $product->field_clothing_type['und'][0]['taxonomy_term'];
$clothing_type_parents = taxonomy_get_parents($clothing_type->tid);
$clothing_type_parent = (empty($clothing_type_parents)) ? FALSE : current($clothing_type_parents);
$clothing_type_path = '/'.drupal_clean_css_identifier($sex);

?>

<ul class="breadcrumbs">
    <li class="first"><a href="<?php print $clothing_type_path;?>"><?php print $sex;?></a></li><?php
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

<?php
print views_embed_view('product_node', 'block', $node->nid);
?>
