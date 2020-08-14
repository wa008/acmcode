t = int(input())
fir = 0
while t>0:
    t -= 1
    fir += 1
    n,p = list(map(int, input().split()))
    ar = list(map(int, ("0 "+input()).split()))
    ar.sort()
    ss = [0 for i in range(n+1)]
    for i in range(n+1):
        ss[i] = ss[i-1] + ar[i]
    mx = 100000000000
    for i in range(p, n+1):
        mx = min(mx, ar[i]*p - ss[i] + ss[i-p])
    print("Case #%d: %d" % (fir,mx))

