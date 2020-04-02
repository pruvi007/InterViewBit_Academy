
def findCell(v):
    for i in range(9):
        for j in range(9):
            if v[i][j]=='.':
                return i,j
    return -1,-1

def safe(v,row,col,num):
    # check row
    for i in range(9):
        if v[row][i]==str(num):
            return False

    # check column
    for i in range(9):
        if v[i][col]==str(num):
            return False

    # check box
    r,c = row-row%3, col-col%3
    for i in range(3):
        for j in range(3):
            if v[i+r][j+c]==str(num):
                return False

    # check if unassigned
    if v[row][col]!='.':
        return False

    return True

def sudoku(v):
    row,col = findCell(v)
    if row==-1 and col==-1:
        return True
    for i in range(1,10):
        if safe(v,row,col,i):
            v[row][col] = str(i)
            if sudoku(v):
                return True
            v[row][col]='.'
    return False

v = []
for i in range(9):
    x = input()
    v.append( [x[i] for i in range(len(x)) ] )

print("Given Board")
for row in v:
    print(row)
fill = sudoku(v)
print("Solution Board")
if fill:
    for row in v:
        print(row)
else:
    "Unable to Fill"
