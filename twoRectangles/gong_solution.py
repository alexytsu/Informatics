fin = open('bendin.txt', 'r')
fout = open('bendout.txt', 'w')

rec1 = fin.readline().strip().split(' ')
rec2 = fin.readline().strip().split(' ')

a=int(rec1[0])
b=int(rec1[1])
c=int(rec1[2])
d=int(rec1[3])
e=int(rec2[0])
f=int(rec2[1])
g=int(rec2[2])
h=int(rec2[3])

rec1 = [a, b, c, d]
rec2 = [e, f, g, h]

def area(rec):
    return (rec[2] - rec[0]) * (rec[3] - rec[1])

overcount = area(rec1) + area(rec2)

overrec = [sorted([a, c, e, g])[1], sorted([b, d, f, h])[1],
           sorted([a, c, e, g])[2], sorted([b, d, f, h])[2]]
overlap = area(overrec)

if a<e and b<f:
    #rec1 bottom left
    if e>c or f>d:
        #definitely none
        overlap = 0
else:
    #rec2 bottom left
    if b>h or a>g:
        overlap = 0
result = overcount - overlap
fout.write('%d\n' % (result))

fin.close()
fout.close()