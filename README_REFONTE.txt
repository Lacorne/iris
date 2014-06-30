#update
Passage � D7.28 plus mise � jour des modules contrib.

# Gestion des modules
Les modules ont �t� r�organis�s de cette mani�re:
sites/all/modules
  - contrib: contient les modules contrib (de la communaut�), et ne doivent donc par cons�quent pas �tre modifi�s, sauf par des mises � jour provenant de la communaut�.
  - custom: contient les modules custom, par cons�quent susceptibles d'�tres modifi�s
  - features: contient les features (sauvegarde de configurations sous forme de fichiers)

Lors de la r�cup�ration de cette r�cup�ration, executer la commande drush cc all depuis la racine du site.
Drupal doit mettre � jour le nouveau chemin des modules contrib qui ont �t� d�plac�s.

#Nouveaux modules ajout�s
=> Pour des besoins de d�veloppement
- features: https://www.drupal.org/project/features
- diff: https://www.drupal.org/project/diff
- strongarm: https://www.drupal.org/project/strongarm
- display suite: https://www.drupal.org/project/ds

=> Pour des besoins de fonctionnement du site
- superfish: https://www.drupal.org/project/superfish

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

#Liste des features
sites/all/modules/features/iris:
- iris_views

#Patch
Le module collapsibblock pr�sentait un bug JS avec l'utilisation de la derni�re version de jQuery.
Depuis jQuery 1.10, la fonction cookie est supprim�e.
Collapsiblock utilise cette fonction et retournait une erreur.
Le patch suivant � �t� utilis�:
https://www.drupal.org/node/1429956
Le #3.

#Content Type
Modification du type de contenu actualit�s.
Ajout d'un champ cat�gorie (Podcast, ...)
Ajout d'un champ image (image remont�e sur la home)
Ajout des view mode big img, small img (utilis�s dans la vue "le fil").

#views
Cr�ation de la view "le fil" qui est un update + renommage de la vue "une2"
Dans cette vue, la page a �t� modif�e pour afficher 2 attachements:
- First news: l'actualit� la plus r�cente
- Sticky: l'actualit� �pingl�e en haut des listes (la plus r�cente des �pingl�es).
Le type d'affichage est un rendered entity, afin d'afficher les view modes d�sir�s (comportant les champs d�sir�s, et les images dans leur bons formats gr�ce aux styles d'images.)

#Envol
Bdd cr��e: d7_envol
Dossier cr��: sites/all/iris.onera.envol