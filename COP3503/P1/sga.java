import java.util.Scanner;
import java.util.HashMap;

public class sga {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        Long total = 0L; // total number of pairs
        String[] names = new String[n];
        
        // Tracks the count of words that start with each letter
        int[] firstLetters = new int[26];
        // Tracks the count of each words
        HashMap<String, Integer> freq = new HashMap<String, Integer>();

        scan.nextLine();

        for (int i = 0; i < n; i++) {
            String s = scan.nextLine();
            names[i] = s;

            firstLetters[s.charAt(0) - 'A']++;

            Integer val = freq.get(s);
            if (val != null) freq.put(s, val + 1);
            else freq.put(s, 1);
        }
        
        // Add all possible pairs for each of the names being the president
        for (int i = 0; i < n; i++)
            total += firstLetters[names[i].charAt(0) - 'A'] - freq.get(names[i]);

        System.out.println(total);
        scan.close();
    }
}