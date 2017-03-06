fr = open('rainin.txt', 'r')
parameters = fr.readline().split()
rainfall = fr.read().split()
fr.close()
rainfall = list(map(int, rainfall))
capacity = int(parameters[1])
collected = 0
days = 0
for x in rainfall:
    if collected >= capacity:
        break
    days += 1 
    collected += x

fw = open('rainout.txt', 'w')
fw.write(str(days))
fw.close()

