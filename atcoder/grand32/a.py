n = int(input())
ar = list(map(int, input().split()))
ans = [0 for i in range(n)]
fond = True
for i in range(n-1,-1,-1):
    mx = -1
    for j in range(i+1):
        if ar[j] == j+1:
            mx = max(mx, j+1)
    if mx == -1:
        fond = False
        break
    else:
        ans[i] = mx
        for j in range(mx-1, i):
            ar[j] = ar[j+1]

if fond:
    for i in range(n):
        print(ans[i])
else:
    print(-1)


