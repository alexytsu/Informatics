fr = open('taktakin.txt', 'r')
input = int(fr.readline())
fr.close()
divisible = False
counter = 0

while divisible == False:
    if (input % 11) == 1:
        divisible = True
    else:
        input = input * 2
        counter = counter + 1

fw = open('taktakout.txt', 'w')
fw.write('%s %s' % (counter, input))
fw.close()
