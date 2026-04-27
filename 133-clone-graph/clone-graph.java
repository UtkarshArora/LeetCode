/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {

    public Node clone(Node node, HashMap<Node, Node> mp)
    {

        if(node == null)
            return null;
        
        if(mp.containsKey(node))
            return mp.get(node);
        
        Node newNode = new Node(node.val);
        mp.put(node, newNode);

        for(Node n : node.neighbors)
        {
            if(!mp.containsKey(n))
            {
                Node node1 = clone(n, mp);
                mp.put(n, node1);
            }
            newNode.neighbors.add(mp.get(n));
        }
        return newNode;
    }
    public Node cloneGraph(Node node) {

        HashMap<Node, Node> mp = new HashMap<>();
        return clone(node, mp);
    }
}