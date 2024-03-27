// David Robinson
// P6 - DP Sum Problem A
// Arup Guha
// 03/26/24

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class gcdsum {
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

    static long gcd(long a, long b) {
        if (a < b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        FastScanner scan = new FastScanner(System.in);
        int n = scan.nextInt(), k = scan.nextInt();
        int[] nums = new int[n];
        long[][] dp = new long[k][n];
        int[][] indices = new int[k][n];

        for (int i = 0; i < n; i++) nums[i] = scan.nextInt();

        dp[0][0] = nums[0];

        for (int i = 1; i < n; i++)
            dp[0][i] = gcd(nums[i], dp[0][i-1]);

        for (int i = 1; i < k; i++) {
            for (int j = i; j < n; j++) {
                long best = 0;
                long curr = nums[j];

                for (int m = j-1; m >= 0; m--) {
                    if (best < curr + dp[i-1][m]) {
                        best = curr + dp[i-1][m];
                        indices[i][j] = m + 1;
                    }

                    curr = gcd(curr, nums[m]);
                }

                dp[i][j] = best;
            }
        }

        System.out.println(dp[k-1][n-1]);
        int[] partitions = new int[k];
        int index = n - 1, currentK = k-1;
        while (currentK >= 0) {
            partitions[currentK] = indices[currentK][index] + 1;
            index = indices[currentK][index] - 1;
            currentK--;
        }

        for (int i = 0; i < k; i++)
            System.out.print(partitions[i] + " ");
        
        System.out.println();
    }
}
