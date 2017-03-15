# hold the number of fences in a counter
# checking from the outside in, subtract everytime a fence does not need to be removed

# setup
fr = open('farmin.txt', 'r')
n_plots = int(fr.readline())
plots = fr.read().split()
fr.close()
plots = [int(i) for i in plots]
rplots = plots[::-1]
fences = n_plots -1
kept = 0

remove = False

for x in range(len(rplots)):
    if rplots[x] != plots[x]:
         remove = True

fw = open('farmout.txt', 'w')
if remove:
    fw.write("1")
else: 
    fw.write("0")
fw.close()
