class Node
{
    public int data;
    public Node next;

    Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList
{
    private Node head;
    private Node tail;
    private int size;

    public static final int EMPTY_LINKED_LIST_ERROR = Integer.MIN_VALUE;

    // Runtime: O(1)
    public void insertHead(int data)
    {
        // Create a new node and have it point to the current head 
        // and then make the head pointer point to the new node
        Node newHead = new Node(data);
        newHead.next = head;
        head = newHead;

        // If the linked list is empty, then the node added is both the head and the tail
        if (tail == null)
            tail = head;

        size++;
    }

    // Runtime: O(1)
    public int removeHead()
    {
        // If the list is empty
        if (head == null)
            return EMPTY_LINKED_LIST_ERROR;

        // Hold onto the value from the current head of the list
        int retval = head.data;

        // Move the head to the next node, leaving the old head for garbage
        head = head.next;
        size--;

        // If the only node in the list was removed
        if (head == null)
            tail = null;

        // Return removed value
        return retval;
    }

    // Runtime: O(1)
    public void insertTail(int data)
    {
        size++;

        // If the list is empty
        if (head == null)
        {
            head = tail = new Node(data);
            return;
        }

        // Add new node to end of list and shift tail pointer to the new tail
        tail.next = new Node(data);
        tail = tail.next;
    }

    // Runtime: O(N)
    public int removeTail()
    {
        // If the list is empty
        if (head == null)
            return EMPTY_LINKED_LIST_ERROR;

        // Hold onto the value from the current tail of the list
        int retval = tail.data;

        // If the list only has one node
        if (head == tail)
        {
            head = tail = null;
            return retval;
        }

        // Move cur to the node before the current tail
        Node cur = head;

        while (cur.next != tail)
            cur = cur.next;

        // Remove last node and set tail to the new last node
        cur.next = null;
        tail = cur;

        // Return removed value
        return retval;
    }

    public boolean isEmpty()
    {
        return head == null;
    }

    public void print()
    {
        if (head == null) return;
        
        for(Node current = head; current != null; current = current.next)
            System.out.print(current.data + ((current.next != null) ? " " : "\n"));
    }

    public static void main(String[] args)
    {
        LinkedList list = new LinkedList();

        list.insertTail(1);
        list.insertTail(2);
        list.insertTail(3);
        list.insertTail(4);

        list.print();
    }
}