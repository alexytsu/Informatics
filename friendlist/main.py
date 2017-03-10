fr = open('listin.txt', 'r')
param = fr.readline().split()
lines = int(param[0])
list = []
for i in range(lines):
    pair = fr.readline().split()
    pair = [int(i) for i in pair]
    list.append(pair)
fr.close()

data = []
for x in list:
    for i in x:
        data.append(i)

data.sort()

def getFreq(a):
    counter = 0
    for x in data:
        if(x==a):
            counter += 1
    return counter

unique = []

for x in data:
    if x not in unique:
        unique.append(x)

popular = []
mostPopular = 0

for x in unique:
    b = getFreq(x)
    if b > mostPopular:
        popular = [x]
        mostPopular = b
    elif b == mostPopular:
        popular.append(x)

print(x)

fw = open('listout.txt', 'w')
for x in popular:
    fw.write('%d\n' % x)

fw.close()
