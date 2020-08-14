class Solution:
    def prefixesDivBy5(self, A):
        pre = 0
        n = len(A)
        ans = []
        for i in range(n):
            pre = pre * 2 + A[i]
            ans.append(pre % 5 == 0)
        return ans

