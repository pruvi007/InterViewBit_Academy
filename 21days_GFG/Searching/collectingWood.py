def wood(h,tree):
    w = 0
    for i in range(len(tree)):
        if h<tree[i]:
            w += tree[i]-h
    # print("Height:{}, WoodCollected:{}".format(h,w))
    return w
    
def find_height(tree,n,k):
    low,high = 1,max(tree)
    ans = -1
    while low<=high:
        mid = (low+high)//2
        w = wood(mid,tree)
        if w == k :
            return mid
        elif w<k:
            high = mid-1
        else:
            low = mid+1
    return ans