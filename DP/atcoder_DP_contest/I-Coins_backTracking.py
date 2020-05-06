
def total(p,cp,seq):
    global prob
    if cp==len(p):
        # print(seq)
        h = 0
        for i in range(cp):
            if seq[i]=="Head":
                h+=1
        if h>cp//2:
            curProb = 1
            for i in range(cp):
                if seq[i]=="Head":
                    curProb = curProb*p[i]
                else:
                    curProb = curProb*(1-p[i])
            prob += curProb

        return
    seq[cp] = "Head"
    total(p,cp+1,seq)

    seq[cp] = "Tail"
    total(p,cp+1,seq)

prob = 0
n = int(input())
p = list( map(float,input().split()))
seq = [ "" for i in range(n)]
total(p,0,seq)
print(prob)
