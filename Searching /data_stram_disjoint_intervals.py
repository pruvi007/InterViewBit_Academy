
intervals = set()


while True:
    n = int(input())
    flag = False
    l = list( intervals )
    for i in range(1,len(l)):
        cur,prev = l[i],l[i-1]
        if cur[0] > n and prev[1] < n:
            # remove ith and i+1 th interval and insert a new interval with ( prev[0],cur[1])
            new_interval = ( prev[0],cur[1] )
            set.remove( cur )
            set.remove( prev )
            set.add( new_interval )
            flag = True
    if flag == False:
        intervals.add((n,n))
    
    for x in intervals:
        print( x,end=' ')

