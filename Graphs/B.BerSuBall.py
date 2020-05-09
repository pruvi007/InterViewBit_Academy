from sys import stdin, stdout
n = int(stdin.readline())
boys = list( map(int,stdin.readline().split()) )
m = int(stdin.readline())
girls = list( map(int,stdin.readline().split()) )
boys, girls = sorted(boys), sorted(girls)
c = 0
l,r=0,0
while l<n and r<m:
    if abs(boys[l]-girls[r])<=1:
        c+=1
        l,r = l+1,r+1
    elif boys[l]>girls[r]:
        r+=1
    else:
        l+=1
stdout.write("{}\n".format(c))