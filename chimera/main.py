""" Determine how much currency we have for each category. Each unit
of currency should also have its usefullness as attributes. Then,
to the most needed category, assign the least useful token. """

fr = open('chimin.txt', 'r')
length = int(fr.readline())
lion = []
for x in range(length):
    lion.append(fr.read(1))
fr.read(1)
snake = []
for x in range(length):
    snake.append(fr.read(1))
fr.read(1)
goat = []
for x in range(length):
    goat.append(fr.read(1))
fr.close()

available_lower = list()
available = list()
used = list()
chimera = list()
for x in range(length):
    chimera.append('null')
    used.append('empty')
    available.append('')
    available_lower.append('')

for x in range(length):
    if lion[x] == snake[x] and snake[x] == lion[x]:
        chimera[x] = lion[x]
        used[x] = 'used'

for x in range(length):
    if used[x] != 'used':
        available[x] += str(snake[x])
        available[x] += str(goat[x])
        available[x] += str(lion[x])

for x in range(length):
    a = available[x]
    available_lower[x] = a.lower()

print(available_lower)


def determine_score(animal):
    score = 0
    for x in range(length):
        if chimera[x] == animal[x]:
            score += 1
    return score


def get_lowest_animal(snake, goat, lion):
    d = {}
    d['snake'] = determine_score(snake)
    d['goat'] = determine_score(goat)
    d['lion'] = determine_score(lion)
    return min(d, key=d.get)


def not_finished(chimera):
    not_finished = False
    for x in chimera:
        if x == 'null':
            not_finished = True
    return not_finished


def add_gene(animal):
    for x in range(length):
        if chimera[x] == 'null':
            if animal[x] in available_lower[x]:
                chimera[x] = animal[x]
            else:
                chimera[x] = available[x][0]
                break


while (not_finished(chimera)):
    add_gene(get_lowest_animal(snake, goat, lion))


def get_lowest_score(chimera):
    lower_chimera = list()
    for x in range(length):
        lower_chimera.append('')
    for x in range(length):
        lower = chimera[x]
        lower_chimera[x] = lower.upper()
    print(lower_chimera)
    lion_score = 0
    snake_score = 0
    goat_score = 0
    for x in range(length):
        if lower_chimera[x] == lion[x]:
            lion_score += 1
            print('match')
        if lower_chimera[x] == snake[x]:
            snake_score += 1
            print('snake match')
        if lower_chimera[x] == goat[x]:
            goat_score += 1
            print('goat match')
    return min(goat_score, lion_score, snake_score)

lowest_score = get_lowest_score(chimera)
fw = open('chimout.txt', 'w')
fw.write(str(lowest_score))
fw.close()
