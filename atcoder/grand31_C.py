import math

n, a, b = list(map(int, input().split()))

maxn = 1000000
vis = [0 for i in range(maxn)]
an = 1

def func(now):
    global b
    global vis
    global an
    global n
    an += 1
    # print(now, an, n)
    if an == 1<<n:
        print("", b)
        # print("b = ", b, an)
        return -1
    else:
        for i in range(n):
            if vis[now ^ (1<<i)] == 0 and (now^(1<<i)) != b:
                vis[now ^ (1<<i)] = 1
                print("", now ^ (1<<i),end="")
                return now^(1<<i)
    return -1
x = 0
for i in range(n):
    if (a&(1<<i)) != (b&(i<<i)):
        x += 1
if x == 1:
    print("NO")
else:
    print("YES")
    vis[a] = 1
    print(a,end="")
    a = func(a)
    while a != -1:
        a = func(a)
