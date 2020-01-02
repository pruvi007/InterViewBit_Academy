s = input()
count = [ 0 for i in range(26) ]
for i in range(26):
    x = chr(97+i)
    j=0
    while j<len(s):
        if s[j] == x:
            j += 1
            while j<len(s) and s[j]==x :
                j+=1
            count[ord(x)%97]+=1
        j+=1

print(count)
m = [0,0]
for i in range(26):
    if count[i] > m[0]:
        m[0] = count[i]
        m[1] = i
s = 0
for i in range(26):
    if m[0]==count[i] and m[1] == i:
        s+=1
    else:
        s+=count[i]
print(m)
print(s)
