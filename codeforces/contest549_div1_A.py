import math
n,k = list(map(int, input().split()))
a,b = list(map(int, input().split()))

x=n*k
y=-1
for i in range(n):
    now = i*k+b-a
    if now<0:
        now += n*k
    ans = n*k//math.gcd(n*k,now)
    x = min(x,ans)
    y = max(y,ans)
    
    now = i*k+(k-b)-a
    if now<0:
        now += n*k
    ans = n*k//math.gcd(n*k,now)
    x = min(x,ans)
    y = max(y,ans)

print(x,y)
