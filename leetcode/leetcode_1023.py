class Solution:
    def camelMatch(self, q, p):
        n=len(p)
        ans=[]
        for x in q:
            ins = 0
            flag=True
            for i in x:
                if ins<n and i==p[ins]:
                    ins += 1
                elif i.isupper():
                    flag=False
                    break
            if ins != n:
                flag=False
            ans.append(flag)
        return ans
