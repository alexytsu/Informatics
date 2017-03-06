fr = open('magicin.txt', 'r')
param = fr.readline().split()
fr.close()

a = param[0]
b = param[1]
c = param[2]

rowa = [a, b, c]
rowb = [c, a, b]
rowc = [b, c, a]

fw = open('magicout.txt', 'w')
for x in rowa:
    fw.write(str(x)+" ")
fw.write("\n")
for x in rowb:
    fw.write(str(x)+" ")
fw.write("\n")
for x in rowc:
    fw.write(str(x)+" ")
fw.close()

