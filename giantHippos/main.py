fr = open('hippoin.txt', 'r')
params = fr.readline().split()
params = list(map(int, params))
positions = fr.read().split()
positions = list(map(int, positions))
fr.close()

tulips = params[0]
hippos = params[1]
fences = params[2]

for x in positions:
    print(x)
