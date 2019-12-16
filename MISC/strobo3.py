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

    
class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def solve(self, A, B):
        l1,l2 = len(A),len(B)
        # a = numdef(l1,l1)
        # b = numdef(l2,l2)
        
        # a,b = sorted(a),sorted(b)
        
        # print(a,b)
        c1,c2=0,0
        for z in range(l1,l2+1):
            a = numdef(z,z)
            for i in range(len(a)):
                if int(a[i])>=int(A) and int(a[i])<=int(B):
                    c1+=1
        
        return c1
        