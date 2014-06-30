#update
Passage à D7.28 plus mise à jour des modules contrib.

# Gestion des modules
Les modules ont été réorganisés de cette manière:
sites/all/modules
  - contrib: contient les modules contrib (de la communauté), et ne doivent donc par conséquent pas être modifiés, sauf par des mises à jour provenant de la communauté.
  - custom: contient les modules custom, par conséquent susceptibles d'êtres modifiés
  - features: contient les features (sauvegarde de configurations sous forme de fichiers)

Lors de la récupération de cette récupération, executer la commande drush cc all depuis la racine du site.
Drupal doit mettre à jour le nouveau chemin des modules contrib qui ont été déplacés.

#Nouveaux modules ajoutés
=> Pour des besoins de développement
- features: https://www.drupal.org/project/features
- diff: https://www.drupal.org/project/diff
- strongarm: https://www.drupal.org/project/strongarm
- display suite: https://www.drupal.org/project/ds

=> Pour des besoins de fonctionnement du site
- superfish: https://www.drupal.org/project/superfish

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

#Liste des features
sites/all/modules/features/iris:
- iris_views

#Patch
Le module collapsibblock présentait un bug JS avec l'utilisation de la dernière version de jQuery.
Depuis jQuery 1.10, la fonction cookie est supprimée.
Collapsiblock utilise cette fonction et retournait une erreur.
Le patch suivant à été utilisé:
https://www.drupal.org/node/1429956
Le #3.

#Content Type
Modification du type de contenu actualités.
Ajout d'un champ catégorie (Podcast, ...)
Ajout d'un champ image (image remontée sur la home)
Ajout des view mode big img, small img (utilisés dans la vue "le fil").

#views
Création de la view "le fil" qui est un update + renommage de la vue "une2"
Dans cette vue, la page a été modifée pour afficher 2 attachements:
- First news: l'actualité la plus récente
- Sticky: l'actualité épinglée en haut des listes (la plus récente des épinglées).
Le type d'affichage est un rendered entity, afin d'afficher les view modes désirés (comportant les champs désirés, et les images dans leur bons formats grâce aux styles d'images.)

#Envol
Bdd créée: d7_envol
Dossier créé: sites/all/iris.onera.envol