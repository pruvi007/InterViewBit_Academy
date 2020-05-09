from sys import stdin, stdout
n = int(stdin.readline())
a = list( map(int,stdin.readline().split()) )
for i in range(n):
    vis = set()
    start = a[i]-1
    vis.add(i)
    while True:
        if start in vis:
            stdout.write("{} ".format(start+1))
            break
        # stdout.write("{} ".format(start))
        vis.add(start)
        start = a[start]-1
        
stdout.write("\n")
