class Solution:
    def canThreePartsEqualSum(self, A):
        n = len(A)
        ss = 0
        for i in range(n):
            ss += A[i]
        if ss % 3 != 0:
            return False
        pre = 0
        ans = 0
        for i in range(n):
            pre += A[i]
            if pre == ss/3:
                ans += 1
                pre = 0
        return ans == 3
