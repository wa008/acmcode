class Solution:
    def queryString(self, S:str, N:int) -> bool:
        s = set()
        n = len(S)
        for i in range(n):
            x = 0
            for j in range(i,n):
                x = (x<<1) + (S[j]=='1')
                s.add(x)
        for i in range(1,N+1):
            if i not in s:
                return False
        return True
