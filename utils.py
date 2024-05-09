import AEF
from subprocess import call

def save(aef, filename):
    """ Enregistrez le AEF spécifié dans un fichier.
         Un AEF peut être lu avec la fonction « read ».
         @param aef le AEF à enregistrer
         @param filename le nom du fichier dans lequel
             l'automate sera sauvegardé."""
    txt = "a = AEF.AEF(\"" + str(aef.alphabet) + "\")\n"
    for etat in aef.etats:
        if etat in aef.finals:
            txt += "a.ajout_etat(\"" + etat + "\", True)\n"
        else:
            txt += "a.ajout_etat(\"" + etat + "\")\n"

    txt += "\na.initial = " + str(aef.initial)+ "\n\n"

    for etat in aef.etats:
        for (symbole, etat_dest) in aef.transitions[etat]:
            txt += "a.ajout_transition(\"" + etat + "\", \"" + symbole + "\", \"" + etat_dest + "\")\n"

    with open(filename, "w") as file:
        file.write(txt)

def read(filename):
    """ Lit le AEF spécifié à partir d'un fichier.
         Un AEF peut être enregistré avec la fonction « save ».
         @param filename le fichier dans lequel l' AEF est stocké.
         @renvoyez l' AEF du fichier.
        """
    local_dict = locals()
    with open(filename, "r") as file:
        exec(compile(open(filename).read(), filename, 'exec'), globals(), local_dict)

    return local_dict["a"]

def to_dot(aef, nom="Graph"):
    """ Renvoie une chaîne correspondant au AEF spécifié au format DOT.
         @param aef le AEF à convertir au format DOT.
         @param nom le nom de l'automate pour le fichier DOT ("Graph")
         par défaut.
         @renvoie l'automate au format DOT."""
    affichage = "digraph " + nom + " {\n    rankdir=\"LR\";\n\n"
    affichage += "    // States (" + str(len(aef.etats)) + ")\n"

    nom_etat = lambda s : "Q_" + str(aef.etats.index(s))

    # etats
    for etat in aef.initial:
        affichage += "    node [shape = point ];     __Q"+etat+"__ // Initial state\n" # Initial state
    for etat in aef.etats:
        affichage += "    "
        if etat in aef.finals:
            affichage += "node [shape=doublecircle]; "
        else:
            affichage += "node [shape=circle];       "
        affichage += nom_etat(etat) + " [label=" + etat + "];\n"

    # Transitions
    affichage += "\n    // Transitions\n"
    for etat in aef.initial:
        affichage += "    __Q"+etat+"__ -> " + nom_etat(etat) + "; // Initial state arrow\n"
    for etat in aef.etats:
        for (symbole, etat_dest) in aef.transitions[etat]:
            affichage += "    " + nom_etat(etat) + " -> " + nom_etat(etat_dest) + " [label=" + symbole + "];\n"
    return affichage + "}\n"

def to_png(aef, filename=None, nom="Graph"):
    """ Créez l'image PNG correspondant à la représentation du
         aef spécifié dans un fichier.
         L'automate est converti au format DOT et la commande dot est appelée
         afin de générer le PNG.
         @param aef: l'AEF à convertir en PNG.
         @param nom: le nom du graphique.
         @param filename: le nom du fichier PNG, utilisez le nom du graphique si
             non spécifié. """

    if filename is None:
        filename = nom + ".png"

    tmp_file = filename + ".tmp"
    with open(tmp_file, "w") as file:
        file.write(to_dot(aef, nom))

    call(("dot -Tpng " + tmp_file + " -o " + filename).split(" "))
    # call(("rm " + tmp_file).split(" "))


def to_pdf(aef, filename=None, nom="Graph"):
    """ Créez la représentation PDF graphique de l'aef spécifié dans un fichier.
         L'automate est converti au format DOT et la commande dot est appelée
         afin de générer le PDF.
         @param aef l'aef à convertir en PDF.
         @param nom le nom du graphique.
         @param filename le nom du fichier PDF, utilisez le nom du graphique si
             non spécifié."""

    if filename is None:
        filename = nom + ".pdf"

    tmp_file = filename + ".tmp"
    with open(tmp_file, "w") as file:
        file.write(to_dot(aef, nom))

    call(("dot -Tpdf " + tmp_file + " -o " + filename).split(" "))
    call(("rm " + tmp_file).split(" "))