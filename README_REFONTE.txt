# Modifications structurelles
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

#Liste des features
sites/all/modules/features/iris:
- iris_views

#Envol
Bdd créée: d7_envol
Dossier créé: sites/all/iris.onera.envol