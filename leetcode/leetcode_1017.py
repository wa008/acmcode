class Solution:
    def baseNeg2(self, n):
        if n == 0:
            return "0"
        pre = 0
        ans = ""
        while n>0 or pre>0:
            now = n&3
            n >>= 2
            if now == 1:
                ans += "10"
            elif now == 3:
                ans += "11"
                n += 1
            elif now == 2:
                ans += "01"
                n += 1
            elif now == 0:
                ans += "00"
        n = len(ans)
        if ans[n-1] == "0":
            ans = ans[:n-1]
        return ans[::-1]

