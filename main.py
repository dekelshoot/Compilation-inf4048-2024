from AEF import AEF
import utils
a = AEF(['a','b'])

a.ajout_etat("1",initial=True, final=True)
a.ajout_etat("2",final=True)
a.ajout_etat("3")
a.ajout_etat("4")
a.ajout_etat("5")
a.ajout_etat("6")
a.ajout_etat("7")


a.ajout_transition("1", "a", "2")
a.ajout_transition("1", "b", "5")
a.ajout_transition("2", "a", "2")
a.ajout_transition("2", "b", "4")
a.ajout_transition("3", "a", "3")
a.ajout_transition("3", "b", "2")
a.ajout_transition("4", "a", "5")
a.ajout_transition("4", "b", "3")
a.ajout_transition("5", "a", "4")
a.ajout_transition("5", "b", "6")
a.ajout_transition("6", "b", "1")
a.ajout_transition("6", "a", "6")
a.ajout_transition("7", "a", "5")
a.ajout_transition("7", "b", "7")



# utils.save(a,"./save/11.aef")
# a=utils.read("./save/11.aef")

# utils.to_png(b,filename="./save/11.png",nom="aaa")
# utils.to_pdf(b,filename="./save/11.pdf",nom="aaa")
# a.est_un_mot_accepte("ababb", details=True)
# print(a)
# a.determinisation()
a.minimisation()
# print(a)
# utils.to_png(b,filename="./save/11d.png",nom="aaa")
