import sys
def gcd_func(a, b):
    if a % b == 0:
        return b
    else :
        return gcd_func(b, a % b)

t = int(input())
for case in range(1, t + 1):
    inp = raw_input().strip()
    ns, m = map(int, inp.split())
    ar = map(int, raw_input().split())
    nx = [0 for i in range(m + 1)]
    for i in range(m - 1):
        if ar[i] != ar[i + 1]:
            gcdx = gcd_func(ar[i], ar[i + 1])
            nx[i] = ar[i] / gcdx
            for j in range(i + 1, m + 1):
                nx[j] = ar[j - 1] / nx[j - 1]
            for j in range(i - 1, -1, -1):
                nx[j] = ar[j + 1] / nx[j + 1]
            s = set()
            index = 0
            for x in nx:
                # print index , x
                index += 1
                s.add(x)
            s = sorted(list(s))
            assert len(set(s)) == 26
            d = dict()
            for i in range(len(s)):
                d[s[i]] = i
            sys.stdout.write(("Case #%d: " % case))
            for x in nx:
                sys.stdout.write(chr(ord('A') + d[x]))
            sys.stdout.write("\n")
            break

