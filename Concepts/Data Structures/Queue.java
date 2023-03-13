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

public class Queue
{
    private Node front; // Next node in queue
    private Node rear; // Last node in queue
    private int size; // Number of nodes in queue

    private static final int EMPTY_QUEUE_ERROR = Integer.MIN_VALUE;

    // Return the value that is next in queue
    public int peek()
    {
        // If the queue is empty
        if (isEmpty())
            return EMPTY_QUEUE_ERROR;

        // Return next value in queue
        return front.data;
    }

    // Remove the next value in queue
    public void dequeue()
    {
        // If the queue is empty
        if (isEmpty()) return;

        // Shift front of queue to next node
        front = front.next;
        size--;

        // If there was only node in the queue
        if (isEmpty())
            rear = null;
    }

    // Add a new value to end of queue
    public void enqueue(int value)
    {
        // Create node with inputed value
        Node newNode = new Node(value);
        size++;

        // If the queue is empty
        if (isEmpty())
        {
            front = rear = newNode;
            return;
        }

        // Add new node to end of queue
        rear.next = newNode;

        // Move the rear pointer to the new end of queue
        rear = rear.next;
    }

    // Check if a queue is empty
    public boolean isEmpty()
    {
        return front == null;
    }

    // String format for queue n1 <- n2 <- ...
    public String toString()
    {
        String s = "";

        for(Node current = front; current != null; current = current.next)
            s += current.data + ((current.next != null) ? " <- " : "");

        return s;
    }

    // Return number of nodes in queue
    public int size()
    {
        return size;
    }
}
