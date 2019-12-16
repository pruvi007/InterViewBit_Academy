def numdef(n, length): 
      
    if n == 0: return [""] 
    if n == 1: return ["1", "0", "8"] 
      
    middles = numdef(n - 2, length) 
    result = [] 
    # print(middles)
    for middle in middles: 
        if n != length:             
            result.append("0" + middle + "0") 
  
        result.append("8" + middle + "8") 
        result.append("1" + middle + "1") 
        result.append("9" + middle + "6") 
        result.append("6" + middle + "9") 
    return result 

def strobo(n):
    if n==0:
        return [""]
    if n==1:
        return ["1","0","8"]
    q = ["1","0","8"]
    cur_len = 1
    while len(q)>0:
        l = len(q)
        print("len {} strobo: ".format(l))
        for i in range(l):
            x = q.pop(0)
            q.append("0"+x+"0")
            q.append("8"+x+"8")
            q.append("1"+x+"1")
            q.append("9"+x+"6")
            q.append("6"+x+"9")
        cur_len += 2
    
        if l==n:
            break
        


ans = numdef(6,6)
print(ans)
ans = strobo(5)