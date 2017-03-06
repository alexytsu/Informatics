#takes two numbers from addin.txt and outputs their sum to addout.txt

fr = open('addin.txt', 'r')
numbers = fr.read().split()
sum =str(int(numbers[0]) + int(numbers[1]))
fr.close()

fw = open('addout.txt', 'w')
fw.write(sum)
fw.close()
