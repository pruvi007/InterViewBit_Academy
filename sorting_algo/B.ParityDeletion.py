n = int(input())
a = list( map(int,input().split()) )
even,odd =[],[]
for i in range(n):
    if a[i]%2:
        odd.append(a[i])
    else:
        even.append(a[i])
odd, even = sorted(odd), sorted(even)
# print(even)
# print(odd)
if len(odd)>len(even):
    i = 0
    while len(odd):
        if i%2==0:
            if len(odd)==0:
                break
            s = len(odd)-1
            odd.pop(s)
        else:
            if len(even)==0:
                break
            s = len(even)-1
            even.pop(s)
        i+=1
elif len(even)>len(odd):
    i = 1
    while len(even):
        if i%2==0:
            if len(odd)==0:
                break
            s = len(odd)-1
            odd.pop(s)
        else:
            if len(even)==0:
                break
            s = len(even)-1
            even.pop(s)
        i+=1
else:
    i = 1
    while len(even) or len(odd):
        if i%2==0:
            if len(odd)==0:
                break
            s = len(odd)-1
            odd.pop(s)
        else:
            if len(even)==0:
                break
            s = len(even)-1
            even.pop(s)
        i+=1

# print(even)
# print(odd)
ans = 0
for i in range(len(odd)):
    ans += odd[i]
for i in range(len(even)):
    ans += even[i]
print(ans)