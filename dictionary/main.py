fr = open('dictin.txt', 'r')
params = fr.readline().split()
params = list(map(int, params))
int2whole  = {}

for x in range(params[0]):
    templist = fr.readline().split()
    int2whole[templist[0]] = templist[1]

queries = fr.read().split()
fr.close()

fw = open('dictout.txt', 'w')
for x in queries:
    if x in int2whole:
        fw.write(int2whole[x] + '\n')
    else:
        fw.write('C?\n')

fw.close()




