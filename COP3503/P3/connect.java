import java.util.*;

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

        arr[p1] += arr[p2];
        arr[p2] = p1;
        
        // add new connectivity (sum of both sizes^2) and subtract old connectivity for the two
        // old sets (size of each set^2) from the numerator
        num += Math.pow(arr[p1] + arr[p2], 2) - Math.pow(arr[p1], 2) - Math.pow(arr[p2], 2);

        // decrement the denominator since there is now one less disjoint set
        den--;
    }
}

public class connect {
    static long euclids(long a, long b) {
        if (b == 0) return a;
        return euclids(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(), m = scan.nextInt();

        DS ds = new DS(n);

        for (int i = 0; i < m; i++) {
            int op = scan.nextInt();
            switch (op) {
                case 1:
                    // connect the two computers
                    ds.merge(scan.nextInt() - 1, scan.nextInt() - 1);
                    break;
                case 2:
                    // find the greatest common factor to simplify the
                    // fraction and print out the simplified fraction
                    long gcf = euclids(ds.num, ds.den);
                    System.out.println((ds.num / gcf) + "/" + (ds.den / gcf));
                    break;
            }
        }

        scan.close();
    }
}