import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        ArrayList list = new ArrayList();

        // Linked List: {5, 10, 11, 7, 1, 9, 6, 2, 8, 4}
        //     Indexes:  0   1   2  3  4  5  6  7  8  9
        list.add(5);
        list.add(10);
        list.add(11);
        list.add(7);
        list.add(1);
        list.add(9);
        list.add(6);
        list.add(2);
        list.add(8);
        list.add(4);
    
        System.out.println(list);
    
        // Remove element at index of 2 in the arraylist which is 11
        // ArrayList: {5, 10, 7, 1, 9, 6, 2, 8, 4}
        //     Indexes:  0   1  2  3  4  5  6  7  8
        list.remove(2);
        System.out.println(list);
    
        // Insert 3 at the index of 5 so it is between 9 and 6
        // ArrayList: {5, 10, 7, 1, 9, 3, 6, 2, 8, 4}
        //     Indexes:  0   1  2  3  4  5  6  7  8  9
        list.insert(3, 5);
        System.out.println(list);
    
        // Size: 10
        System.out.println("Size: " + list.size());
    
        // Reversed order of elements
        // ArrayList: {4, 8, 2, 6, 3, 9, 1, 7, 10, 5}
        //     Indexes:  0  1  2  3  4  5  6  7   8  9
        list.reverse();
        System.out.println(list);
    
        // Sort arraylist
        // ArrayList: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        //     Indexes:  0  1  2  3  4  5  6  7  8   9
        list.sort(0, list.size() - 1);
        System.out.println(list);
    
        // Get value at 4th index of arraylist which is 5
        // ArrayList: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        //     Indexes:  0  1  2  3 (4)  5  6  7  8   9
        System.out.println("list[4] = " + list.get(4));
    }
}