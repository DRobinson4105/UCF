import java.util.*;
import java.io.*;
import static java.lang.Math.*;

class DS {
    int arr[];
    long num = 0, den = 0;

    DS(int n) {
        arr = new int[n];
        num = den = n;
        for (int i = 0; i < n; i++)
            arr[i] = -1;
    }

    int find(int x) {
        return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
    }

    void merge(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        
        if (p1 == p2) return;

        // add new connectivity (sum of both sizes^2) and subtract old connectivity for the two
        // old sets (size of each set^2) from the numerator
        num += (long)(arr[p1] + arr[p2]) * (arr[p1] + arr[p2]) - 
            (long)arr[p1] * arr[p1] - (long)arr[p2] * arr[p2];

        // decrement the denominator since there is now one less disjoint set
        den--;

        arr[p1] += arr[p2];
        arr[p2] = p1;
    }
}

public class connect {
    static long euclids(long a, long b) {
        if (b == 0) return a;
        return euclids(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(stdin.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());

        DS ds = new DS(n);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(stdin.readLine());
            int op = Integer.parseInt(st.nextToken());

            switch (op) {
                case 1:
                    // connect the two computers
                    ds.merge(Integer.parseInt(st.nextToken()) - 1, 
                        Integer.parseInt(st.nextToken()) - 1);
                    break;
                case 2:
                    // find the greatest common factor to simplify the
                    // fraction and print out the simplified fraction
                    long gcf = euclids(ds.num, ds.den);
                    sb.append(ds.num / gcf); sb.append("/");
                    sb.append(ds.den / gcf); sb.append("\n");
                    break;
            }
        }

        System.out.print(sb);
    }
}