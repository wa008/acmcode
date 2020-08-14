class Solution:
    def nextLargerNodes(self, head):
        arn = []
        while head != None:
            arn.append(head.val)
            head = head.next
        n = len(arn)
        ans = [0 for i in range(n)]
        mid = []
        leng = 0
        for i in range(n-1,-1,-1):
            while leng != 0 and mid[leng-1] <= arn[i]:
                mid.pop()
                leng -= 1
            if leng == 0:
                ans[i] = 0
            else:
                ans[i] = mid[leng-1]
            mid.append(arn[i])
            leng += 1
        return ans
