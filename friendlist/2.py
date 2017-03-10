fr = open('listin.txt', 'r')
lines = int(fr.readline())
list = fr.read().split()
friends = {}
for i in list:
    if i not in friends:
        friends[i] = 1
    else: 
        friends[i] += 1
fr.close()

max = 0
popular =  []

for k in friends:
    if friends[k] > max:
        popular = [k]
        max = friends[k]
        print("new max = ", max)
    elif friends[k] == max:
        popular.append(k)
        print("Appending k", k)

popular = [int(i) for i in popular]
popular.sort()
print(popular)

fw = open('listout.txt', 'w')
for x in popular:
    fw.write(str(x))
    fw.write("\n")

fw.close()
