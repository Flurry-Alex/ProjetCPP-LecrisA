# ProjetCPP-LecrisA

## Etape 1
Créez une première classe Carte qui mémorisera les informations d’une carte : sa couleur et sa valeur. Utilisez deux énumérations pour cela. 
Créez une seconde classe CarteL héritée de la première qui contiendra en plus l’adresse d’une autre carte qui lui est liée. 
Définir les attributs en protected et décrire les méthodes de manipulation correspondantes en public. 

C'est ok !


## Etape 2
Se créer une bibliothèque d’outils (méthodes) permettant de manipuler un paquet de cartes. 
Pour cela se définir une convention de nommage des méthodes (Français, anglais, majuscule, minuscule,…). 
En plus des constructeurs/destructeurs, Il y aura au moins les méthodes suivantes :  
Assesseurs pour les données membres 
Ajouter une carte à la fin 
Prendre une carte dans le paquet 
Effectuer un mélange aléatoire 

C'est ok !


## Etape 3
Créer une classe Main qui va hériter de Paquet et qui contiendra en plus un numéro de joueur et une cagnotte (entier). 
Créer une classe Pile qui va hériter de Paquet et qui contiendra la couleur de la pile. 
Créer une classe Donne qui va gérer un tour de jeu. Elle contiendra entra 4 et 6 mains, 4 piles de couleurs différentes (pique, cœur, carreau, trèfle) et un pot (entier). 
Elle contiendra au moins les méthodes suivantes : 
Répartir les cartes en quatre mains. 
Créer les 4 piles. 
Tester si une carte peut aller sur une pile. 
Effectuer un mouvement d’une carte sur une pile. 
Démarrer un tour de jeu qui renvoie comme valeur 10%de la somme gagnée (par la banque) 

C'est ok !


## Etape 4
Faire jouer les 4 joueurs les uns après les autres. 
Le tour de jeu se déroule comme suit : 
Répartir les cartes entre les mains 
Chaque joueur à son tour va tester ses cartes pour voir si une carte est jouable. 
Si oui, il va la jouer. 
Si aucune carte n’est jouable, il va augmenter le pot de 1 diminuer la cagnotte du joueur de 1. 
Passer au joueur suivant jusqu’à ce qu’un joueur n’a plus de cartes. 
Ajouter le pot à la cagnotte du joueur gagnant (-10%) 
Supprimer toutes les cartes restantes 
Si un joueur est ruiné, le jeu s’arrête de lui-même, on peut aussi arrêter entre chaque tour ou voir si la banque fait crédit. 

C'est ok !


## Etape 5
Adaptez pour 5 ou 6 joueurs. 
Mettre les paramètres (nombre de cartes, difficulté du mélange dans un fichier). 
Créez une DB avec des joueurs, l’évolution de leur cagnotte en fonction des parties. 

C'est ok !


## Etape 6
Permettre aux joueurs de jouer réellement 
Permettre l’emploi de bots 

C'est ok !


# Pas terminé :
Diagramme UML
