public class ArrayList
{
    private int [] array;
    private int size;
    private int capacity;

    // Starting capacity of array if not provided
    public static int DEFAULT_SIZE = 5;

    // Initialize arraylist with default size
    ArrayList()
    {
        this(DEFAULT_SIZE);
    }

    // Initialize arraylist with given size
    ArrayList(int initialCapacity)
    {
        array = new int[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    // Multiplies the capacity of the arraylist by 2
    private void expand()
    {
        // Create new array with doubled size
        int [] temp = new int[2 * capacity];
        
        // Add all elements from old array to new array
        for(int i = 0; i < size; i++)
            temp[i] = array[i];

        // Replace old array and capacity with new array and capacity
        array = temp;
        capacity = 2 * capacity;
    }

    // Adds value to end of array
    public void add(int value)
    {
        // If the array is full, double the capacity
        if(size >= capacity)
            expand();

        // Add value to end of array and increase size
        array[size] = value;
        size++;
    }
    
    // Returns number of elements in arraylist
    public int size()
    {
        return size;
    }

    // Adds value at specific index in the array
    public void insert(int value, int index)
    {
        // If the array is full, double the capacity
        if(size >= capacity)
            expand();
        
        // Shift all elements to the right of index by one
        for(int i = size; i > index; i--)
            array[i] = array[i - 1];

        // Insert value
        array[index] = value;
        size++;
    }

    // Remove element at specific index in the array
    public void remove(int index)
    {
        // Shift all elements to the right of index down by one
        for(int i = index; i < size - 1; i++)
            array[i] = array[i + 1];

        // Decrease size
        size--;
    }

    // Reverse order of elements in the list
    public void reverse()
    {
        // Temp variable for swapping
        int temp;

        // Swap outer pairs of elements until middle is reached
        for(int i = 0; i < size / 2; i++)
        {
            temp = array[i];
            array[i] = array[size - 1 - i];
            array[size - 1 - i] = temp;
        }
    }

    // Repeatedly splits array until each subarray has a 
    // length of one and then merges and sorts the subarrays
    // array[] --> Array to be sorted
    // L --> Starting index
    // R --> Ending index
    public void sort(int L, int R)
    {
        if(L < R)
        {
            int M = L + (R - L) / 2;

            // Sort left and right halves of array
            sort(L, M);
            sort(M + 1, R);

            // Merge both halves together
            merge(L, R, M);
        }
    }

    // Merges and sorts two subarrays of elements where 
    // first subarray is array[L..M] and second subarray 
    // is array[M+1..R]
    // array[] --> Array to be sorted
    // L --> Starting index
    // R --> Ending index
    // M --> Midpoint between L and R
    private void merge(int L, int R, int M)
    {
        int length1 = M - L + 1;
        int length2 = R - M;
    
        // Create temp arrays for left and right subarrays
        int[] arrL = new int[length1];
        int[] arrR = new int[length2];
    
    
        // Copy left and right subarray elements into temp arrays
        for(int i = 0; i < length1; i++)
            arrL[i] = array[i + L];
    
        for(int i = 0; i < length2; i++)
            arrR[i] = array[M + 1 + i];
    
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        int k = L; // Initial index of merged subarray
        
        // Merge temp arrays back into array[L..R]
        while (i < length1 && j < length2)
        {
            // If arrL[i] is less than or equal to arrR[j] then add arrL[i] to the 
            // next index in the merged subarray and move to the next value in arrL[]
            if (arrL[i] <= arrR[j])
            {
                array[k] = arrL[i];
                i++;
            }
            else
            {
                array[k] = arrR[j];
                j++;
            }
            
            k++;
        }
        
        // Copy any remaining elements in arrL[]
        while (i < length1)
        {
            array[k] = arrL[i];
            i++;
            k++;
        }
     
        // Copy any remaining elements in arrR[]
        while (j < length2)
        {
            array[k] = arrR[j];
            j++;
            k++;
        }
    }

    // Get value at specific index in array
    public int get(int index)
    {
        return array[index];
    }

    // String format for array [n1, n2, ...]
    public String toString()
    {
        String s = "[";

        for(int i = 0; i < size; i++)
        {
            s += array[i];
            if(i < size - 1)
                s += ", ";
        }

        return s + "]";
    }
}