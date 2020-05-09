from sys import stdin, stdout
n = int(stdin.readline())
a = list( map(int,stdin.readline().split()) )
last = n-2
ans = []
while a[last]!=1:
    last = a[last]
    # print(last)
    ans.append(last)
    last -=2
ans = [1] + ans[::-1] + [n]
for node in ans:
    stdout.write("{} ".format(node))
