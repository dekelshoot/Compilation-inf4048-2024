from AEF import AEF
import utils
a = AEF(["a", "b","c"])

a.ajout_etat("1",initial=True)
a.ajout_etat("2",initial=True)
a.ajout_etat("3")
a.ajout_etat("4", final=True)


a.ajout_transition("1", "a", "1")
a.ajout_transition("1", "a", "3")
a.ajout_transition("2", "b", "2")
a.ajout_transition("2", "b", "3")
a.ajout_transition("3", "c", "3")
a.ajout_transition("3", "c", "4")


utils.save(a,"./save/1.aef")
a=utils.read("./save/1.aef")
utils.to_png(a,filename="./save/1.png",nom="aaa")
utils.to_pdf(a,filename="./save/1.pdf",nom="aaa")

b=a.determinisation()
print(b)
utils.to_png(b,filename="./save/1d.png",nom="aaa")
