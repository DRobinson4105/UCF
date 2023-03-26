public class Stack 
{
    private Node top;
    private int size;
    
    private static final int EMPTY_STACK_ERROR = Integer.MIN_VALUE;

    // Return the value that is at the top of the stack
    public int peek()
    {
        // If the stack is empty
        if (isEmpty())
            return EMPTY_STACK_ERROR;

        // Return top value in stack
        return top.data;
    }

    // Remove top value in stack
    public void pop()
    {
        // If the stack is empty
        if (isEmpty()) return;

        // Shift top of stack to next node
        top = top.next;
        size--;
    }

    // Add value to top of stack
    public void push(int value)
    {
        // Create node with inputed value
        Node newNode = new Node(value);
        size++;

        // Add new node to top of stack
        newNode.next = top;

        // Save the new top
        top = newNode;
    }

    // String format for stack n1 <- n2 <- ...
    public String toString()
    {
        String s = "";

        for(Node current = top; current != null; current = current.next)
            s += current.data + ((current.next != null) ? " <- " : "");

        return s;
    }

    // Check if a queue is empty
    public boolean isEmpty()
    {
        return top == null;
    }

    // Return number of nodes in stack
    public int size()
    {
        return size;
    }
}
