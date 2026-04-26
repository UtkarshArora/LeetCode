/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode next1 = head.next;
        head.next = null;
        ListNode newHead = reverseList(next1);
        ListNode temp = newHead;
        while(temp.next!=null)
        {
            temp = temp.next;
        }
        temp.next = head;
        return newHead;
    }
}