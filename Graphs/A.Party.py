from sys import stdin, stdout
n = int(stdin.readline())

from collections import defaultdict
adj = defaultdict(list)
start = []
for i in range(1,n+1):
    x = int(stdin.readline())
    if x==-1:
        start.append(i)
        continue
    adj[i].append(x)
    adj[x].append(i)
q = []
for x in start:
    q.append(x)

vis = set()
group = 0
while len(q):
    size = len(q)
    for i in range(size):
        front = q.pop(0)
        # stdout.write("{} ".format(front))
        vis.add(front)
        for node in adj[front]:
            if node not in vis:
                q.append(node)
    group+=1
stdout.write("{}\n".format(group))
