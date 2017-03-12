fr = open("surfin.txt", "r")
params = fr.readline().split()
params = [int(i) for i in params]
grid = fr.read().splitlines()


print(grid)
