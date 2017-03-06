fr = open('dishin.txt', 'r')
items = int(fr.readline())
data = fr.read().split()
fr.close()

data = list(map(int, data))

total = sum(data)

low = min(data)
high = max(data)
mean = int(total/items)

fw = open('dishout.txt', 'w')
fw.write('%d %d %d' % (low, high, mean))
fw.close()


