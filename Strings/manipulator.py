from sys import stdin, stdout
t = int(stdin.readline())
while t>0:
    s1 = stdin.readline().split('\n')[0]
    s2 = stdin.readline().split('\n')[0]
    
    n,m = len(s1),len(s2)
    S1,S2 = [],[]
    c = 0
    found = False
    for i in range(n-1,-1,-1):
        if s1[i]=='#':
            c+=1
            found = True
            continue
        else:
            if found:
                S1.append(c)
                found = False
            c%=26
            ch = chr(65 + (ord(s1[i])%65 + c)%26)
            S1.append(ch)
            c=0
            
    c=0
    for i in range(m-1,-1,-1):
        if s2[i]=='#':
            c+=1
            found = True
            continue
        else:
            if found:
                S2.append(c)
                found = False
            c%=26  
            ch = chr(65 + (ord(s2[i])%65 + c)%26)
            S2.append(ch)
            c=0
    fs1=''
    fs2=''
    for i in range(len(S1)-1,-1,-1):
        if type(S1[i])==str:
            fs1+=S1[i]
    for i in range(len(S2)-1,-1,-1):
        if type(S2[i])==str:
            fs2+=S2[i]     
    # for i in range(len(S1)):
    #     if S1[i]>='A' and S1[i]<='Z':
    #         if i+1 < len(S1) and (S1[i+1]>=1 and S1[i+1]<=9):
    #             c = S1[i+1]
    #             ch = chr(65 + (ord(S1[i])%65 + c)%25)
    #             S1[i] = str(ch)
    # for i in range(len(S2)):
    #     if S2[i]>='A' and S2[i]<='Z':
    #         if i+1 < len(S2) and (S2[i+1]>=1 and S2[i+1]<=9):
    #             c = S2[i+1]
    #             ch = chr(65 + (ord(S2[i])%65 + c)%25)
    #             S2[i] = str(ch)
            
    print(S1)
    print(S2)
    print(fs1,fs2)
    if fs1==fs2:
        stdout.write("{}\n".format("Yes"))
    else:
        stdout.write("{}\n".format("No"))
    t-=1