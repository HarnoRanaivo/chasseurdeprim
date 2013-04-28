chasseurdeprim
==============

Chasseur de Prim, projet de SDA2 (Structures de Données et Algorithmique 2), L2S4, Université de Strasbourg.
Recherche d'arbres couvrants minimum d'un graphe non orienté et connexe à l'aide de l'algorithme de Prim.

Télécharger et compiler « Chasseur de Prim »
--------------------------------------------
### Pré-requis ###
Tout d'abord, il vous faudra les outils standards de développement GNU, ainsi que git. Pour Ubuntu :
````
apt-get install build-essentials git-core
````

### Récupérer le projet ###
Pour récupérer le projet dans le dossier de votre choix :
````
git clone git://github.com/remove/chasseurdeprim.git [dossier]
````
Ensuite, pour récupérer les changements :
````
git pull
````

### Compiler ###
Un makefile est fourni, il vous suffit de vous placer à la racine du projet et de lancer make :
````
make
````

Lancer Chasseur de Prim
-----------------------
Une fois le programme compilé, il suffit de lancer le binaire disponible dans ```bin``` :
````
ledit bin/main
````
```ledit``` est optionnel, ce programme permet d'obtenir un prompt plus agréable (historique, complétion des noms de fichiers, ...). Pour obtenir de l'aide, entrez la commande ```aide```. Pour quitter le programme, entrez la commande ```quitter``` ou ```q```, puis confirmez votre décision par ```oui```.

Documentation
-------------
Chasseur de Prim est documenté à l'aide de Doxygen. Pour installer doxygen sur Ubuntu :
````
apt-get install doxygen
````
Un ```Doxyfile``` est déjà présent. Il suffit de lancer ```doxygen``` pour générer la documentation. Celle-ci sera disponible dans le dossier ```doc```.
````
doxygen
````
La documentation est également disponible [ici](http://remove.github.io/chasseurdeprim "Documentation").

Tests
-----
La branche ````test```` contient des tests unitaires qui nécéssitent la bibliothèque [CUnit](http://cunit.sourceforge.net/ "CUnit Testing Framework for C"). Des paquets sont disponibles dans les dépots d'Ubuntu :
````
apt-get install libcunit1 libcunit1-dev libcunit1-doc
````
Pour passer dans la branche ````test````, compiler et éxécuter les tests :
````
git checkout test
cd test
make
bin/main
````
Pour revenir dans la branche principale :
````
git checkout master
````

Branches
--------
Les versions stables se trouvent dans la branche ````master````, la branche ````dev```` contient la version de développement du projet, la branche ````test```` contient des tests unitaires. Pour passer d'une branche à l'autre :
````
git checkout <branche>
````

License
-------
Copyright © 2013 Harenome RAZANAJATO, Jérémy MEYER

Ce projet est libre. Vous pouvez le redistribuer ou le modifier selon les termes de la license « Do What The Fuck You Want To Public License », Version 2, comme publiée par Sam Hocevar. Pour de plus amples informations, veuillez vous référer au fichier COPYING, ou bien http://www.wtfpl.net/.
