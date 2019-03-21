class Solution:
    def shipWithinDays(self, weights, D) -> int:
        n = len(weights)
        def check(x):
            now = 0
            num = 1
            nonlocal n
            nonlocal weights
            nonlocal D
            for i in range(n):
                if now + weights[i] > x:
                    now = weights[i]
                    num += 1
                else:
                    now += weights[i]
            if num > D:
                return False
            else:
                return True

        l = 1
        for i in range(n):
            l = max(l, weights[i])
        r = 25000000
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return r

