import java.util.*;
import java.io.*;

public class dyslectionary {
    // reverses a string
    private static String reverse(String s) {
        char[] res = new char[s.length()];

        for (int i = s.length() - 1; i >= 0; i--) {
            res[s.length() - 1 - i] = s.charAt(i);
        }

        return new String(res);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<String> pq = new PriorityQueue<String>();
        String curr;
        int highest;
        boolean notFirst = false;
        
        do {
            highest = 0; // track the length of the largest string
            if (notFirst) System.out.println(); // space out the answers
            notFirst = true;

            // reverse the strings and add them to a priority
            // queue to sort them in a reversed order
            while ((curr = stdin.readLine()) != null && curr.length() > 0) {
                pq.add(reverse(curr));
                highest = Math.max(highest, curr.length());
            }    

            // print the strings
            while (!pq.isEmpty()) {
                String top = pq.peek(); pq.remove();

                // add enoguh spaces before each string so they all have the same length
                int diff = highest - top.length();
                while (diff-- > 0)
                    System.out.print(" ");
                
                // reverse the string back and print it
                System.out.println(reverse(top));
            }
        } while (curr != null);
    }
}