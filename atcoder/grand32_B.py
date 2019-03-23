n = int(input())

s = 0
if (n & 1) == 1:
    s = n
    print((n-1) * (n-1) // 2)
else:
    s = n+1
    print((n-2) * n // 2)
for i in range(1, n+1):
    for j in range(i+1, n+1):
        if i + j != s:
            print(i, j)
