#update
Passage à D7.28 plus mise à jour des modules contrib.

# Gestion des modules
Les modules ont été réorganisés de cette manière:
sites/all/modules
  - contrib: contient les modules contrib (de la communauté), et ne doivent donc par conséquent pas être modifiés, sauf par des mises à jour provenant de la communauté.
  - custom: contient les modules custom, par conséquent susceptibles d'êtres modifiés
  - features: contient les features (sauvegarde de configurations sous forme de fichiers)

Lors de la récupération, executer la commande drush cc all depuis la racine du site.
Drupal doit mettre à jour le nouveau chemin des modules contrib qui ont été déplacés.

#Nouveaux modules ajoutés
=> Pour des besoins de développement
- features: https://www.drupal.org/project/features
- diff: https://www.drupal.org/project/diff
- strongarm: https://www.drupal.org/project/strongarm
- display suite: https://www.drupal.org/project/ds
- field collection: https://www.drupal.org/project/field_collection
- wysiwyg_template: https://www.drupal.org/project/wysiwyg_template
- nodeblock: https://www.drupal.org/project/nodeblock

=> Pour des besoins de fonctionnement du site
- superfish: https://www.drupal.org/project/superfish
- flippy: https://www.drupal.org/project/flippy

#Modules mis à jour
- context: https://www.drupal.org/project/context
  Le module en place étant en version beta ... La dernière release a été installée.
- jquery_update 7.x-2.2 vers 7.x-2.4
  => se rendre dans "admin/config/development/jquery_update", puis selectionner 1.5 dans la partie "Alternate jQuery version for administrative pages".
  => laisser 1.10 dans "Default jQuery Version".

#Nouveaux modules utilisés:
- context
- superfish
- features
- diff
- strongarm
- transliteration
- display suite
- field collection
- nodeblock

#Liste des features
sites/iris.onera.accueil/modules/features:
- iris_config
- iris_contexts
- iris_views
sites/iris.onera.envol/modules/features:
- envol_config
- envol_contexts
- envol_views

#Patch
Le module collapsibblock présentait un bug JS avec l'utilisation de la dernière version de jQuery.
Depuis jQuery 1.10, la fonction cookie est supprimée.
Collapsiblock utilise cette fonction et retournait une erreur.
Le patch suivant à été utilisé:
https://www.drupal.org/node/1429956
Le #3.

#Content Type
Les nouveaux content type sont présents sur Envol

#views
Les nouvelles views sont présentes sur Envol

#Envol
Bdd créée: d7_envol
Dossier créé: sites/all/iris.onera.envol

#Actions à faire:
Iris:
Activer le theme Iris et le mettre par défaut
Désactiver le module External Links
Créer un contenu de type "Page 2".
Mettre en titre "Le fil", et indiquer comme alias "lefil"
Aller dans "admin/config/system/site-information" et indiquer en page d'accueil "lefil"
Dans admin/config/development/jquery_update indiquer en default la 1.10 et indiquer 1.5 pour la version administration

Envol:
Activer le theme Envol et le mettre par défaut
Dans modules, désactiver les modules core "overlay" et "Toolbar"
Dans admin/config/development/jquery_update indiquer en default la 1.10 et indiquer 1.5 pour la version administration

#Commandes Drush
Iris:
drush iris.onera.accueil en features
drush iris.onera.accueil en iris_config
drush iris.onera.accueil en iris_contexts
drush iris.onera.accueil en iris_views
drush iris.onera.accueil cc all -y -v

Envol:
drush iris.onera.envol en features
drush iris.onera.envol en envol_config
drush iris.onera.envol en envol_contexts
drush iris.onera.envol en envol_views
drush iris.onera.envol cc all -y -v
