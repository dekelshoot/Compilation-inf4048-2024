# Compilation-inf4048-2024

Compilation-inf4048-2024

# L’implémentation de l'automate

Pour résumer le design que nous avons choisi, un automate est représenté par la classe DFA, qui va contenir :

- Un alphabet (représenté par une chaîne de caractères).
- Une liste d’états, qui seront représentés par leur nom.
- Une liste d’états initiaux, qui seront représentés par leur nom.
- Une liste d’états finaux, encore une fois leurs noms.
- Les transitions, représentés par un dictionnaire associant une chaîne de caractère (le nom de l’état d’origine), avec une paire symbole / état-cible.

# Comment imprimer un automate

Un fichier dot peut ensuite être simple transformé en image à l’aide de divers outils, notamment **Graphviz**. Cette collection d’outils est installée par défaut sur beaucoup de distributions Linux, sinon essayez de trouver le paquet correspondant ( `sudo apt install graphviz`). Pour créer une image PNG à partir du fichier DOT : `dot -Tpng *aaba*.dot -o *aaba*.png`.
