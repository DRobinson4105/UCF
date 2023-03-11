// David Robinson
// COP 3330, Spring 2023
// da034737

public class Garland
{
    private Node head; // Reference to the top-left node in this garland
    private int size; // The number of strings currently in this garland

    // Takes a string and creates a linked list representation of that string with
    // each character being a node in the linked list, returning the head of it
    public static Node stringToLinkedList(String s)
    {
        // If list is null or empty 
        if (s == null || s.length() == 0)
            return null;
        
        // Save head of new linked list
        Node stringHead = new Node(s.charAt(0));

        // Build new linked list saving each character as the next node in the list
        Node curr = stringHead;

        for (int i = 1; i < s.length(); i++)
        {
            curr.down = new Node(s.charAt(i));
            curr = curr.down;
        }

        // Return head of new linked list
        return stringHead;
    }

    // Takes the head of a linked list and returns the string represented by that linked list
    public static String linkedListToString(Node head)
    {
        int size = 0;

        // Find size of linked list by traversing through and keeping a counter
        Node curr = head;

        while(curr != null)
        {
            size++;
            curr = curr.down;
        }

        // Create new character array to hold all of the characters from the linked list
        char[] charArray = new char[size];

        // Iterate through the array saving each character in the current index and then traversing to next node
        curr = head;

        for (int i = 0; i < size; i++)
        {
            charArray[i] = curr.data;
            curr = curr.down;
        }

        // Return the character array as a string
        return new String(charArray);
    }

    // Default constructor, auto-initializing the head pointer to null and size to 0 
    Garland() {}

    // Overloaded constructor, takes an aray of string and forms the garland with them
    Garland(String[] strings)
    {
        // If there were any strings inputed
        if (strings.length > 0)
        {
            // Set the garland head to the head of the first string
            head = stringToLinkedList(strings[0]);

            // Iterate through the array of strings adding each string to the garland
            Node curr = head;

            for (int i = 1; i < strings.length; i++)
            {
                curr.next = stringToLinkedList(strings[i]);
                curr = curr.next;
            }
        }

        // Set the size to the number of strings
        size = strings.length;
    }

    // Returns the head of the garland
    public Node head()
    {
        return head;
    }

    // Returns the size of the garland (number of strings)
    public int size()
    {
        return size;
    }

    // Takes a string, converts it to a linked list and adds it to the end of the garland
    public void addString(String s)
    {
        // If list is null or empty 
        if (s == null || s.length() == 0)
            return;
        
        // If garland is empty
        if (size == 0)
        {
            head = stringToLinkedList(s);
            size++;
            return;
        }

        // Find head of last string in garland
        Node curr = head;
        while (curr.next != null)
            curr = curr.next;

        // Add new string to the end of the garland
        curr.next = stringToLinkedList(s);
        size++;
    }

    // Returns the head node of the linked list at the given index in the garland
    public Node getNode(int index)
    {
        // If given index was invalid
        if (index < 0 || index >= size)
            return null;
        
        // Find head of the linked list at the given index
        Node curr = head;
        for (int i = 0; i < index; i++)
            curr = curr.next;

        // Return the head
        return curr;
    }

    // Returns the string at the given index in the garland
    public String getString(int index)
    {
        // Uses getNode() to find the requested linked list and converts it to a string
        return linkedListToString(getNode(index));
    }

    // Removes the string at the given index from the garland and returns true if string was removed
    public boolean removeString(int index)
    {
        // If given index was invalid
        if (index < 0 || index >= size)
            return false;
        
        // If first string needs to be removed
        if (index == 0)
        {
            head = head.next;
            size--;
            return true;
        }

        // Find head of the linked list at the given index
        Node curr = head;
        for (int i = 0; i < index - 1; i++)
            curr = curr.next;

        // Remove the string at the given index
        curr.next = curr.next.next;
        size--;
        return true;
    }

    // Prints the string at the given index in the garland
    public boolean printString(int index)
    {
        // If given index was invalid
        if (index < 0 || index >= size)
        {
            System.out.println("(invalid index)");
            return false;
        }

        // Find head of the linked list at the given index
        Node curr = head;
        for (int i = 0; i < index; i++)
            curr = curr.next;

        printString(curr);

        return true;
    }

    // Prints all of the strings in the garland
    public void printStrings()
    {
        // If garland is empty
        if (size == 0)
        {
            System.out.println("(empty list)");
            return;
        }

        Node curr = head;

        // Print each string
        for (int i = 0; i < size; i++)
        {
            printString(curr);
            curr = curr.next;
        }
    }

    // Prints all of the characters in the linked list given starting with the head and moving down
    public static void printString(Node head)
    {
        Node curr = head;

        // Print each character
        while (curr != null)
        {
            System.out.print(curr.data);
            curr = curr.down;
        }

        System.out.println();
    }

    public static double difficultyRating()
    {
        return 2;
    }

    public static double hoursSpent()
    {
        return 3;
    }
}