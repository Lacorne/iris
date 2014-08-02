'use strict';

/**
 * Configuration and logic for all the grunt tasks.
 * @param  {[type]} grunt [description]
 * @return {[type]}       [description]
 */
module.exports = function(grunt) {

  // Project configuration.
  grunt.initConfig({
    pkg : grunt.file.readJSON('package.json'),
    dirs: grunt.file.readJSON('package.json').directories,
    conf: grunt.file.readJSON('package.json').config,
    ft  : grunt.file.readJSON('package.json').filetypes,

    /**
     * Announcer
     * @type custom multitask
     */
    announce: {
      csslint: {
        title: "------------------------= CSSLint    =------------------------",
        manifest: "Will hurt your feelings... (And help you code better)."
      },
      stylus: {
        title: "------------------------= Stylus     =------------------------",
        manifest: "CSS needed a Heroe !"
      }
    },

    /**
     * CSSLint
     * @type task
     */
    csslint: {
      site: {
        options: {
          csslintrc: '<%= conf.csslintrc %>'
        },
        src:['<%= dirs.dest.siteCss %>/<%= ft.css %>']
      }
    },

    /**
     * Stylus
     * @type task
     */
    stylus: {
      // Dev release with line numbers and stuffs to help: for site
      devSite: {
        options: {
          compress: false,
          linenos: true,
          use: [
            require('nib')
          ],
          paths: [
            './node_modules',
            '<%= dirs.src.siteStylus %>'
          ],
          banner: '<%= conf.banner %>'
        },
        files: [{
          expand: true,
          cwd: '<%= dirs.src.siteStylus %>/',
          src: [ '*.styl'],
          dest: '<%= dirs.dest.css %>/',
          ext: '.css'
        }]
      },

      // Distribution release with minimal stuffs: for site
      distSite: {
        options: {
          paths: [
            './node_modules',
            '<%= dirs.src.siteStylus %>'
          ],
          use: [
            require('nib')
          ],
          banner: '<%= conf.banner %>'
        },
        files: [{
          expand: true,
          cwd: '<%= dirs.src.siteStylus %>/',
          src: [ '*.styl'],
          dest: '<%= dirs.dest.css %>/',
          ext: '.min.css'
        }]
      }
    },

    watch: {
      options: {
        livereload: true,
      },
      stylusSiteDev: {
        files: ['<%= dirs.src.siteStylus %>/*.styl', '<%= dirs.src.libStylus %>/**/*.styl'],
        tasks: ['announce:stylus', 'stylus:devSite'/*, 'announce:csslint', 'csslint:site'*/],
      },
      stylusSiteDist: {
        files: ['<%= dirs.src.siteStylus %>/*.styl', '<%= dirs.src.libStylus %>/**/*.styl'],
        tasks: ['announce:stylus', 'stylus:distSite'/*, 'announce:csslint', 'csslint:site'*/],
      }
    }

  });

  // Load the plugin
  require('matchdep').filterDev('grunt-*').forEach(grunt.loadNpmTasks);

  // Default task(s).
  grunt.registerTask('default', ['watch']);
  // Separate dist tasks
  grunt.registerTask('sitecss:dist', ['watch:stylusSiteDist']);

  // Separate dev tasks
  grunt.registerTask('sitecss:dev', ['watch:stylusSiteDev']);


  /**
   * =============================================================================
   *                                 Custom Tasks
   * =============================================================================
   */

  /**
   * Shout a task title and manifest stored in his conf.
   */
  grunt.registerMultiTask('announce', 'Announce stuff.', function() {
    var
      title = grunt.log.wraptext(80,this.data.title),
      manifest = grunt.log.wraptext(80, this.data.manifest)
    ;
    if(title.length){
      grunt.log.subhead(title);
    }
    if(manifest.length){
      grunt.log.writeln(manifest);
    }
  });
};