// David Robinson
// P6 - DP Sum Problem B
// Arup Guha
// 03/26/24

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class subseqsum {
    static class FastScanner { 
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
            st = new StringTokenizer("");
        }

        public String next() throws IOException {
            if (st.hasMoreTokens()) return st.nextToken();
            
            st = new StringTokenizer(br.readLine());
            return next();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner scan = new FastScanner(System.in);
        int n = scan.nextInt(), k = scan.nextInt();
        int[] nums = new int[n];
        long[] dp = new long[n];
        int[] indices = new int[n];

        for (int i = 0; i < n; i++) nums[i] = scan.nextInt();

        for (int i = 0; i < n; i++) {
            long best = 0;
            int bestIdx = -1;

            for (int j = 0; j < i; j++) {
                if (Math.abs(nums[i] - nums[j]) <= k && dp[j] > best) {
                    best = dp[j];
                    bestIdx = j;
                }
            }

            dp[i] = best + nums[i];
            indices[i] = bestIdx;

        }

        long highest = 0;
        int highestIdx = -1;

        for (int i = 0; i < n; i++) {
            if (dp[i] > highest) {
                highest = dp[i];
                highestIdx = i;
            }
        }

        System.out.println(highest);
        
        List<Integer> result = new ArrayList<>();
        while (highestIdx >= 0) {
            result.add(0, highestIdx + 1);
            highestIdx = indices[highestIdx];
        }

        for (int idx : result)
            System.out.print(idx + " ");

        System.out.println();
    }
}
