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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode prev = new ListNode();
        ListNode curr = new ListNode();
        prev.next = curr;
        while(list1!=null || list2!=null)
        {
            int val1 = (list1 == null)? Integer.MAX_VALUE : list1.val;
            int val2 = (list2 == null)? Integer.MAX_VALUE : list2.val;
            if(val1 <= val2)
            {
                curr.next = list1;
                list1 = list1.next;
            }
            else
            {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        return prev.next.next;
    }
}