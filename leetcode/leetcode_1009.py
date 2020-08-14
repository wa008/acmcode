class Solution:
    def bitwiseComplement(self, n):
        if n == 0:
            return 1
        ans = 0
        ins = 1
        while n>0:
            if (n&1) == 0:
                ans += ins
            ins <<= 1
            n >>= 1
        return ans
