import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class drones {
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        LinkedList<Integer> queue = new LinkedList<>();
        int distances[] = new int[1 << 24];
        boolean visited[] = new boolean[1 << 24];

        for (int i = 1 << 24 - 1; i >= 0; i--) {
            distances[i] = 0;
            visited[i] = false;
        }
    
        int n = Integer.parseInt(stdin.readLine());
        int curr = 0;
        boolean noFlyZones[] = new boolean[64];
        int answer = 0;

        for (int i = 0; i < 8; i++) {
            st = new StringTokenizer(stdin.readLine());

            for (int j = 0; j < 8; j++) {
                String str = st.nextToken();
                
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
        while (!queue.isEmpty()) {
            curr = queue.poll();

            // reached destination
            if (curr == answer) {
                System.out.println(distances[curr]);
                return;
            }
            
            // if this position has already been checked
            if (visited[curr]) continue;
            visited[curr] = true;

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
                //  best path to the next position
                if (distances[next] == 0 || distances[next] > distances[curr] + 1) {
                    distances[next] = distances[curr] + 1;
                    queue.add(next);
                }

            }
        }

        System.out.println(-1);
    }
}
