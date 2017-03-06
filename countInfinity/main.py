fr = open('countin.txt', 'r')
input = int(fr.readline())
fr.close()

fw = open('countout.txt', 'w')

for i in range(input):
    fw.write(str(i+1)+'\n')
fw.close()


