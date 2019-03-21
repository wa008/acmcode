class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        mx = 0
        ans = ""
        for i in range(n):
            l = i-1
            r = i+1
            while l>=0 and r<n:
                if s[l] == s[r]:
                    l -= 1
                    r += 1
                else:
                    break
            if r-l-1 > mx:
                mx = r-l-1
                ans = ""
                for j in range(l+1, r):
                    ans += s[j]
        for i in range(n):
            l = i
            r = i+1
            while l>=0 and r<n:
                if s[l] == s[r]:
                    l -= 1
                    r += 1
                else:
                    break
            if r-l-1 > mx:
                mx = r-l-1
                ans = ""
                for j in range(l+1, r):
                    ans += s[j]
        return ans

