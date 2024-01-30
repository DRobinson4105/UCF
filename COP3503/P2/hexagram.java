import java.util.*;
import java.io.*;

/* 
The six rows in the hexagram:
- 0 2 5 7
- 0 3 6 10
- 1 2 3 4
- 1 5 8 11
- 7 8 9 10
- 4 6 9 11
 */

public class hexagram {
    private static int compute(int perm[], int nums[], boolean used[], int curr, int target) {
        // Check if the hexagram is now invalid
        if (
            (curr == 5 && perm[1] + perm[2] + perm[3] + perm[4] != target) ||
            (curr == 8 && perm[0] + perm[2] + perm[5] + perm[7] != target) ||
            (curr == 11 && perm[0] + perm[3] + perm[6] + perm[10] != target) ||
            (curr == 11 && perm[7] + perm[8] + perm[9] + perm[10] != target) ||
            (curr == 12 && perm[1] + perm[5] + perm[8] + perm[11] != target) ||
            (curr == 12 && perm[4] + perm[6] + perm[9] + perm[11] != target)
        ) return 0;
        
        // Check if hexagram is complete
        if (curr == 12) return 1;

        int total = 0;
        
        // Find all possible hexagrams using the current hexagram
        for (int i = 0; i < 12; i++) {
            if (used[i]) continue;
            used[i] = true;
            perm[curr] = nums[i];
            total += compute(perm, nums, used, curr + 1, target);
            used[i] = false;
        }

        return total;
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int nums[] = new int[12];
        boolean used[] = new boolean[12];
        int perm[] = new int[12];

        while ((nums[0] = scan.nextInt()) != 0) {
            int target = nums[0];
            for (int i = 1; i < 12; i++)
                target += nums[i] = scan.nextInt();
            
            target *= 2;

            // Sum of all rows is 2 * (sum of all values), if the sum of all rows
            // can't be divided by 6, then the rows will never have equal values
            if (target % 6 != 0) {
                System.out.println(0);
                continue;
            }

            target /= 6;
            for (int i = 0; i < 12; i++) used[i] = false;
            
            // Divide result by 12 to remove reflections and rotations
            // since there is 12 ways to display a hexagrams
            System.out.println(compute(perm, nums, used, 0, target) / 12);
        }
    }
}
