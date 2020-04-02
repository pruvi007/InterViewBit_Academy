
def sixlets(a,level,sum,size,b):
    if size>b:
        return 0
    
    if sum<=1000 and size==b:
        return 1
    if level>=len(a):
        return 0
    return sixlets( a,level+1,sum+a[level],size+1,b ) + sixlets( a,level+1,sum,size,b )
    

n = int(input())
a = list(map(int,input().split()))
b = int(input())
ans = sixlets(a,0,0,0,b)
print(ans)