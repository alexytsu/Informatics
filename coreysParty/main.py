fr = open('partyin.txt', 'r')
params = fr.readline().split()
params = [int(i) for i in params]
friendships = []
for x in range(params[1]):
    me = fr.readline().split()
    me = [int(i) for i in me]
    friendships.append(me)
fr.close()


