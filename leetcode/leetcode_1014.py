class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        n = len(A)
        now = A[0]
        ans = -100000
        for i in range(1,n):
            ans = max(ans, now+A[i]-1)
            now = max(now-1, A[i])
        return ans
