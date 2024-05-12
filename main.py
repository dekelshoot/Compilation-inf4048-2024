from AEF import AEF
import utils
# a = AEF(['a','b'])

# a.ajout_etat("1",initial=True, final=True)
# a.ajout_etat("2",final=True)
# a.ajout_etat("3")
# a.ajout_etat("4")
# a.ajout_etat("5")
# a.ajout_etat("6")
# a.ajout_etat("7")


# a.ajout_transition("1", "a", "2")
# a.ajout_transition("1", "b", "5")
# a.ajout_transition("2", "a", "2")
# a.ajout_transition("2", "b", "4")
# a.ajout_transition("3", "a", "3")
# a.ajout_transition("3", "b", "2")
# a.ajout_transition("4", "a", "5")
# a.ajout_transition("4", "b", "3")
# a.ajout_transition("5", "a", "4")
# a.ajout_transition("5", "b", "6")
# a.ajout_transition("6", "b", "1")
# a.ajout_transition("6", "a", "6")
# a.ajout_transition("7", "a", "5")
# a.ajout_transition("7", "b", "7")



# utils.save(a,"./save/11.aef")
# print(a.est_coaccessible("7"))
# print(a.est_coaccessible("6"))
# print(a.emonde())

# a=utils.read("./save/11.aef")

# utils.to_png(a,filename="./save/11.png",nom="aaa")
# utils.to_pdf(b,filename="./save/11.pdf",nom="aaa")
# a.est_un_mot_accepte("ababb", details=True)
# print(a)
# a.determinisation()
# a.minimisation()
# print(a)
# utils.to_png(b,filename="./save/11d.png",nom="aaa")


# a = AEF(['a','b'])
# a.ajout_etat("0",initial=True)
# a.ajout_etat("1")
# a.ajout_etat("2")
# a.ajout_etat("3")
# a.ajout_etat("4",final=True)
# a.ajout_transition("0", "b", "0")
# a.ajout_transition("0", "a", "1")
# a.ajout_transition("1", "a", "2")
# a.ajout_transition("1", "b", "0")
# a.ajout_transition("2", "a", "2")
# a.ajout_transition("2", "b", "3")
# a.ajout_transition("3", "a", "4")
# a.ajout_transition("3", "b", "0")
# a.ajout_transition("4", "a", "4")
# a.ajout_transition("4", "b", "4")
# b=a.complementaire()
# utils.to_png(a,filename="./save/12com.png",nom="aaa")
# print(a.successors("1"))
# print(a.predecesseurs("2"))
# print(a.est_complet())
# print(a.accessible_states())

# a = AEF(["a","b","c"])
# a.ajout_etat("0", initial=True)
# a.ajout_etat("1")
# a.ajout_etat("2")
# a.ajout_etat("3", final=True)

# a.ajout_transition("0", "a", "1")
# a.ajout_transition("1", "b", "2")
# a.ajout_transition("2", "c", "3")
# a.ajout_transition("3", "c", "3")
# a.ajout_transition("3", "b", "3")
# a.ajout_transition("3", "a", "3")


# b = a.complete()
# utils.to_png(b,filename="./save/14.png",nom="aaa")


a = AEF(["a","b"])
a.ajout_etat("0", initial=True,final=True)
a.ajout_etat("1")

a.ajout_transition("0", "a", "1")
a.ajout_transition("0", "b", "0")
a.ajout_transition("1", "a", "0")
a.ajout_transition("1", "b", "1")

utils.to_png(a,filename="./save/15.png",nom="aaa")

b = AEF(["a","b","ε"])
b.ajout_etat("0", initial=True,final=True)
b.ajout_etat("1", final=True)
b.ajout_etat("2")

b.ajout_transition("0", "a", "0")
b.ajout_transition("0", "ε", "1")
b.ajout_transition("1", "a", "0")
b.ajout_transition("1", "b", "2")
b.ajout_transition("1", "b", "2")
b.ajout_transition("2", "a", "2")
b.ajout_transition("2", "b", "2")


utils.to_png(b,filename="./save/15_2.png",nom="aaa")

# p = a.intersection(b)
print(b.nature())

# utils.to_png(p,filename="./save/15_3.png",nom="aaa")