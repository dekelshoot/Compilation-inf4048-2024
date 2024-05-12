# Compilation-inf4048-2024

Compilation-inf4048-2024

# Explication du code

## L’implémentation de l'automate

l'implementation de l'automate est réalisée dans le ficier [AEF.py](./AEF.py)

> AEF signifie automate à états finis

Pour résumer le design que nous avons choisi, un automate est représenté par la classe DFA, qui va contenir :

- **aphabet**: Un alphabet (représenté par une chaîne de caractères).
- **etats**: Une liste d’états, qui seront représentés par leur nom.
- **initial**: Une liste d’états initiaux, qui seront représentés par leur nom.
- **finals**: Une liste d’états finaux, encore une fois leurs noms.
- **transition**: Les transitions, représentés par un dictionnaire associant une chaîne de caractère (le nom de l’état d’origine), avec une paire symbole / état-cible.

## Explication des fonctions de la classe AEF

### **init**(self, alphabet)

Initialisez l'automate à étas finis.\
@param l'alphabet de l'automate.

### ajout_etat(self, etat, final = False, initial = False):

Ajoutez un nouvel état. Erreur d'impression si l'état existe déjà.\
@param etat: indique le nom du nouvel état.\
@param final: un booléen déterminant si l'état est final

### symbole_valide(self, symbole):

Renvoie vrai si le symbole fait partie de l'alphabet,faux sinon.\
@param symbole: le symbole à tester

### etat_dest(self, etat_src, symbole):

Rechercher la transition correspondante à l'état source spécifié et le symbole et renvoie l'état de destination. Si la transition fait n'existe pas, renvoie None.\
@param etat_src l'état source de la transition.\
@param symbol le symbole de la transition.

### ajout_transition(self, etat_src, symbole, etat_dest):

Ajoute une transition . Erreur d'impression si l'automate possède déjà untransition pour l’état source , le symbole spécifiés et l'état de destination.\
@param etat_src le nom de l'état source.\
@param symbole le symbole de la transition\
@param etat_dest le nom de l'état de destination.

### **str**(self):

surcharger de l'opération d'afficharge**str** de manière à avoir possibilité d’afficher nos automates dans la console

### clone(self):

Renvoie une copie du AEF. permet de faire une copie (complète) de l’automate

### successeurs(self, etat):

Renvoie la liste des successeurs de l'état spécifié dans le AEF.\n
@param etat indique l'état considéré.\
@retourne la liste des successeurs de l'Etat.

### emonde(self):

Renvoie True si le DFA spécifié est émondé (accessible et coaccessible),Faux sinon.\
@return True si le DFA est émondé, False sinon.

### predecesseurs(self, etat):

Renvoie la liste des prédécesseurs de l'état spécifié dans le AEF.\
@param etat l'état considéré.\
@retourne la liste des prédécesseurs de l'état.

### complete(self):

Complète l'automate spécifié.\
@return True si l'AEF modifié.

### est_complet(self):

Renvoie True si l'automate est complet, False sinon.

### etats_accessibles(self):

Renvoie la liste de tous les états accessibles dans l'automate spécifié.\
@return True si la liste des états accessibles.

### est_accessible(self, etat):

Renvoie True si l'état spécifié est accessible dans l'automate, renvoie,Faux sinon.\
@param etat: indique l'état à tester.\
@return True si l'état est accessible, False sinon.

### accessible(self):

Renvoie True si le AEF spécifié est accessible (si tous ses états le sont accessible), Faux sinon.\
@return True si le AEF est accessible, False sinon.

### etats_coaccessibles(self):

Renvoie la liste de tous les états co-accessibles dans l'automate spécifié.\
@return True si la liste des états co-accessibles.

### est_coaccessible(self,etat):

Renvoie True si l'état spécifié est accessible dans l'automate, renvoie Faux sinon.\
@param etat: indique l'état à tester.\
@return True si l'état est coaccessible, False sinon.

### coaccessible(self):

Renvoie True si le AEF spécifié est coaccessible (si tous ses états accessible), Faux sinon.\
@return True si le DFA est coaccessible, False sinon.

### est_un_mot_accepte(self, mot, details = False):

Exécute le AEF spécifié sur un mot et renvoie True si le mot est accepté.\
@param mot: le mot à tester.\
@param details: si True, plus d'informations sont affichées sur l'exécution.\
@return True si le mot est accepté, False sinon.

### complementaire(self):

complementarise l'automate , qui reconnaît désormais le langage complementaire du AEF d'origine.\
@return True si le AEFC modifié.

### intersection(self, autre):

Renvoie un nouvel automate qui est le produit des deux AEF spécifiés (self ∩ autre ).\
@param autre le deuxième opérande du produit.\
@return True si le produit des deux AEF.

### renome_etat(self):

renome les états d'un automate\
@return l'AEF dont les états ont été renomés.

### est_deterministe(self)->bool:

permet de verifier si l'AEF est déterministe\
@return True si l'AEF est déterministe

### est_epsilone_non_deterministe(self):

permet de verifier si l'AEF est un ε-AFN \
@return True si l'AEF est un ε-AFN

### nature(self):

permet de determiner la nature d'un automate\
@return la nature de l'automate

### determinisation(self):

> aefd signifi automate à état fini déterministe

retoune l'automate déterminiser \
 il déterminise en suivant les étapes suivantes:

- construction de la table de transition
- réunion des états initiaux
- rajouter dans la table de transitions les transition de la nouvelle réunion
- pour chaque nouvelle nouvelle état, efectuer l'étape 3 jusqu'a ce qu'il n y ait plus de nouvelle état
- l'état initial est le rassemblement des états initiaux
- les états finaux contienent l'ensemble des états finaux

### distingue_partition(self, partitions: List[List[str]], partition: List[str])

Essayez de distinguer une partition d'état, en renvoyant la nouvelle partition générée par l'étape.\

:param partitions : la liste des partitions d'état.\
:type partitions : Liste[Liste[str]]
:param partition : les partitions à distinguer.\
:type partition : Liste[str]\
:return : la liste des nouveaux\
:rtype : Liste[Liste[str]]

### etats_equivalents(self)

Renvoie une liste contenant chaque groupe d'états équivalents.\
:return : une liste de listes d'états équivalents.\
:rtype : Liste[Liste[str]]

### minimise(self):

minimise l'automate spécifié (renvoie une copie).\
:retour : le AEF minimisé.

# Comment imprimer un automate

Un fichier dot peut ensuite être simple transformé en image à l’aide de divers outils, notamment **Graphviz**. Cette collection d’outils est installée par défaut sur beaucoup de distributions Linux, sinon essayez de trouver le paquet correspondant ( `sudo apt install graphviz`). Pour créer une image PNG à partir du fichier DOT : `dot -Tpng *aaba*.dot -o *aaba*.png`.
