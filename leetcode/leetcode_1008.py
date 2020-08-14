class Solution:
    def bstFromPreorder(self, ar):
        n = len(ar)
        ins = 0
        def binary(flag, x):
            nonlocal ins
            if ins == n:
                return None
            now = TreeNode(ar[ins])
            ins += 1
            if ins == n:
                return now
            if ar[ins]<now.val:
                now.left = binary(0, now.val)
            if ins == n:
                return now
            if flag == 1 or ar[ins]<x:
                now.right = binary(flag, x)
            return now
        return binary(1, 0)
