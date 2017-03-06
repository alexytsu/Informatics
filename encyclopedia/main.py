fr = open('encyin.txt', 'r')
params = fr.readline().split()
params = list(map(int, params))

index = []
for x in range(params[0]):
    index.append(int(fr.readline()))

questions = []
for x in range(params[1]):
    questions.append(int(fr.readline()))

fr.close()

fw = open('encyout.txt', 'w')
for x in questions:
    fw.write('%d\n' % index[x-1])

fw.close()

