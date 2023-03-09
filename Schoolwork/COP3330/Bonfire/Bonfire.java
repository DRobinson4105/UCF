// David Robinson
// COP 3330, Spring 2023
// da034737

public class Bonfire
{
    public static boolean containsValueAfterIndex(int needle, int[] haystack, int index)
    {
        if(index < -1) // if the inputed index is invalid
            return false;
        
        // start from index after inputed index and check every index until end of arra
        for(int i = index + 1; i < haystack.length; i++)
        {
            if(haystack[i] == needle)
                return true;
        }

        return false;
    }

    public static int getThirdLargest(int[] array)
    {
        int max = 0;

        if(array.length < 3) // if the array size is smaller than 3
            return Integer.MIN_VALUE;

        for(int i = 0; i < array.length; i++) // check for highest value
        {
            if(array[i] > array[max])
                max = i;
        }

        array[max] = '\0';
        max = -1;
        
        for(int i = 0; i < array.length; i++) // check for second highest value
        {
            if(array[i] != '\0' && (max == -1 || array[i] > array[max]))
                max = i;
        }

        array[max] = '\0';
        max = -1;
        
        for(int i = 0; i < array.length; i++) // check for third highest value
        {
            if(array[i] != '\0' && (max == -1 || array[i] > max))
                max = array[i];
        }

        return max;
    }

    public static void printThirdLargest(int[] array)
    {
        System.out.println(getThirdLargest(array));
    }

    public static boolean isRotation(int[] array1, int[] array2)
    {
        if(array1.length != array2.length)
            return false;

        boolean flag;

        if(array1.length == 0) // if both of the arrays are empty
            return true;

        for(int i = 0; i < array1.length; i++) // check every possible rotation
        {
            flag = true;

            for(int j = 0; j < array1.length; j++) // for each rotation, check if the two arrays match
            {
                if(array1[(j + i) % array1.length] != array2[j])
                    flag = false;
            }

            if(flag) // if the arrays match in the current rotation
                return true;
        }

        return false;
    }

    public static int[] generateNthRotation(int[] array, int n)
    {
        int[] rotatedArray = new int[array.length];

        for(int i = 0; i < array.length; i++) // rotate each index by the nth amount
            rotatedArray[((i + n) % array.length + array.length) % array.length] = array[i];

        return rotatedArray;
    }

    public static void printRibbon(int n, int width)
    {
        printBorder(width); // top line
        
        // create a ribbon line with 3n length
        String ribbon = "";
        ribbon += charNTimes('@', n);
        ribbon += charNTimes('o', n);
        ribbon += charNTimes('@', n);

        for(int i = width; i > 0; i--)
        {
            System.out.print('|'); // start row

            for(int j = 0; j < width - i; j++) // any spaces before ribbon
                System.out.print(' ');
            
            System.out.print(ribbon.substring(0, (i > ribbon.length()) ? ribbon.length() : i)); // ribbon

            for(int j = 0; j < ((i - ribbon.length() > 0) ? i - ribbon.length() : 0); j++) // any spaces after ribbon
                System.out.print(' ');
            
            System.out.println('|'); // end row
        }

        printBorder(width); // bottom line
    }

    public static void printBorder(int width)
    {
        System.out.print('+');

        for(int i = 0; i < width; i++)
            System.out.print('-');

        System.out.println('+');
    }

    public static String charNTimes(char c, int n)
    {
        String line = "";

        for(int i = 0; i < n; i++)
            line += c;

        return line;
    }

    public static double difficultyRating()
    {
        return 3;
    }

    public static double hoursSpent()
    {
        return 4;
    }
}