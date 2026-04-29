# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    prev = None
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        while head:
            next1 = head.next
            head.next = self.prev
            self.prev = head
            head = next1
        return self.prev


        