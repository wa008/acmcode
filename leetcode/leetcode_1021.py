class Solution:
    def removeOuterParentheses(self, s):
        ans = ""
        ins = 0
        pre = 0
        for i in s:
            pre = ins
            if i=='(':
                ins += 1
            else:
                ins -= 1
            if ins!=0 and pre!=0:
                ans += i
        return ans
