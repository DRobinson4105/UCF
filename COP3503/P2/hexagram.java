import java.util.*;
import java.io.*;

/* 
1 3 6 8     - 0 2 5 7
1 4 7 11    - 0 3 6 10
2 3 4 5     - 1 2 3 4
2 6 9 12    - 1 5 8 11
8 9 10 11   - 7 8 9 10
5 7 10 12   - 4 6 9 11
 */

public class hexagram {
    private static int compute(int res[], int nums[], boolean used[], int curr, int target) {
        if (
            (curr == 5 && res[1] + res[2] + res[3] + res[4] != target) ||
            (curr == 8 && res[0] + res[2] + res[5] + res[7] != target) ||
            (curr == 11 && res[0] + res[3] + res[6] + res[10] != target) ||
            (curr == 11 && res[7] + res[8] + res[9] + res[10] != target) ||
            (curr == 12 && res[1] + res[5] + res[8] + res[11] != target) ||
            (curr == 12 && res[4] + res[6] + res[9] + res[11] != target)
        ) return 0;
        
        if (curr == 12) return 1;

        int total = 0;
        
        for (int i = 0; i < 12; i++) {
            if (used[i]) continue;
            used[i] = true;
            res[curr] = nums[i];
            total += compute(res, nums, used, curr + 1, target);
            used[i] = false;
        }

        return total;
    }
    
    public static void main(String[] args) {
        // BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        Scanner scan = new Scanner(System.in);

        int nums[] = new int[12];

        while ((nums[0] = scan.nextInt()) != 0) {
            int target = nums[0];
            for (int i = 1; i < 12; i++)
                target += nums[i] = scan.nextInt();
            
            if (target % 3 != 0) {
                System.out.println(0);
                continue;
            }
            target /= 3;
            boolean used[] = new boolean[12];
            for (int i = 0; i < 12; i++) used[i] = false;
            int res[] = new int[12];

            System.out.println(compute(res, nums, used, 0, target) / 12);
        }
    }
}
