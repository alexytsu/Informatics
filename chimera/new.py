fr = open('chimin.txt', 'r')
length = int(fr.readline())
lion = fr.read(length)
fr.read(1)
snake =fr.read(length)
fr.read(1)
goat = fr.read(length)
fr.read(1)
fr.close()

lion_score = 0
snake_score = 0 
goat_score = 0
chim_length = 0

for x in range(length):
    if lion[x] == goat[x] and goat[x] == snake[x]:
        lion_score += 1
        snake_score += 1
        goat_score += 1
        chim_length += 1
    elif lion[x] == goat[x]:
        lion_score += 1
        goat_score += 1
        chim_length += 1
    elif goat[x] == snake[x]:
        goat_score += 1
        snake_score += 1
        chim_length += 1
    elif lion[x] == snake[x]:
        lion_score += 1
        snake_score += 1
        chim_length += 1

while chim_length < length:
    if lion_score <= goat_score and lion_score <= snake_score:
        lion_score += 1
    elif goat_score <= lion_score and goat_score <= snake_score:
        goat_score += 1
    elif snake_score <= lion_score and snake_score <= goat_score:
        snake_score += 1
    chim_length += 1


def keepGoing(sc):
    if max(sc) > min(sc)+1:
        return True
    else:
        return False

"""if the max is like 2 above the min, take one from max and add one to min"""

scores = [lion_score, goat_score, snake_score]
while keepGoing(scores):
    lowest = min(scores)
    highest = max(scores)
    if lion_score == highest:
        lion_score -= 1
        if snake_score == lowest:
            snake_score += 1
        elif goat_score == lowest:
            goat_score += 1
    elif snake_score == highest:
        snake_score -= 1
        if goat_score == lowest:
            goat_score += 1
        elif lion_score == lowest:
            lion_score += 1
    elif goat_score == highest:
        goat_score -= 1
        if snake_score == lowest:
            snake_score += 1
        elif lion_score == lowest:
            lion_score += 1
    scores = [lion_score, goat_score, snake_score]



scores = [lion_score, goat_score, snake_score]
fw = open('chimout.txt', 'w')
fw.write(str(min(scores)))
fw.close()
