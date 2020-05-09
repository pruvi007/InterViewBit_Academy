dx= [0,-1,-1,-1,0,1,1,1]
dy =[-1,-1,0,1,1,1,0,-1]
from sys import stdin, stdout
n = int(stdin.readline())
qx,qy = map(int,stdin.readline().split())
kx,ky = map(int,stdin.readline().split())
tx,ty = map(int,stdin.readline().split())
# obstacles = set()
# for i in range(8):
#     curX,curY = qx,qy
#     while 0<=curX<n and 0<=curY<n:
#         obstacles.add((curX,curY))
#         stdout.write("({},{}) ".format(curX,curY))
#         curX, curY = curX+dx[i], curY+dy[i]
#     print()
# ans = "NO"
# q = [[kx,ky]]
# vis = set()
# while len(q):
#     f = q.pop(0)
#     vis.add((f[0],f[1]))
#     if f[0]==tx and f[1]==ty:
#         ans = "YES"
#         break
#     for i in range(8):
#         nx,ny = f[0]+dx[i],f[1]+dy[i]
#         if 0<=nx<n and 0<=ny<n and (nx,ny) not in obstacles and (nx,ny) not in vis:
#             q.append([nx,ny])
#             vis.add((nx,ny))
ans = "YES"
if (tx>qx and kx<qx) or (tx<qx and kx>qx):
    ans = "NO"
if (ty>qy and ky<qy) or (ty<qy and ky>qy):
    ans = "NO"
stdout.write("{}\n".format(ans))