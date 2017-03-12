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

def keepGoing():
    for x in range(len(rplots)):
        if rplots[x] != plots[x]:
            return True
    return False

while (keepGoing()):
    for x in range(len(rplots)):

