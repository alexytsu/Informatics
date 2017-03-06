fr = open("farmin.txt", "r")
fw = open("farmout.txt", "w")
fw.write(str(int(fr.readline())-1))
fr.close()
fw.close()

