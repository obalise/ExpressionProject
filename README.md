# ExpressionProject


****************************************************************************************************************
Guide PROJET 6:

Fonction charger/sauvegarder (fichier) fonctionnelles depuis l'environnement Qt5.
Fonction affichage NC /NPI & calculer fonctionnelles:
pour une expression  2 opérande + 1 opérateur ou 3 opérande + 2 opérateur ou 4 opérande et 3 opérateur.

Ex: ( 5 + 8 ) ou ( 5 + 8 ) - 3 ) ou (( 5 + 8 ) - 3 ) / 4 

* Gestion des parenthèses à améliorer ==> ( 5 + 8 ) - ( 3 / 4) ne fonctionne pas

Pour tester il faut soit charger un fichier texte soit utiliser le menu saisie expression.

Dans l'ordre Saisie ou charger, sauvegarde l'expression puis affichage ou calcul

format attendu ( 5 + 2 ) (respecter les espaces entre chaque caractère).

Dernier point l'expression est disponible via un pointeur _monExpression

Image background:
Ajouter le dossier Image dans le reprtoire de debug (obtenu après la première compilation) 

Code commenté.

***************************************************************************************************************


Bienvenue jeune programmeur !!
Tu viens d'integrer le projet "Expression"!


SUJET : 

Il s’agit de traiter des expressions mathématiques simples de la forme ci-dessous en permettant de : 

- créer en mémoire ("en dur dans le code") une expression quelconque, 

- de calculer la valeur de cette expression, 

- d’afficher sur un flot de sortie (classe ostream) une représentation de l'expression (sous la forme d'une chaîne de caractères) en notation classique ou polonaise inversée. 

(5/2 + 4) * (-3 - 20) 

 

Dans cette première partie, les expressions que l'on souhaite traiter sont composées uniquement : 

- d'opérateurs arithmétiques : addition, soustraction, multiplication, division 

- de constantes flottantes.

ORGANISATION :

Chaque membre de ce projet a été affecté à un groupe de projet qui sera représenté par une branche qui représente votre environnement de travail.
J'essaierai par la suite en tant que modérateur de vous donner les droits d'écriture et de "merge" dans vos environnements.
Pour l'instant vous devrez me consulter avant de merger!
Bon courage à tous est très bientôt dans le code.