import java.util.*;
import java.io.*;

public class sga {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(stdin.readLine());
        Long total = 0L; // total number of pairs
        String[] names = new String[n];
        
        // Tracks the count of words that start with each letter
        int[] firstLetters = new int[26];
        // Tracks the count of each words
        HashMap<String, Integer> freq = new HashMap<String, Integer>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(stdin.readLine());
            String s = st.nextToken();
            names[i] = s;

            firstLetters[s.charAt(0) - 'A']++;

            Integer count = freq.get(s);
            if (count != null) freq.put(s, count + 1);
            else freq.put(s, 1);
        }
        
        // Add all possible pairs for each of the names being the president
        for (int i = 0; i < n; i++)
            total += firstLetters[names[i].charAt(0) - 'A'] - freq.get(names[i]);

        System.out.println(total);
    }
}