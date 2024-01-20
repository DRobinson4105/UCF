import java.util.*;
import java.io.*;

public class dobra {
    private static boolean isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    private static boolean isPleasant(char[] word) {
        boolean containsL = false;
        int vowelsInRow = 0, consonantsInRow = 0;

        for (char c : word) {
            if (c == 'L') containsL = true;

            if (isVowel(c)) {
                vowelsInRow++;
                consonantsInRow = 0;
            } else {
                consonantsInRow++;
                vowelsInRow = 0;
            }

            if (vowelsInRow == 3 || consonantsInRow == 3) return false;
        }

        return containsL;
    }

    private static long compute(char[] word, int index) {
        if (index == word.length) return isPleasant(word) ? 1 : 0;

        // Current character cant be changed
        if (word[index] != '_') return compute(word, index + 1);

        long res = 0;

        // Use L
        word[index] = 'L';
        res += compute(word, index + 1);
        word[index] = '_';

        // Use vowel
        word[index] = 'A';
        res += 5 * compute(word, index + 1);
        word[index] = '_';

        // Use consonant thats not L
        word[index] = 'B';
        res += 20 * compute(word, index + 1);
        word[index] = '_';

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(compute(stdin.readLine().toCharArray(), 0));
    }
}
