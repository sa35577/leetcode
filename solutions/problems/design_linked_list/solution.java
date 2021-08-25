class Node {
    Node nxt;
    Node prev;
    int val;
    Node(int x) {
        val = x;
        nxt = null;
        prev = null;
    } 
}


class MyLinkedList {

    /** Initialize your data structure here. */
    Node head;
    Node tail;
    public MyLinkedList() {
        head = null;
        tail = null;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (head == null) return -1;
        int idx = 0;
        Node cur = head;
        while (idx != index) {
            cur = cur.nxt;
            if (cur == null) return -1;
            idx++;
        }
        return cur.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (head == null) {
            head = new Node(val);
            tail = head;
            return;
        }
        Node newHead = new Node(val);
        newHead.nxt = head;
        if (head == tail) {
            tail.prev = newHead;
        }
        head.prev = newHead;
        
        head = newHead;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (tail == null) {
            tail = new Node(val);
            head = tail;
            return;
        }
        Node newTail = new Node(val);
        newTail.prev = tail;
        if (head == tail) {
            head.nxt = newTail;
        }
        tail.nxt = newTail;
        
        tail = newTail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        int idx = 0;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node newBefore = head,newAfter,newNode = new Node(val);
        while (idx != index-1) {
            newBefore = newBefore.nxt;
            if (newBefore == null) return;
            idx++;
        }
        if (newBefore == tail) {
            addAtTail(val);
            return;
        }
        newAfter = newBefore.nxt;
        
        newNode.prev = newBefore;
        newNode.nxt = newAfter;
        newAfter.prev = newNode;
        newBefore.nxt = newNode;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (head == null) return;
        if (head == tail) {
            if (index != 0) return;
            head = null;
            tail = null;
            return;
        }
        int idx = 0;
        Node newBefore,delNode=head,newAfter;
        while (idx != index) {
            delNode = delNode.nxt;
            if (delNode == null) return;
            idx++;
        }
        if (delNode == head) {
            newAfter = head.nxt;
            newAfter.prev = null;
            head = null;
            head = newAfter;
        }
        else if (delNode == tail) {
            newBefore = tail.prev;
            newBefore.nxt = null;
            tail = null;
            tail = newBefore;
        }
        else {
            newBefore = delNode.prev;
            newAfter = delNode.nxt;
            delNode = null;
            newBefore.nxt = newAfter;
            newAfter.prev = newBefore;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */