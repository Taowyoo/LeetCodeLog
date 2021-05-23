/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/
// my solution of DFS
class Solution {
    private Node process(Node head){
        Node cur = head;
        Node last = cur;
        while(cur != null){
            if(cur.child != null){
                Node end = process(cur.child);
                end.next = cur.next;
                if(cur.next != null) cur.next.prev = end;
                cur.next = cur.child;
                cur.child.prev = cur;
                cur.child = null;
                cur = end.next;
                last = end;
            }
            else{
                last = cur;
                cur = cur.next;
            }
        }
        return last;
    }
    public Node flatten(Node head) {
        if(head == null) return null;
        process(head);
        return head;
    }
}
//========================================================================================================
// One pass
class Solution {
    public Node flatten(Node head) {
        if( head == null) return head;
	// Pointer
        Node p = head; 
        while( p!= null) {
            /* CASE 1: if no child, proceed */
            if( p.child == null ) {
                p = p.next;
                continue;
            }
            /* CASE 2: got child, find the tail of the child and link it to p.next */
            Node temp = p.child;
            // Find the tail of the child
            while( temp.next != null ) 
                temp = temp.next;
            // Connect tail with p.next, if it is not null
            temp.next = p.next;  
            if( p.next != null )  p.next.prev = temp;
            // Connect p with p.child, and remove p.child
            p.next = p.child; 
            p.child.prev = p;
            p.child = null;
        }
        return head;
    }
}
//========================================================================================================
// official Solution DFS recursive
class Solution {
    public Node flatten(Node head) {
        if (head == null) return head;
        // pseudo head to ensure the `prev` pointer is never none
        Node pseudoHead = new Node(0, null, head, null);

        flattenDFS(pseudoHead, head);

        // detach the pseudo head from the real head
        pseudoHead.next.prev = null;
        return pseudoHead.next;
    }
    /* return the tail of the flatten list */
    public Node flattenDFS(Node prev, Node curr) {
        if (curr == null) return prev;
        curr.prev = prev;
        prev.next = curr;

        // the curr.next would be tempered in the recursive function
        Node tempNext = curr.next;

        Node tail = flattenDFS(curr, curr.child);
        curr.child = null;

        return flattenDFS(tail, tempNext);
    }
}
//========================================================================================================
// DFS iteration
class Solution {
public Node flatten(Node head) {
    if (head == null) return head;

    Node pseudoHead = new Node(0, null, head, null);
    Node curr, prev = pseudoHead;

    Deque<Node> stack = new ArrayDeque<>();
    stack.push(head);

    while (!stack.isEmpty()) {
    curr = stack.pop();
    prev.next = curr;
    curr.prev = prev;

    if (curr.next != null) stack.push(curr.next);
    if (curr.child != null) {
        stack.push(curr.child);
        // don't forget to remove all child pointers.
        curr.child = null;
    }
    prev = curr;
    }
    // detach the pseudo node from the result
    pseudoHead.next.prev = null;
    return pseudoHead.next;
}
}