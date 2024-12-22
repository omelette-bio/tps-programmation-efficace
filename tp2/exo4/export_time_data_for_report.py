sum = 0
f = open("data.txt")
j = 0
k = 0
# opti = ["base", "bloc_l1", "bloc_l2", "bloc_l3", "bloc_floop_block"]
# opti = ["bloc_l1_ijk", "bloc_l1_ikj", "bloc_l1_jik", "bloc_l1_jki", "bloc_l1_kij", "bloc_l1_kji"]
# opti = ["bloc_l2_ijk", "bloc_l2_ikj", "bloc_l2_jik", "bloc_l2_jki", "bloc_l2_kij", "bloc_l2_kji"]
opti = ["bloc_l3_ijk", "bloc_l3_ikj", "bloc_l3_jik", "bloc_l3_jki", "bloc_l3_kij", "bloc_l3_kji"]

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
print("\\begin{table}[H]")
print("\\centerline")
print("\\begin{tabular}{ l|c|r }")
print("Taille de bloc & Moyenne temps globaux & Taux d'acceleration \\\\")
print("\\hline")

print("\\textbf{",opti[0],"} & \\textbf{",res[opti[0]],"} & \\textbf{1} \\\\")
for i in opti[1:]:
    print(i,"&",res[i],"&",res[opti[0]]/res[i],"\\\\")

print("\\end{tabular}")
print("\\caption{}")
print("\\end{table}")