fr = open('hippoin.txt', 'r')
numDaisies = int(fr.readline())
hippoPos = fr.read().split()
hippoPos = list(map(int, hippoPos))
fr.close()

daisyStatus = []
hippocount = 1
for x in range(numDaisies):
    pos = x + 1
    daisyStatus.append(pos)


def getGroups(daisyInitial):
    # four groups of daisies exist @@#@@#@@@#@@@
    groups = []
    g1 = hippoPos[0] - 1
    g2 = hippoPos[1] - hippoPos[0] - 1
    g3 = hippoPos[2] - hippoPos[1] - 1
    g4 = numDaisies - hippoPos[2]
    groups.append(g1)
    groups.append(g2)
    groups.append(g3)
    groups.append(g4)
    groups.sort()
    save1 = groups[3]
    if groups[3] == g1 or groups[3] == g4:
        save2 = groups[2]
    elif (groups[3] == g2) or (groups[3] == g3):
        save2 = max(g1, g4)
    totalSaved = save1 + save2
    return totalSaved


fw = open('hippoout.txt', 'w')
fw.write(str(getGroups(daisyStatus)))
fw.close()
