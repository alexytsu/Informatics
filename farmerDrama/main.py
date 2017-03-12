# hold the number of fences in a counter
# checking from the outside in, subtract everytime a fence does not need to be removed

# setup
fr = open('farmin.txt', 'r')
n_plots = int(fr.readline())
plots = fr.read().split()
fr.close()
plots = [int(i) for i in plots]
fences = n_plots -1

counter = 0
for x in range(n_plots):
    a = x
    b = n_plots - (x+1)
    if plots[a] == plots[b]:
        print(a,b)
        fences -= 1 
        counter += 1
    else:
        removed = 0
        for x in range(fences):

            

print(fences)
