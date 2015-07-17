<?php
print '<div class="background" style="background-image: url('.$fields['field_image_background']->content.');"><div><div>';

foreach ($fields as $id => $field)
{    
    if ($id == 'field_image_background')
    {
        continue;
    }
    
    if (!empty($field->separator))
    {
        print $field->separator;
    }
    print $field->wrapper_prefix;
    print $field->label_html;
    print $field->content;
    print $field->wrapper_suffix;
}

print '</div></div></div>';
?>