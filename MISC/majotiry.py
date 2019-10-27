'''
idea: moore vorting process
start maj from 0th elemt 
if found then increment count else decrement (if count ==0 then change majority elemtn)
this method gives us the candidate for majorrity element

'''

class Solution:
    def majorityElement(self, a):
        n = len(a)
        maj,count = 0,1
        for i in range(1,n):
            if a[maj] == a[i]:
                count +=1
            else:
                count -=1
                if count == 0:
                    maj = i
                    count = 1
        return a[maj]