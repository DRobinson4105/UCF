// David Robinson
// P5 - Shortcodes
// Arup Guha
// 03/07/24
// I solved all 3 tasks

import java.io.*;
import java.util.*;

/*
 * Part 1:
 * Build a network flow graph with source to each drug, each code to sink, and each drug to each
 * code that is a substring of that drug. Each edge will have a capacity of one and the maximum
 * flow will show how many drugs can have unique codes so a maximum flow of n means that every drug
 * has a unique code.
 * 
 * Part 2-3:
 * If there is a maximum flow of n, then every drug can have a unique code. To guarantee a mapping
 * of each drug to a specific code, we need to ensure that a graph constructed with drugs only
 * connected to their mapped code will still have a maximum flow of n. To find the first
 * lexicographical mapping, we will first sort the codes so that the first valid code will be the
 * first lexicograpgical one. Then, we will iterate through the drugs and find the first code that
 * when the drug is not pointing to any other code, there is still a max flow of n. Once that code
 * is found, keep the graph with the drug only pointing to that code since that code will be used
 * and move on to the next drug.
 */

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
        Dinic dinic;

        int n = scan.nextInt(); int m = scan.nextInt();
        int source = n + m, sink = n + m + 1;
        dinic = new Dinic(n + m);

        // get input
        for (int i = 0; i < n; i++) {
            String str = scan.next();
            drugs.add(str);
        }

        for (int i = 0; i < m; i++) {
            String str = scan.next();
            codes.add(str);
        }

        // sort codes since we want the first lexicographical one
        Collections.sort(codes);

        for (int i = 0; i < n; i++) {
            // add edge from source to each drug
            dinic.add(source, i, 1, 0);

            for (int j = 0; j < m; j++) {
                // if current code is a substring of the current drug, add an edge from the drug to
                // the code
                if (drugs.get(i).contains(codes.get(j)))
                    dinic.add(i, j + n, 1, 0);
            }
        }

        // add edge from each code to sink
        for (int i = 0; i < m; i++)
            dinic.add(i + n, sink, 1, 0);

        if (dinic.flow() == n) {
            System.out.println("yes");

            for (int i = 0; i < n; i++) {
                // remove all edges from current drug to codes
                for (Edge edge : dinic.adj[i]) edge.cap = 0;

                // loop through codes
                for (int j = 0; j < m; j++) {
                    int idx = -1;
                    for (int k = 0; k < dinic.adj[i].size() && idx == -1; k++)
                        if (dinic.adj[i].get(k).v2 == (j + n)) idx = k;

                    // if code can't be used for drug
                    if (idx == -1) continue;

                    // test drug with code
                    dinic.adj[i].get(idx).cap = 1;

                    // if current drug can be used with current code with every other drug having a
                    // unique code, use it and move on to the next drug
                    if (dinic.flow() == n) {
                        System.out.println(codes.get(j));
                        break;
                    }

                    // this code is not the one to use for this drug so remove the edge
                    dinic.adj[i].get(idx).cap = 0;
                }
            }
        } else {
            System.out.println("no");
        }
    }
}