class Solution:
    def sumRootToLeaf(self, root):
        ans = 0
        def dfs(root,val):
            nonlocal ans
            val = val*2 + root.val
            if root.left==None and root.right==None:
                ans += val
            if root.left!=None:
                dfs(root.left, val)
            if root.right!=None:
                dfs(root.right, val)
        dfs(root,0)
        return ans
