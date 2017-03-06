fr = open('sitin.txt', 'r')
rows, seats, people = fr.read().split()
fr.close()
rows, seats, people = int(rows), int(seats), int(people)
totalSeats = rows*seats
fw = open('sitout.txt'     , 'w')
if totalSeats < people:
    fw.write(str(totalSeats))
    fw.write(" " + str(people-totalSeats))
    fw.close()
else:
    fw.write(str(people)+ " 0")