fr = open('tripin.txt', 'r')
discard = fr.readline()
numbers = fr.read().split()
fr.close()
numbers = list(map(int, numbers))

line = 0
counter = 0
positions = []
for x in numbers:
    line += 1
    if (x % 3) == 0:
        counter += 1
        positions.append(line)

fw = open('tripout.txt', 'w')

if counter == 0:
    fw.write('Nothing here!')
else:
    fw.write(str(counter)+'\n')
    for x in positions:
        fw.write(str(x) + ' ')

fw.close()

