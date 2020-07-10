'''
    handle - pruvi007
    questionName - Apple DIvision
    Contest - NA
    Topic - 
    Platform - CSES
'''
from sys import stdin, stdout
from collections import defaultdict

def main():
    n = int(input())
    a = list( map(int,stdin.readline().split()) )
    a = sorted(a)
    target = sum(a)//2


main()