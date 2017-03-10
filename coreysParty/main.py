## read in data
fr = open('partyin.txt', 'r')
params = fr.readline().split()
params = [int(i) for i in params]
friendships = []
for x in range(params[1]):
    me = fr.readline().split()
    me = [int(i) for i in me]
    friendships.append(me)
fr.close()

## generate dictionary of friends
friendlist = {}

for x in friendships:
    a = x[0]
    b = x[1]

    if a not in friendlist:
        friendlist[a] = [b]
    else:
        if b not in friendlist[a]:
            friendlist[a].append(b)
    if b not in friendlist:
        friendlist[b] = [a]
    else:
        if a not in friendlist[b]:
            friendlist[b].append(a)

## if person does not have enough friends(a), remove from consideration
a_req = params[2]

def keep_removing():
    for x in friendlist:
        if len(friendlist[x]) < a_req:
            return True
    return False 

while(keep_removing()):
    for x in friendlist:
        if len(friendlist[x]) < a_req:
            del friendlist[x]
            for y in friendlist:
                if x in friendlist[y]:
                    friendlist[y].remove(x)
            break

fw = open('partyout.txt', 'w')
fw.write(str(len(friendlist)))
fw.close()
