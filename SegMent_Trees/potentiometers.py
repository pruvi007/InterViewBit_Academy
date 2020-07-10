'''
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
'''
from sys import stdin, stdout
from collections import defaultdict

class fenwickTree:
    def __init__(self,n):
        self.n = n+1
        self.bit = [ 0 for i in range(self.n+1)]
    def build(self,a):
        for i in range(len(a)):
            self.add(i,a[i])
    def add(self,i,delta):
        i+=1
        while i<self.n:
            self.bit[i] += delta
            i = i + i&(-i)
    def sum(self,idx):
        ret = 0
        idx += 1
        while idx>0:
            ret += self.bit[idx]
            idx = idx - idx&(-idx)
        return ret
    def rangeQuery(self,l,r):
        return self.sum(r) - self.sum(l-1)

def main():
    while True:
        n = int(stdin.readline())
        if n==0:
            break
        a = []
        for i in range(n):
            a.append( int(stdin.readline()) )
        BIT = fenwickTree(n)
        BIT.build(a)
        print(BIT.bit)
        while True:
            s = stdin.readline().split('\n')[0]
            if s=="END":
                break
            s = s.split()
            ch, l, r = s[0], int(s[1]), int(s[2])
            if ch=='M':
                ans = BIT.rangeQuery(l-1,r-1)
                stdout.write("{}\n".format(ans))
            else:
                delta = r - a[l-1]
                a[l-1] = r
                BIT.add(l-1,delta)
    

main()