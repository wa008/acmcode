n = int(input())
x = []
for i in range(n):
    a, b = list(map(int, input().split()))
    x.append(a)

k = int(input())
i = 0
while i < n:
    if x[i] > k:
        break
    i += 1
print(n - i + 1)
