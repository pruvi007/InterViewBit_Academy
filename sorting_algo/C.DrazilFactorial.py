from sys import stdin, stdout

n = int( stdin.readline() )
s = stdin.readline().split('\n')

d = {}
d['0'] = ''
d['1'] = ''
d['2'] = '2'
d['3'] = '3'
d['4'] = '322'
d['5'] = '5'
d['6'] = '53'
d['7'] = '7'
d['8'] = '7222'
d['9'] = '7332'
ans = ''
for c in s[0]:
    ans += d[c]

ans = sorted(ans,reverse=True)

stdout.write(''.join(ans))
