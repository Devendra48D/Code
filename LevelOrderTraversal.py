class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def levelorder(root):
    if not root:
        return
    queue = [root]
    while queue:
        node = queue.pop(0)
        print node.val,
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
            
a = TreeNode("A")
a.left = TreeNode("B")
a.right = TreeNode("C")
a.left.left = TreeNode("D")
a.right.left = TreeNode("E")
a.right.right = TreeNode("F")

levelorder(a)

##output is "A B C D E F"
