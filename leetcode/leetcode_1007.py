class Solution:
    def minDominoRotations(self, aa,ab):
        flag=1
        n=len(aa)
        ans = 10000000
        a = 0
        b = 1
        for i in range(1,n):
            if aa[0]!=aa[i] and aa[0]!=ab[i]:
                flag=0
                break
            if aa[0]!=aa[i]:
                a += 1
            if aa[0]!=ab[i]:
                b += 1
        if flag==1:
            ans=min(ans,a,b)
        flag = 1
        a = 0
        b = 1
        for i in range(1,n):
            if ab[0]!=aa[i] and ab[0]!=ab[i]:
                flag=0
                break
            if ab[0]!=aa[i]:
                b += 1
            if ab[0]!=ab[i]:
                a += 1
        if flag==1:
            ans=min(ans,a,b)
        if ans == 10000000:
            ans=-1
        return ans

