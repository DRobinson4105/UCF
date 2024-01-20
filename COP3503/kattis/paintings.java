import java.util.*;
import java.io.*;

public class paintings {
    private static String[] best;
    private static int compute(
        String colors[], String res[], boolean used[], 
        HashMap<String, Set<String>> notAllowed, int curr, int n
    ) {
        if (curr == n) {
            // current order of colors is most preferred if this is the first order found
            if (best == null) {
                best = new String[n];
                for (int i = 0; i < n; i++)
                    best[i] = res[i];
            }
            
            return 1;
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            // if current color has already been used or cant be next to the previous used color
            if (used[i] || (curr != 0 && notAllowed.get(res[curr - 1]) != null && 
                notAllowed.get(res[curr - 1]).contains(colors[i]))) continue;
            
            used[i] = true;
            res[curr] = colors[i];
            total += compute(colors, res, used, notAllowed, curr + 1, n);
            used[i] = false;
        }

        return total;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(stdin.readLine());

        while (t-- != 0) {
            int n = Integer.parseInt(stdin.readLine());
            String colors[] = new String[n];
            String res[] = new String[n];
            boolean used[] = new boolean[n];
            HashMap<String, Set<String>> notAllowed = new HashMap<String, Set<String>>();

            // get colors
            StringTokenizer st = new StringTokenizer(stdin.readLine());
            for (int i = 0; i < n; i++)
                colors[i] = st.nextToken();
            
            // find all pairs of colors that cant be next to each other
            int m = Integer.parseInt(stdin.readLine());
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(stdin.readLine());
                String first = st.nextToken(), second = st.nextToken();

                if (!notAllowed.containsKey(first))
                    notAllowed.put(first, new HashSet<String>());
                if (!notAllowed.containsKey(second))
                    notAllowed.put(second, new HashSet<String>());

                notAllowed.get(first).add(second);
                notAllowed.get(second).add(first);
            }
            
            // print all possible orders and the most preferred order
            best = null;
            System.out.println(compute(colors, res, used, notAllowed, 0, n));
            for (String s : best)
                System.out.print(s + " ");
            System.out.println();
        }
    }
}
