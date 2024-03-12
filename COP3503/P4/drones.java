import java.util.LinkedList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class drones {
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

    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        FastScanner scan = new FastScanner(System.in);
        LinkedList<Integer> queue = new LinkedList<>();
        int distances[] = new int[1 << 24];

        for (int i = (1 << 24) - 1; i >= 0; i--)
            distances[i] = -1;
    
        int n = scan.nextInt();
        int curr = 0;
        boolean noFlyZones[] = new boolean[64];
        int answer = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                String str = scan.next();

                if (str.equals("XX")) {
                    // no fly zone
                    noFlyZones[(i << 3) + j] = true;
                } else if (str.startsWith("D")) {
                    // set drone's position
                    int drone = str.charAt(1) - '0' - 1;
                    curr = curr | ((i << 3) + j) << (drone * 6);
                } else if (str.startsWith("G")) {
                    // set destination's position
                    int drone = str.charAt(1) - '0' - 1;
                    answer = answer | ((i << 3) + j) << (drone * 6);

                    // destinations are treated as no fly zones for all drones except for the drone
                    // delivering to it, which is handled before checking no fly zone
                    noFlyZones[(i << 3) + j] = true;
                }
            }
        }

        queue.add(curr);
        distances[curr] = 0;
        while (!queue.isEmpty()) {
            curr = queue.poll();

            // reached destination
            if (curr == answer) {
                System.out.println(distances[curr]);
                return;
            }

            // each direction
            for (int k = 0; k < 4; k++) {
                int next = 0;
                // update each drone
                for (int i = n - 1; i >= 0; i--) {
                    int pos = (curr >> (i * 6)) & 63;

                    // if current drone has already reached its destination
                    if (pos == ((answer >> (i * 6)) & 63)) {
                        next = (next << 6) + pos;
                        continue;
                    }

                    // get next column and row from current position
                    int nr = ((pos >> 3) & 7) + dx[k], nc = (pos & 7) + dy[k];
                    int nPos = (nr << 3) + nc;

                    // if next position is invalid, keep old position
                    if (nr == -1 || nr == 8 || nc == -1 || nc == 8) {
                        next = (next << 6) + pos;
                        continue;
                    }

                    // if next position is a no fly zone for this drone, keep old position
                    if (nPos != ((answer >> (i * 6)) & 63) && noFlyZones[(nr << 3) + nc]) {
                        next = (next << 6) + pos;
                        continue;
                    }

                    // use new position
                    next = (next << 6) + nPos;
                }

                // if the next position has not been visited yet or if this path is better than the
                // best path to the next position
                if (distances[next] == -1 || distances[next] > distances[curr] + 1) {
                    distances[next] = distances[curr] + 1;
                    queue.add(next);
                }
            }
        }

        System.out.println(-1);
    }
}