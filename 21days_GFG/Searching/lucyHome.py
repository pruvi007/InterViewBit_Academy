def partitions(folders,mid):
    s,c = 0,1
    n = len(folders)
    for i in range(n):
        if s+folders[i] <= mid:
            s += folders[i]
        else:
            c+=1
            s = folders[i]
    return c
def Min_Time(folders,n,workers):
    if workers>n:
        workers = n
    low, high = max(folders), sum(folders)
    ans = 0
    while low<=high:
        mid = (low+high)//2
        p = partitions(folders,mid)
        # print(mid,p)
        if p<=workers:
            ans = mid
            high = mid-1
        else:
            low = mid+1
    return ans 
