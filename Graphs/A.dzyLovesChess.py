


from sys import stdin, stdout
n,m = map(int,stdin.readline().split())
s = []
for i in range(n):
    l = stdin.readline().split('\n')[0]
    s.append(list(l))

dx = [-1,1,0,0]
dy = [0,0,1,-1]
vis = set()

def bfs(s,si,sj,vis):
    q = [[si,sj,'B']]
    while len(q):
        f = q.pop(0)
        x,y,color = f[0],f[1],f[2]
        vis.add((x,y))
        s[x][y] = color
        for j in range(4):
            nx,ny = x+dx[j],y+dy[j]
            if 0<=nx<len(s) and 0<=ny<len(s[0]) and (nx,ny) not in vis and s[nx][ny]=='.':
                if color == 'B':
                    q.append([nx,ny,'W'])
                else:
                    q.append([nx,ny,'B'])
                vis.add((nx,ny))              
        

for i in range(n):
    for j in range(m):
        if s[i][j]=='.' and (i,j) not in vis:
            bfs( s,i,j,vis )

for i in range(n):
    stdout.write("{}\n".format(''.join(s[i])))