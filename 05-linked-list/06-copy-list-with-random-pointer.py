"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def __init__(self):
        self.map = { None: None }

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr: Optional[Node] = head
        while curr:
            copy = Node(curr.val)
            self.map[curr] = copy
            curr = curr.next
        
        curr: Optional[Node] = head
        while curr:
            copy = self.map[curr]
            copy.next = self.map[curr.next]
            copy.random = self.map[curr.random]
            curr = curr.next
        
        return self.map[head]
