class Solution:
    def numPairsDivisibleBy60(self, ar):
        aa = [0 for i in range(60)]
        for x in ar:
            aa [x % 60] += 1
        ans = 0
        for i in range(31):
            x = (60-i)%60
            if x == i:
                ans += aa[i] * (aa[i]-1) // 2
            else:
                ans += aa[i]*aa[x]
        return ans
