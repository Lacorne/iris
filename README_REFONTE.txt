#update
Passage � D7.28 plus mise � jour des modules contrib.

# Gestion des modules
Les modules ont �t� r�organis�s de cette mani�re:
sites/all/modules
  - contrib: contient les modules contrib (de la communaut�), et ne doivent donc par cons�quent pas �tre modifi�s, sauf par des mises � jour provenant de la communaut�.
  - custom: contient les modules custom, par cons�quent susceptibles d'�tres modifi�s
  - features: contient les features (sauvegarde de configurations sous forme de fichiers)

Lors de la r�cup�ration, executer la commande drush cc all depuis la racine du site.
Drupal doit mettre � jour le nouveau chemin des modules contrib qui ont �t� d�plac�s.

#Nouveaux modules ajout�s
=> Pour des besoins de d�veloppement
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

#Modules mis � jour
- context: https://www.drupal.org/project/context
  Le module en place �tant en version beta ... La derni�re release a �t� install�e.
- jquery_update 7.x-2.2 vers 7.x-2.4
  => se rendre dans "admin/config/development/jquery_update", puis selectionner 1.5 dans la partie "Alternate jQuery version for administrative pages".
  => laisser 1.10 dans "Default jQuery Version".

#Nouveaux modules utilis�s:
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
Le module collapsibblock pr�sentait un bug JS avec l'utilisation de la derni�re version de jQuery.
Depuis jQuery 1.10, la fonction cookie est supprim�e.
Collapsiblock utilise cette fonction et retournait une erreur.
Le patch suivant � �t� utilis�:
https://www.drupal.org/node/1429956
Le #3.

#Content Type
Les nouveaux content type sont pr�sents sur Envol

#views
Les nouvelles views sont pr�sentes sur Envol

#Envol
Bdd cr��e: d7_envol
Dossier cr��: sites/all/iris.onera.envol

#Actions � faire:
Iris:
Activer le theme Iris et le mettre par d�faut
D�sactiver le module External Links
Cr�er un contenu de type "Page 2".
Mettre en titre "Le fil", et indiquer comme alias "lefil"
Aller dans "admin/config/system/site-information" et indiquer en page d'accueil "lefil"
Dans admin/config/development/jquery_update indiquer en default la 1.10 et indiquer 1.5 pour la version administration

Envol:
Activer le theme Envol et le mettre par d�faut
Dans modules, d�sactiver les modules core "overlay" et "Toolbar"
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
