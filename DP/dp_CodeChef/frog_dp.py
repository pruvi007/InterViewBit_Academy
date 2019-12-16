n,k,p = map(int,input().split())
a = list( map(int,input().split()) )
frog = [ [a[i],i+1] for i in range(len(a)) ]
frog = sorted(frog,reverse=True)
# print(frog)

max_dis = [0]*n
max_dis[frog[0][1]-1] = frog[0][0] + k
for i in range(1,n):
    if frog[i-1][0]-frog[i][0] <= k:
        max_dis[frog[i][1]-1] = max_dis[frog[i-1][1]-1]
    else:
        max_dis[frog[i][1]-1] = frog[i][0]+k

for i in range(p):
    x,y = map(int,input().split())
    if max_dis[x-1] == max_dis[y-1]:
        print("Yes")
    else:
        print("No")
