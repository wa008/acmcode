class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        n = K
        now = 1
        ss = 1
        ans = 1
        for i in range(1,200000):
            if ss == 0:
                return ans
            now = now * 10 % n
            ss = (ss + now) % n
            ans += 1
        return -1
