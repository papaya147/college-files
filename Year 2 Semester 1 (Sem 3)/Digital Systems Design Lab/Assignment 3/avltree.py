import random


class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.right = None
        self.left = None

    def insert(self, val):
        if self is None:
            self = Node(val)
        if val > self.val:
            if self.right:
                self.right.insert(val)
            else:
                self.right = Node(val)
        else:
            if self.left:
                self.left.insert(val)
            else:
                self.left = Node(val)
        
    def inorder(self):
        if self.left:
            self.left.inorder()
        print(self.val, end=' ')
        if self.right:
            self.right.inorder()

    def display(self):
        lines, *_ = self._display_aux()
        for line in lines:
            print(line)

    def _display_aux(self):
        """Returns list of strings, width, height, and horizontal coordinate of the root."""
        # No child.
        if self.right is None and self.left is None:
            line = '%s' % self.val
            width = len(line)
            height = 1
            middle = width // 2
            return [line], width, height, middle

        # Only left child.
        if self.right is None:
            lines, n, p, x = self.left._display_aux()
            s = '%s' % self.val
            u = len(s)
            first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s
            second_line = x * ' ' + '/' + (n - x - 1 + u) * ' '
            shifted_lines = [line + u * ' ' for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, n + u // 2

        # Only right child.
        if self.left is None:
            lines, n, p, x = self.right._display_aux()
            s = '%s' % self.val
            u = len(s)
            first_line = s + x * '_' + (n - x) * ' '
            second_line = (u + x) * ' ' + '\\' + (n - x - 1) * ' '
            shifted_lines = [u * ' ' + line for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2

        # Two children.
        left, n, p, x = self.left._display_aux()
        right, m, q, y = self.right._display_aux()
        s = '%s' % self.val
        u = len(s)
        first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s + y * '_' + (m - y) * ' '
        second_line = x * ' ' + '/' + (n - x - 1 + u + y) * ' ' + '\\' + (m - y - 1) * ' '
        if p < q:
            left += [n * ' '] * (q - p)
        elif q < p:
            right += [m * ' '] * (p - q)
        zipped_lines = zip(left, right)
        lines = [first_line, second_line] + [a + u * ' ' + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2

def median(root, nums):
    if len(nums) == 0:
        return
    root.insert(int(nums[int(len(nums) / 2)]))
    median(root, nums[ : int(len(nums) / 2)])
    median(root, nums[int(len(nums) / 2) + 1 : ])

nums = [random.randint(0, 100) for _ in range(20)]
nums.sort()
root = Node(nums[int(len(nums) / 2)])
median(root, nums[ : int(len(nums) / 2)])
median(root, nums[int(len(nums) / 2) + 1 : ])
root.display()