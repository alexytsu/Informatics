fr = open('listin.txt', 'r')
lines = int(fr.readline())
data = []
list = []
for x in range(lines):
    line = fr.readline().split()
    line = [int(i) for i in line]
    list.append(line)

print(list)
