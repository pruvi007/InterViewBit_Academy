def check(x,y,s):
    q = []
    q.append([x,y])
    vis = set()
    while len(q):
        f = q.pop(0)
        vis.add((f[0],f[1]))
        if s[f[0]][f[1]]=='S':
            return False
        for i in range(4):
            nx,ny = x+dx[i], y+dy[i]
            if 0<=nx<n and 0<=ny<m and s[nx][ny]!='D' and (nx,ny) not in vis:
                q.append([nx,ny])
    return True

from sys import stdin, stdout
n,m = map(int,stdin.readline().split())
s = []
for i in range(n):
    x = stdin.readline().split('\n')[0]
    s.append( list(x) )

dx, dy = [1,-1,0,0], [0,0,-1,1]
for i in range(n):
    for j in range(m):
        if s[i][j]=='W':
            for z in range(4):
                x,y = i+dx[z], j+dy[z]
                if 0<=x<n and 0<=y<m and s[x][y]=='.':
                    s[x][y] = 'D'


# for row in s:
#     print(''.join(row))

safe = True
for i in range(n):
    for j in range(m):
        if s[i][j]=='W':
            if not check(i,j,s):
                safe = False
                break
    if not safe:
        break


if safe:
    stdout.write("Yes\n")
    for i in range(n):
        stdout.write("{}\n".format(''.join(s[i])))
else:
    stdout.write("No\n")
