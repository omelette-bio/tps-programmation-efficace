sum = 0
f = open("zob.txt")
j = 0
k = 0
opti = ["O0", "O1", "O2", "O3", "Os"]
res = dict()

for i in f.readlines():
    if j == 4:
        print(sum/4)
        res[opti[k]] = sum/4
        sum = 0
        k += 1
        j=0
    sum+=float(i)
    j+=1
res[opti[k]] = sum/4

for i in opti:
    print(i,"&",res[i],"&",res["O0"]/res[i])

print()
print("Partie a mettre dans le rapport : ")
print()
print("\\begin{center}")
print("\\begin{tabular}{ l|c|r }")
print("Taille de bloc & Moyenne temps globaux & Taux d'acceleration \\\\")
print("\\hline")

print("\\textbf{",opti[0],"} & \\textbf{",res[opti[0]],"} & \\textbf{1} \\\\")
for i in opti[1:]:
    print(i,"&",res[i],"&",res[opti[0]]/res[i],"\\\\")

print("\\end{tabular}")
print("\\end{center}")