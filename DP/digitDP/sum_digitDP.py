def Count(DP, S, Sum, num, idx, tight, curr_num):
    #base case 
    if idx == len(num):
        if Sum == S:
            return 1
        
        return 0
    
    #check if this state already calculated
    if DP[idx][Sum][tight] != -1:
        return DP[idx][Sum][tight]
        
    limit = num[idx]+1 if tight else 10
    
    res = 0
    
    for d in range(limit):
        curr_sum = Sum + d
        if curr_sum > S:
            continue
        
        curr_tight = tight and d == num[idx]
        
        res += Count(DP, S, curr_sum, num, idx+1, curr_tight, 10 * curr_num + d)
        
    DP[idx][Sum][tight] = res
        
    return res
    
def dp(N, S):
    num = [int(k) for k in str(N)]
 
    DP = [[[-1 for _ in range(2)] for _ in range(136)] for _ in range(20)]
    
    return Count(DP, S, 0, num, 0, 1, 0)
    
def solve():
    A, B, S = map(int, input().split())
    
    print (dp(B,S) - dp(A-1,S))
    
    #Find smallest number
    num = [int(k) for k in str(A)]
    Min = int(str(S%9) + ((S//9))*"9")
 
    if Min < A:
        sm = sum(num)
        
        if sm > S:
            while sm > S:
                i = len(num)-1
                while sm > S and i > 0:
                    sm -= num[i]
                    num[i] = 0
    
                    k = i-1
                    while k >= 0 and num[k] == 9:
                        sm -= num[k]
                        k -= 1
                    
                    sm += 1
                    
                    if k == -1:
                        num[0] = 1
                        num.append(0)
                        break
                    else:
                        num[k] += 1
                            
                    i -= 1
 
        if sm < S:
            i = len(num)-1
            sm = S - sm
            while sm and i >= 0:
                incr = min(sm, 9 - num[i])
                num[i] += incr
                sm -= incr
                i -= 1
                
        print (''.join(str(k) for k in num))
        
    else:
        print (Min)
 
if __name__ == "__main__":
    solve()