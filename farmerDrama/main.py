fr = open("farmin.txt", "r")
no = int(fr.readline())
land = fr.read().split()
land = [int(i) for i in land]
fr.close()

x = 0
while x <  no:
    ind1 = x
    ind2 = no-1-x
    if land[ind1] < land [ind2]:
        print("Pop!")
        land[ind1] = land[ind1] + land[ind1+1]
        land.pop(ind1 + 1)
        no -= 1
    x += 1

print(land)
fw = open("farmout.txt", "w")
fw.close()

