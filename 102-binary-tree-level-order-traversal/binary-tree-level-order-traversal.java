/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {


        List<List<Integer>>list1 = new ArrayList<>();
        if(root == null){
            return list1;
        }
        Queue<TreeNode>l1 = new ArrayDeque<>();
        l1.add(root);
        while(!l1.isEmpty())
        {
            int size_l = l1.size();
            List<Integer>list2 = new ArrayList<>();
            for(int i = 0 ; i < size_l ; i++)
            {
                TreeNode node = l1.poll();
                list2.add(node.val);
                if(node.left!=null)
                    l1.add(node.left);
                if(node.right!=null)
                    l1.add(node.right);
            }
            list1.add(list2);
        }
        return list1;
    }
}