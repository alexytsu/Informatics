fr = open('mixin.txt', 'r')
n, d = fr.read().split()
fr.close()
n, d = int(n), int(d)
b = n%d
a = int(n/d)
fw = open('mixout.txt', 'w')
if b==0:
    fw.write(str(a))
else:
    a = str(a)
    b = str(b)
    d = str(d) 
    fw.write(a + " " + b + "/" + d) 
