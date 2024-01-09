import java.util.Scanner;
import java.util.HashMap;

public class sga {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        Long total = 0L;
        int[] firstLetters = new int[26];
        HashMap<String, Integer> freq = new HashMap<String, Integer>();
        String[] names = new String[n];

        scan.nextLine();

        for (int i = 0; i < n; i++) {
            String s = scan.nextLine();
            names[i] = s;
            firstLetters[s.charAt(0) - 'A']++;
            Integer val = freq.get(s);
            if (val != null) {
                freq.put(s, val + 1);
            } else {
                freq.put(s, 1);
            }
        }

        for (int i = 0; i < n; i++) {
            total += firstLetters[names[i].charAt(0) - 'A'] - freq.get(names[i]);
        }

        System.out.println(total);
        scan.close();
    }
}