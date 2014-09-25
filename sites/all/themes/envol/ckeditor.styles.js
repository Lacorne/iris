/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [
            /* Inline Styles */

            {
                    name : 'Légende',
                    element : 'span',
                    attributes :
                    {
                            'class' : 'legende'
                    }
            },

            /* Object Styles */
            {
                    name : 'Renvois en bas de page',
                    element : 'div',
                    attributes :
                    {
                            'class' : 'renvois'
                    }
            },

            {
                    name : 'Image a gauche',
                    element : 'div',
                    attributes :
                    {
                            'class' : 'img-left'
                    }
            },

            {
                    name : 'Image a droite',
                    element : 'div',
                    attributes :
                    {
                            'class' : 'img-right'
                    }
            },

            {
                    name : 'Signature',
                    element : 'div',
                    attributes :
                    {
                            'class' : 'signature'
                    }
            }
    ]);
}