sum = 0
f = open("data.txt")
j = 0
k = 0
opti = ["ijk", "ikj", "jik", "jki", "kij", "kji"]
res = dict()

for i in f.readlines():
    if j == 4:
        print("moyenne des temps d'execution globaux de",opti[k],":",sum/4)
        res[opti[k]] = sum/4
        sum = 0
        k += 1
        j=0
    sum+=float(i)
    j+=1

res[opti[k]] = sum/4

print()
print("Partie a mettre dans le rapport : ")
print()
print("\\begin{center}")
print("\\begin{tabular}{ l|c|r }")
print("Niveau d'optimisation & Moyenne temps globaux & Taux d'acceleration \\\\")
print("\\hline")

for i in opti:
    print(i,"&",res[i],"&",res["ijk"]/res[i], "\\\\")

print("\\end{tabular}")
print("\\end{center}")