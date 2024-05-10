import copy

class AEF:
    """
    un automate est représenté par la classe  AEF, qui va contenir :
    - Un alphabet (représenté par une liste de caractères).
    - Une liste d’états, qui seront représentés par leur nom.
    - Une liste d’états , qui seront représentés par leur nom.
    - Une liste d’états finaux, encore une fois leurs noms.
    - Les transitions, représentés par un dictionnaire associant 
    une chaîne de caractère (le nom de l’état d’origine)
    , avec une paire symbole / état-cible.
    """ 

    def __init__(self, alphabet):
        """ Initialisez l'automate à étas fini.
             @param l'alphabet de l'automate."""

        self.etats = []
        """ Liste de chaîne correspondant au nom des l'états.
            Les États sont toujours identifiés par leur nom."""
        self.transitions = {}
        """ Dictionnaire utilisant l'état src comme clé et le mappant à une liste de
             paire (etat_dest, symbole)."""     
        self.initial = []
        """ Une liste contenant le nom des états initiaux."""
        self.finals = []
        """ Une liste contenant le nom des états finaux. """
        
        self.alphabet = alphabet
        """ Une chaîne contenant tous les symboles de l'alphabet."""

    def ajout_etat(self, etat, final = False, initial = False):
        """ Ajoutez un nouvel état. Erreur d'impression si l'état existe déjà.
             @param etat: indique le nom du nouvel état.
             @param final: un booléen déterminant si l'état est
                 final"""
        if etat in self.etats:
            print("erreur : l'état '" + etat + "' existe déja..")
            return
        self.transitions[etat] = []
        self.etats.append(etat)
        if initial:
            self.initial.append(etat)
        if final:
            self.finals.append(etat)
    
    def symbole_valide(self, symbole):
        """ Renvoie vrai si le symbole fait partie de l'alphabet,
             faux sinon.
             @param symbole: le symbole à tester """
        if symbole not in self.alphabet: return False
        return True

    def etat_dest(self, etat_src, symbole):
        """ Rechercher la transition correspondant à l'état source spécifié
             et le symbole et renvoie l'état de destination. Si la transition fait
             n'existe pas, renvoie None.
             @param etat_src l'état source de la transition.
             @param symbol le symbole de la transition. """
        if etat_src not in self.etats:
            print("erreur : l'état '" + etat_src + "' n'est pas un état existant.")
            return
        for (s, etat_dest) in self.transitions[etat_src]:
            if s == symbole:
                return etat_dest
        return None

    def ajout_transition(self, etat_src, symbole, etat_dest):
        """ Ajoute une transition . Erreur d'impression si l'automate possède déjà un
            transition pour l’état source , le symbole spécifiés et l'état de destination.
            @param etat_src le nom de l'état source.
            @param symbole le symbole de la transition
            @param etat_dest le nom de l'état de destination."""
        if not self.symbole_valide(symbole):
            print("erreur : le symbole '" + symbole + "' ne fait pas partie de l'alphabet.")
            return
        if etat_src not in self.etats:
            print("erreur : l' état '" + etat_src + "' n'est pas un état existant.")
            return
        if etat_dest not in self.etats:
            print("erreur : l'état '" + etat_dest + "' n'est pas un état existant.")
            return

        if((symbole, etat_dest) in self.transitions[etat_src]):
            print("erreur : la transition (" + etat_src + ", " + symbole + ", "+etat_dest+ ") existe déja.")
            return
        # if self.etat_dest(etat_src, symbole) != None:
        #     print("erreur : la transition (" + etat_src + ", " + symbole + ", ...) existe déja.")
        #     return

        self.transitions[etat_src].append((symbole, etat_dest))


    def __str__(self):
        """
        surcharger de l'opération d'afficharge__str__  
        de manière à avoir possibilité d’afficher nos automates 
        """
        print(self.alphabet)
        afficharge = "AEF :\n"
        afficharge += "   - alphabet   : '" + str(self.alphabet) + "'\n"
        afficharge += "   - initial       : " + str(self.initial) + "\n"
        afficharge += "   - finals     : " + str(self.finals) + "\n"
        afficharge += "   - états (%d) :\n" % (len(self.etats))
        for etat in self.etats:
            afficharge += "       - (%s)" % (etat)
            if len(self.transitions[etat]) == 0:
                afficharge += ".\n"
            else:
                afficharge = afficharge + ":\n"
                for (symbole, etat_dest) in self.transitions[etat]:
                    afficharge = afficharge + "          --(%s)--> (%s)\n" % (symbole, etat_dest)
        return afficharge
    
    def clone(self):
        """ Renvoie une copie du AEF.
            permet de faire une copie (complète) de l’automate :"""
        a = AEF(self.alphabet)
        a.etats = self.etats.copy()
        a.initial = self.initial
        a.finals = self.finals
        a.transitions = copy.deepcopy(self.transitions)
        return a
    
    def est_un_mot_accepte(self, mot, details = False):
        """ Exécute le AEF spécifié sur un mot et renvoie True si le mot est
             accepté.
             @param mot: le mot à tester.
             @param details si True, plus d'informations sont affichées sur l'
             exécution.
             @return True si le mot est accepté, False sinon.
        """
        if self.initial == None:
            print("erreur : l'automate ne possède aucun symbole initial.")
            return False
        
        aefd = self.determinisation()
        print(aefd)
        etat_courant = aefd.initial[0]

        i = 0
        for symbole in mot:
            if details : print("configuration : (" + etat_courant + ", " + mot[i:] + ")")
            if not aefd.symbole_valide(symbole):
                print("erreur : le symbole '" + symbole + "' ne fait pas partie de l'alphabet "+ str(aefd.alphabet))

            etat_suivant = aefd.etat_dest(etat_courant, symbole)
            if etat_suivant is None:
                if details: print("aucune transition disponible pour (" + etat_courant + ", " + symbole + ").")
                return False

            etat_courant = etat_suivant
            i = i+1

        if etat_courant in aefd.finals:
            if details: print(" se terminant à l'état final '" + etat_courant + "'.")
            return True
        if details: print("se terminant par un état non acceptant '" + etat_courant + "'")
        return False
    
    def determinisation(self):
        """
        aefd signifi automate à état fini déterministe

        retoune l'automate déterminiser de this
        il déterminise en suivant les étapes suivantes:
            - construction de la table de transition
            - réunion des états initiaux
            - rajouter dans la tables de transition les transition de la nouvelle réunion
            - pour chaque nouvelle nouvelle état, efectuer l'étape 3 jusqu'il n y ait plus de nouvelle état
            - l'état initial est le rassemblement des états initiaux
            - les états finaux contienent l'ensemble des états finaux
        """
        #réunir les états initiaux
        new_transition = {}
        new_etats= [str(self.initial)]
        temp_etats= [str(self.initial)]

        #on éffectue les transition des états initiaux et les transitions des nouvelles états
        #jusqu'a ce que on ait plus de nouvelle état
        while len(temp_etats)!=0:
            etats = eval(temp_etats[0])
            temp_etats.remove(str(etats))
            new_transition[str(etats)] = {}
            for symbole in self.alphabet:
                    new_transition[str(etats)][symbole] = []
            for etat in etats:
                for symbole in self.alphabet:
                    for (s, etat_dest) in self.transitions[etat]:
                        if s == symbole:
                            new_transition[str(etats)][symbole].append(etat_dest)
            
            for key in new_transition[str(etats)].keys():
                if str(new_transition[str(etats)][key]) not in new_etats :
                    if  new_transition[str(etats)][key]!=[]:
                       
                        new_etats.append(str(new_transition[str(etats)][key]))
                        temp_etats.append(str(new_transition[str(etats)][key]))
        
        #construction du nouvelle automate
        etats_renomes = [str(x) for x in range(1,len(new_etats)+1)]
        aefd = AEF(self.alphabet)
        #ajout des états
        for etats in new_etats:
            # ajout de l'état initial
            if self.initial == eval(etats):
                for etat in eval(etats):
                    if etat in self.finals and etats_renomes[new_etats.index(etats)] not in aefd.initial:
                        aefd.ajout_etat(etats_renomes[new_etats.index(etats)],initial=True, final=True)
                        break
                    
                if etats_renomes[new_etats.index(etats)] not in aefd.initial:
                    aefd.ajout_etat(etats_renomes[new_etats.index(etats)],initial=True)
            # ajout des états finaux
            for etat in eval(etats):
                if etat in self.finals:
                    if etats_renomes[new_etats.index(etats)] not in aefd.finals:
                        aefd.ajout_etat(etats_renomes[new_etats.index(etats)],final=True)
            #ajout des autres états
            if etats_renomes[new_etats.index(etats)] not in aefd.etats:
                        aefd.ajout_etat(etats_renomes[new_etats.index(etats)])
        
        #ajout des transitions
        for key in new_transition.keys():
            for ke in new_transition[key].keys():
                if new_transition[key][ke] != []:
                    aefd.ajout_transition(etats_renomes[new_etats.index(key)],ke,etats_renomes[new_etats.index(str(new_transition[key][ke]))])
        return aefd
    
    def minimisation(self):
        """
        minimisation retourne l'automate minimisé

        elle s'exécute en respectant les étapes suivantes:
        - Elimination des états inaccessibles(en utilisant l'algorithme de marquage)
        - regrouper les états congruent(appartenent à la même classe d'équvalence)
        """
        #élimination des états inaccessibles
        new_transition = {}
        new_etats = copy.copy(self.initial)
        temp_etats = copy.copy(self.initial)
        while len(temp_etats)!=0:
            etat = temp_etats[0]
            temp_etats.remove(etat)
            new_transition[etat] = {}
            for symbole in self.alphabet:
                new_transition[str(etat)][symbole] = ""
            for symbole in self.alphabet:
                for (s, etat_dest) in self.transitions[etat]:
                    if s == symbole:
                        new_transition[etat][symbole]=etat_dest
            
            for key in new_transition[etat].keys():
                if new_transition[etat][key] not in new_etats :
                    if  new_transition[etat][key]!="":
                        new_etats.append(new_transition[etat][key])
                        temp_etats.append(new_transition[etat][key])
    
        #construction du nouvelle automate
        aefd = AEF(self.alphabet)
        #ajout des états
        for etat in new_etats:
            # ajout de l'état initial
            if etat in self.initial:
                if etat in self.finals:
                    aefd.ajout_etat(etat,initial=True, final=True)
                else:
                    aefd.ajout_etat(etat,initial=True)
            # ajout des états finaux
            if etat in self.finals:
                if etat not in aefd.etats:
                    aefd.ajout_etat(etat,final=True)
            #ajout des autres états
            if etat not in aefd.etats:
                aefd.ajout_etat(etat)
        
        #ajout des transitions
        for key in new_transition.keys():
            for ke in new_transition[key].keys():
                if new_transition[key][ke] != []:
                    aefd.ajout_transition(key, ke, new_transition[key][ke])
        # print(aefd)

        # creer deux classes d'équivalences
        A = aefd.finals.copy()
        B = list(set(aefd.etats)-set(A))

        new_transitions = []
        new_transition = {}
        classes = [A]
        for classe in classes:
            for etat in classe:
                new_transition[etat] = {}
                for symbole in aefd.alphabet:
                    new_transition[etat][symbole] = ""
                    for (s, etat_dest) in aefd.transitions[etat]:
                        if s == symbole:
                            new_transition[etat][symbole]=etat_dest
            print(new_transition)
            checker = True
            for symbole in aefd.alphabet:
                for key in new_transition.keys():
                    if new_transition[key][symbole] not in A:
                        checker = False
            if checker == True:
                new_transitions.append(new_transition)
        print(new_transitions)
        


