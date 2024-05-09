from AEF import AEF
import utils
a = AEF("ab")

a.ajout_etat("0")
a.ajout_etat("1")
a.ajout_etat("2")
a.ajout_etat("3")
a.ajout_etat("4", True)
a.initial = "0"

a.ajout_transition("0", "a", "1")
a.ajout_transition("0", "b", "0")
a.ajout_transition("1", "a", "2")
a.ajout_transition("1", "b", "0")
a.ajout_transition("2", "a", "2")
a.ajout_transition("2", "b", "3")
a.ajout_transition("3", "a", "4")
a.ajout_transition("3", "b", "0")
a.ajout_transition("4", "a", "4")
a.ajout_transition("4", "b", "4")

utils.save(a,"./save/test.aef")
a=utils.read("./save/test.aef")
utils.to_png(a,filename="./save/test.png",nom="aaa")
utils.to_pdf(a,filename="./save/test.pdf",nom="aaa")
