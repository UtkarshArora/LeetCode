"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:

    def clone(self, node: Optional['Node'], map1) -> Optional['Node']:

        if not node:
            return node
        
        if node in map1:
            return map1[node]
        
        map1[node] = Node(node.val)

        for neigh in node.neighbors:
            if neigh in map1:
                map1[node].neighbors.append(map1[neigh])
            else:
                map1[node].neighbors.append(self.clone(neigh, map1))
        
        return map1[node]
            

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        map1 = dict()
        return self.clone(node, map1)
