/*
Copyright (c) 2003-2012, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

CKEDITOR.editorConfig = function( config )
{
	// Define changes to default configuration here. For example:
	 config.language = 'fr';
	// config.uiColor = '#AADC6E';

 
      

   config.toolbar = 'MyToolbar_defaut';
    config.toolbar_MyToolbar_defaut =
    [    
    ['Bold','Italic','Underline','Strike','-'],
    config.toolbar = 'MyToolbar_user';

    ];
    config.toolbar_MyToolbar_user =
    [    
    ['Bold','Italic','Underline','Strike','-'],
    ['NumberedList','BulletedList','-','Outdent','Indent'],
    ['JustifyLeft','JustifyCenter'],
    ];


};
