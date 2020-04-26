def bfs(root):
    level = []
    q = [root]
    while len(q)>0:
        n = len(q)
        cur = []
        for i in range(n):
            x = q.pop(0)
            cur.append(x)
            if x.left:
                q.append(x.left)
            if x.right:
                q.append(x.right)
        level.append(cur)
    return level
        
def findCousinSum( root, key):
    level = bfs(root)
    # for l in level:
    #     print(l)
    parent = [-1,-1]
    s = 0
    present = False
    for i in range(len(level)):
        for j in range(len(level[i])):
            if (level[i][j].left and level[i][j].left.data==key) or (level[i][j].right and level[i][j].right.data==key):
                parent = [i,level[i][j]]
                break
    ind = parent[0]
    p = parent[1]
    for i in range(len(level[ind]) ):
        if level[ind][i]==p:
            continue
        else:
            if level[ind][i].left:
                present = True
                s += level[ind][i].left.data
            if level[ind][i].right:
                present = True
                s += level[ind][i].right.data
    if present:
        return s
    return -1