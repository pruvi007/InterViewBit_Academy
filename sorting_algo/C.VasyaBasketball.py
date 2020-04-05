def lowerBound(A,d):
    ans = -1
    low,high=0,len(A)-1
    while low<=high:
        mid = (low+high)//2
        if A[mid]<=d:
            ans = mid
            low = mid+1
        else:
            high = mid-1
    return ans+1

n = int(input())
A = list( map( int,input().split() ) )
m = int(input())
B = list( map( int,input().split() ) )

A,B = sorted(A),sorted(B)
low,high = 0,max( max(A),max(B) )+1
m = -10**10
# choose d as one of A,B,low and high
ansA,ansB = 0,0
for i in range(len(A)):
    d = A[i]
    loc = lowerBound(A,d)
    pointsA = loc*2 + (len(A)-loc)*3
    loc = lowerBound(B,d)
    pointsB = loc*2 + (len(B)-loc)*3
    if m<=(pointsA-pointsB):
        if (pointsA-pointsB) == m:
            if pointsA>ansA:
                ansA,ansB = pointsA,pointsB
        else:
            m = pointsA-pointsB
            ansA,ansB = pointsA,pointsB
        # print(ansA,ansB,m)
for i in range(len(B)):
    d = B[i]
    loc = lowerBound(A,d)
    pointsA = loc*2 + (len(A)-loc)*3
    loc = lowerBound(B,d)
    pointsB = loc*2 + (len(B)-loc)*3
    if m<=(pointsA-pointsB):
        if (pointsA-pointsB) == m:
            if pointsA>ansA:
                ansA,ansB = pointsA,pointsB
        else:
            m = pointsA-pointsB
            ansA,ansB = pointsA,pointsB
        # print(ansA,ansB,m)
for x in [low,high]:
    d = x
    loc = lowerBound(A,d)
    pointsA = loc*2 + (len(A)-loc)*3
    loc = lowerBound(B,d)
    pointsB = loc*2 + (len(B)-loc)*3
    if m<=(pointsA-pointsB):
        if (pointsA-pointsB) == m:
            if pointsA>ansA:
                ansA,ansB = pointsA,pointsB
        else:
            m = pointsA-pointsB
            ansA,ansB = pointsA,pointsB
        # print(ansA,ansB,m)
print("{}:{}".format(ansA,ansB))
