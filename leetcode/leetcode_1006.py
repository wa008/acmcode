class Solution:
    def clumsy(self, n):
        if n==1:
            return 1
        if n==2:
            return 2
        if n==3:
            return 6
        def func(x):
            ans = 0
            if x==0:
                ans = 0
            elif x==1:
                ans =-1
            elif x==2:
                ans = -2
            elif x==3:
                ans = -6
            else:
                ans = -(x*(x-1)//(x-2))+x-3+func(x-4)
            return ans
        return n*(n-1)//(n-2)+n-3+func(n-4)
