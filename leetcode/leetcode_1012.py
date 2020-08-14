class Solution:
    def numDupDigitsAtMostN(self,n):
        m = n
        ar = []
        while m>0:
            ar.append(m%10)
            m = m//10
        ar = list(reversed(ar))
        def all_n(num, no, flag, f2):
            if num == 0:
                return 1
            if num == 1:
                return 10-no
            if f2 == 1:
                ans = 10-no
            else:
                ans = 9-no+flag
            for i in range(1,num):
                if flag == 0:
                    ans *= 10 - i - no
                else:
                    ans *= 10 - i - no
            if ans<0:
                ans = 0
            # print("num = ", num, no, flag, ans)
            return ans
        Len = len(ar)
        ans = 0
        for i in range(1,Len-1):
            ans += all_n(i, 0, 0, 0)
            # print("i,ans = ", all_n(i, 0, 0, 0))
        # print("mid_ans = ", ans)
        vis = [0 for i in range(10)]
        ins = 0
        fond = 1
        for i in range(Len):
            for j in range(ar[i]):
                flag = vis[j]
                if flag == 1:
                    continue
                if flag == 0 and (not (j==0 and i==0)):
                    ins += 1
                ff = 0
                if vis[0]==1 or (j==0 and i!= 0):
                    ff = 1
                fff = 1
                if i==0 and j==0:
                    fff = 0
                Mid = all_n(Len-i-1, ins, ff, fff)
                # print("i,j,ans = ", i,j,Len-i-1, ins, ff, fff, Mid)
                ans += Mid
                if flag == 0 and (not (j==0 and i==0)):
                    ins -= 1
            if vis[ar[i]] == 0:
                vis[ar[i]] = 1
                ins += 1
            else:
                fond = 0
                break
        # print(ans, fond, n)
        ans += fond
        return n-ans+1


so = Solution()
print(so.numDupDigitsAtMostN(3))

