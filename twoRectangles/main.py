fr = open('bendin.txt', 'r')
rect1 = fr.readline().split()
rect2 = fr.readline().split()
fr.close()

rect1 = [int(x) for x in rect1]
rect2 = [int(x) for x in rect2] 

aRect1 = (rect1[2] - rect1[0]) * (rect1[3] - rect1[1])
aRect2 = (rect2[2] - rect2[0]) * (rect2[3] - rect2[1])


def getAnswerIfOverlap():
    x = [rect1[0], rect1[2], rect2[0], rect2[2]]
    y = [rect1[1], rect1[3], rect2[1], rect2[3]]
    x.sort()
    y.sort()
    overlap = (x[2] - x[1]) * (y[2] - y[1])
    answer = aRect1 + aRect2 - overlap
    fw = open('bendout.txt', 'w')
    fw.write('%s' % answer)
    fw.close()


def determineIfOverlap():
    if (rect1[0] <= rect2[0]) & (rect1[2] >= rect2[0]):
        xOverlap = True
    elif (rect1[0] >= rect2[0]):
        xOverlap = True
    else:
        xOverlap = False

    if (rect1[1] <= rect2[1]) & (rect1[3] >= rect2[1]):
        yOverlap = True
    elif (rect1[1] >= rect2[1]):
        yOverlap = True
    else:
        yOverlap = False

    if xOverlap & yOverlap:
        return (True)
    else:
        return (False)

if determineIfOverlap():
    getAnswerIfOverlap()
else:
    answer = aRect1 + aRect2
    fw = open('bendout.txt', 'w')
    fw.write(str(answer))
    fw.close()
