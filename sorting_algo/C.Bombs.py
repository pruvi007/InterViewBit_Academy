from sys import stdin, stdout

n = int(stdin.readline())
pos = []
for i in range(n):
    x, y = map( int,stdin.readline().split() )
    pos.append([x,y])
pos = sorted( pos,key=lambda pos: abs(pos[0])+abs(pos[1]) )
# print(pos)
moves = []
for p in pos:
    x,y = p
    xNeg,yNeg=False,False
    xPos,yPos=False,False
    if x>0:
        # print("1 R ",x)
        moves.append( "1 {} R".format(x)  )
        xPos = True
    elif x<0:
        # print("1 L ",-x)
        moves.append( "1 {} L".format(-x)  )
        xNeg = True
    
    if y>0:
        # print("1 U ",y)
        moves.append( "1 {} U".format(y)  )
        yPos = True
    elif y<0:
        # print("1 D ",-y)
        moves.append( "1 {} D".format(-y)  )
        yNeg = True
    # print(2)
    moves.append( "{}".format(2)  )
    if xNeg:
        # print("1 R ",-x)
        moves.append( "1 {} R".format(-x)  )
    elif xPos:
        # print("1 L ",x)
        moves.append( "1 {} L".format(x)  )

    if yNeg:
        # print("1 U ",-y)
        moves.append( "1 {} U".format(-y)  )
    elif yPos:
        # print("1 D ",y)
        moves.append( "1 {} D".format(y)  )
    # print(3)
    moves.append( "{}".format(3)  )

print(len(moves))
for m in moves:
    stdout.write(m)
    stdout.write("\n")

