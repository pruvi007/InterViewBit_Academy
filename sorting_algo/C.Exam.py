from sys import stdin, stdout
n = int(stdin.readline())
exam = []
for i in range(n):
    x, y = map( int,stdin.readline().split() )
    exam.append([x,y])
exam = sorted(exam)
day = min(exam[0][0],exam[0][1])
for i in range(1,n):
    if exam[i][0]>=day or exam[i][1]>=day:
        if exam[i][0]>=day and exam[i][1]>=day:
            day = min(exam[i][0],exam[i][1])
        elif exam[i][0]>=day:
            day = exam[i][0]
        elif exam[i][1]>=day:
            day = exam[i][1]
stdout.write("{}\n".format(day))
