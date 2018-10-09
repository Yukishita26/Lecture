I=lambda:map(int,input().split())

while True:
    N,M=map(int,input().split())
    if N==0: break
    sumH = [0]
    for _ in range(N):
        sumH += [sumH[-1]+int(input())]
    sumW=[0]
    for _ in range(M):
        sumW += [sumW[-1]+int(input())]
    
    lH=[]
    for i in range(N):
        for j in range(i,N):
            lH += [sumH[j+1]-sumH[i]]
    #lH = sorted(lH)
    lW=[]
    for i in range(M):
        for j in range(i,M):
            lW += [sumW[j+1]-sumW[i]]
    #lW = sorted(lW)

    mul = {}
    dub = {}
    for i in lH:
        if i in mul.keys():
            mul[i] += 1
        else:
            mul[i] = 1
            dub[i] = 0
    for j in lW:
        if j in dub.keys():
            dub[j] += 1
    count = 0
    print(lH)
    print(lW)
    print(mul)
    print(dub)
    for k in mul.keys():
        count += dub[k]*mul[k]

    print(count)



