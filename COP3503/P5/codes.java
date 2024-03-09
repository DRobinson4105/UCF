// David Robinson
// P5 - Shortcodes
// Arup Guha
// 03/07/24
// I solved all 3 tasks

import java.io.*;
import java.util.*;

public class codes {
    // An edge connects v1 to v2 with a capacity of cap, flow of flow.
    static class Edge {
        int v1, v2, cap, flow;
        Edge rev;
        Edge(int V1, int V2, int Cap, int Flow) {
            v1 = V1;
            v2 = V2;
            cap = Cap;
            flow = Flow;
        }
    }

    static class Dinic {

        // Queue for the top level BFS.
        public ArrayDeque<Integer> q;

        // Stores the graph.
        public ArrayList<Edge>[] adj;
        public int n;

        // s = source, t = sink
        public int s;
        public int t;


        // For BFS.
        public boolean[] blocked;
        public int[] dist;

        final public static int oo = (int)1E9;

        @SuppressWarnings("unchecked")
        // Constructor.
        public Dinic (int N) {

            // s is the source, t is the sink, add these as last two nodes.
            n = N; s = n++; t = n++;

            // Everything else is empty.
            blocked = new boolean[n];
            dist = new int[n];
            q = new ArrayDeque<Integer>();
            adj = new ArrayList[n];
            for(int i = 0; i < n; ++i)
                adj[i] = new ArrayList<Edge>();
        }

        // Just adds an edge and ALSO adds it going backwards.
        public void add(int v1, int v2, int cap, int flow) {
            Edge e = new Edge(v1, v2, cap, flow);
            Edge rev = new Edge(v2, v1, 0, 0);
            adj[v1].add(rev.rev = e);
            adj[v2].add(e.rev = rev);
        }

        public void remove(int v1, int v2) {
            boolean stop = true;
            for (int i = 0; i < adj[v1].size(); i++) {
                if (adj[v1].get(i).v2 == v2) {
                    stop = false;
                    adj[v1].remove(i);
                    break;
                }
            }

            if (stop) return;

            for (int i = 0; i < adj[v2].size(); i++) {
                if (adj[v2].get(i).v2 == v1) {
                    adj[v2].remove(i);
                    return;
                }
            }
        }

        // Runs other level BFS.
        public boolean bfs() {

            // Set up BFS
            q.clear();
            Arrays.fill(dist, -1);
            dist[t] = 0;
            q.add(t);

            // Go backwards from sink looking for source.
            // We just care to mark distances left to the sink.
            while(!q.isEmpty()) {
                int node = q.poll();
                if(node == s)
                    return true;
                for(Edge e : adj[node]) {
                    if(e.rev.cap > e.rev.flow && dist[e.v2] == -1) {
                        dist[e.v2] = dist[node] + 1;
                        q.add(e.v2);
                    }
                }
            }

            // Augmenting paths exist iff we made it back to the source.
            return dist[s] != -1;
        }

        // Runs inner DFS in Dinic's, from node pos with a flow of min.
        public int dfs(int pos, int min) {

            // Made it to the sink, we're good, return this as our max flow for the augmenting path.
            if(pos == t)
                return min;
            int flow = 0;

            // Try each edge from here.
            for(Edge e : adj[pos]) {
                int cur = 0;

                // If our destination isn't blocked and it's 1 closer to the sink and there's flow, we
                // can go this way.
                if(!blocked[e.v2] && dist[e.v2] == dist[pos]-1 && e.cap - e.flow > 0) {

                    // Recursively run dfs from here - limiting flow based on current and what's left on this edge.
                    cur = dfs(e.v2, Math.min(min-flow, e.cap - e.flow));

                    // Add the flow through this edge and subtract it from the reverse flow.
                    e.flow += cur;
                    e.rev.flow = -e.flow;

                    // Add to the total flow.
                    // System.out.println(e.v1 + " " + e.v2);
                    flow += cur;
                }

                // No more can go through, we're good.
                if(flow == min)
                    return flow;
            }

            // mark if this node is now blocked.
            blocked[pos] = flow != min;

            // This is the flow
            return flow;
        }

        public int flow() {
            clear();
            int ret = 0;

            // Run a top level BFS.
            while(bfs()) {

                // Reset this.
                Arrays.fill(blocked, false);

                // Run multiple DFS's until there is no flow left to push through.
                ret += dfs(s, oo);
            }
            return ret;
        }

        // Just resets flow through all edges to be 0.
        public void clear() {
            for(ArrayList<Edge> edges : adj)
                for(Edge e : edges)
                    e.flow = 0;
        }
    }

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
        List<String> drugs = new ArrayList<>();
        List<String> codes = new ArrayList<>();
        Map<Integer, Set<Integer>> map = new HashMap<>();
        Dinic netFlow;

        int n = scan.nextInt(); int m = scan.nextInt();
        int source = n + m, sink = n + m + 1;
        netFlow = new Dinic(n + m);

        // get input
        for (int i = 0; i < n; i++) {
            String str = scan.next();
            drugs.add(str);
            map.put(i, new HashSet<>());
        }

        for (int i = 0; i < m; i++) {
            String str = scan.next();
            codes.add(str);
        }

        // sort codes since we want the first lexicographical one
        Collections.sort(codes);

        for (int i = 0; i < n; i++) {
            // add edge from source to each drug
            netFlow.add(source, i, 1, 0);

            for (int j = 0; j < m; j++) {
                // if current code is a substring of the current drug, add an edge from the drug to
                // the code
                if (drugs.get(i).contains(codes.get(j))) {
                    map.get(i).add(j);
                    netFlow.add(i, j + n, 1, 0);
                }
            }
        }

        // add edge from each code to sink
        for (int i = 0; i < m; i++) {
            netFlow.add(i + n, sink, 1, 0);
        }

        int flow = netFlow.flow();
        if (flow == n) {
            System.out.println("yes");
            Set<Integer> used = new HashSet<>();
            List<Integer> result = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                @SuppressWarnings("unchecked")
                ArrayList<Edge>[] old = new ArrayList[n + m + 2];

                // store original graph so that changes made are not brought to next iteration
                for (int j = 0; j < n + m + 2; j++)
                    old[j] = new ArrayList<>(netFlow.adj[j]);

                // remove all edges from current drug to codes
                for (int j = n; j < source; j++)
                    netFlow.remove(i, j);

                // try adding an edge to each code sorted in lexicographical order and test max
                // flow for each code, stopping when a flow of n is found. That code will be used
                // for the current drug so add it to the used set and resulting list.
                for (int j = 0; j < m; j++) {
                    if (!map.get(i).contains(j) || used.contains(j)) continue;

                    netFlow.add(i, j + n, 1, 0);
                    flow = netFlow.flow();
                    netFlow.remove(i, j + n);

                    if (flow == n) {
                        used.add(j);
                        result.add(j);
                        break;
                    }
                }

                // clear all changes made to the graph
                netFlow.adj = old;
            }

            for (int idx : result) System.out.println(codes.get(idx));
        } else {
            System.out.println("no");
        }
    }
}