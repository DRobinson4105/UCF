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
        List<String> strings = new ArrayList<String>();
        String curr;
        boolean notFirst = false;
        
        do {
            int highest = 0; // track the length of the largest string
            if (notFirst) System.out.println(); // space out the answers
            notFirst = true;

            // add the strings to list and track the length of the largest string
            while ((curr = stdin.readLine()) != null && curr.length() > 0) {
                strings.add(curr);
                highest = Math.max(highest, curr.length());
            }

            // sort the strings based off of their reversed characters
            Collections.sort(strings, (String s1, String s2) -> {
                return reverse(s1).compareTo(reverse(s2));
            });

            // print the strings
            for (String s : strings) {
                // add enoguh spaces before each string so they all have the same length
                int diff = highest - s.length();
                while (diff-- > 0)
                    System.out.print(" ");

                System.out.println(s);
            }
            strings.clear();
        } while (curr != null);
    }
}