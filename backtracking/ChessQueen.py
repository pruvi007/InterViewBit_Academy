'''
    handle - pruvi007
    questionName - Chess and Queens
    Contest - NA
    Topic - BackTracking
    Platform - CSES
'''
from sys import stdin, stdout
from collections import defaultdict

def safe(board,row,col):
    for i in range(col):
        if board[row][i]=='Q':
            return False
    l,r = row-1,col-1
    while l>=0 and r>=0:
        if board[l][r]=='Q':
            return False
        l-=1
        r-=1
    l,r = row+1,col-1
    while l<len(board) and col>=0:
        if board[l][r]=='Q':
            return False
        l+=1
        r-=1
    return True
c = 0
def solve(board,col):
    global c
    if col>=len(board[0]):
        c += 1
        
        return
    for i in range(len(board)):
        if safe(board,i,col) and board[i][col]=='.':
            board[i][col] = 'Q'
            solve(board,col+1)
            board[i][col] = '.'

def main():
    board = []
    for i in range(8):
        x = list( stdin.readline().split('\n')[0] )
        board.append(x)
    
    solve( board,0 )
    stdout.write("{}\n".format(c))

main()