class Solution:
    def videoStitching(self, arr, t):
        arr.sort(key = lambda x:(x[0],x[1]))
        ans=1000
        al = [1000 for i in range(len(arr))]
        n = len(arr)
        for i in range(n):
            if arr[i][0]==0:
                al[i]=1
        for j in range(n):
            for i in range(j):
                if arr[j][0]<=arr[i][1]:
                    al[j]=min(al[j], al[i]+1)
        for i in range(n):
            if arr[i][1]>=t:
                ans=min(ans, al[i])
        if ans == 1000:
            ans = -1
        return ans
