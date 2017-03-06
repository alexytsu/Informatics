fin = open("chimin.txt", "r")
length = int(fin.readline())


def determineGenome(animal):
    for x in range(length):
        animal.append(fin.read(1))
    fin.read(1)

lion = []
snake = []
goat = []
determineGenome(lion)
determineGenome(snake)
determineGenome(goat)
fin.close()

chimera = []
for x in range(length):
    chimera.append("N")

for x in range(length):
    if chimera[x] == "N":
        if 
