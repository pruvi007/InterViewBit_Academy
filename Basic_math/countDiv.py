from sys import stdin, stdout
import math
from copy import deepcopy
from collections import defaultdict

MOD = 10**9 + 7



def primeFactor(n):
    ans = defaultdict(int)
    while n % 2 == 0: 
        ans[2]+=1 
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            ans[i]+=1
            n = n / i 
    if n > 2: 
        ans[n]+=1
    return ans
    
n = int(stdin.readline())
a = list( map(int,stdin.readline().split()) )

# print(sieve)
occur = defaultdict(int)
occur2 = defaultdict(int)
f = {}
for i in range(n):
    p = primeFactor(a[i])
    for x in p:
        occur[x] += p[x]
        occur2[x] += p[x]
    if a[i] not in f:
        f[ a[i] ] = defaultdict(int)
        for x in p:
            f[a[i]][x] += p[x]
# print(occur)

for i in range(n):
    x = f[a[i]]
    for k in x:
        occur2[k] -= x[k]
    ans = 1
    for k in occur2:
        ans = (ans%MOD*(occur2[k]+1)%MOD)%MOD
        ans %= MOD
    for x in occur:
        occur2[x] = occur[x]
    stdout.write("{} ".format(ans))