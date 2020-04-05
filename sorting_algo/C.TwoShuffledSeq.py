n = int(input())
a = list( map( int,input().split() ) )
a = sorted(a)
inc,dec = [],[]
inc.append(a[0])
flag = [ False for i in range(n) ]
flag[0] = True
c = 1
for i in range(len(a)):
    if flag[i]==False and a[i]>inc[-1]:
        inc.append(a[i])
        flag[i] = True
        c += 1

end = -1
for i in range(n-1,-1,-1):
    if flag[i]==False:
        dec.append(a[i])
        flag[i] = True
        end = i-1
        c += 1
        break

for i in range(end,-1,-1):
    if flag[i]==False and a[i]<dec[-1]:
        dec.append(a[i])
        flag[i] = True
        c += 1
# print(a)
# print(flag)
# print(inc,dec)
if c<n:
    print("NO")
else:
    print("YES")
    print(len(inc))
    for i in range(len(inc)):
        print(inc[i],end=' ')
    print()
    print(len(dec))
    for i in range(len(dec)):
        print(dec[i],end=' ')
    print()

