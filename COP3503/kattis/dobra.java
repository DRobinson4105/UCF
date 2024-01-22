import java.util.*;
import java.io.*;

public class dobra {
    private static boolean isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    private static int containsL(char[] word) {
        for (char c : word)
            if (c == 'L') return 1;
        
        return 0;
    }

    private static long compute(char[] word, int index, int vowelsInRow, int consonantsInRow) {
        if (vowelsInRow == 3 || consonantsInRow == 3) return 0;
        if (index == word.length) return containsL(word);

        // Current character cant be changed
        if (word[index] != '_') {
            if (isVowel(word[index]))
                return compute(word, index + 1, vowelsInRow + 1, 0);
            else
                return compute(word, index + 1, 0, consonantsInRow + 1);
        }

        long res = 0;

        // Use vowel
        word[index] = 'A';
        res += 5 * compute(word, index + 1, vowelsInRow + 1, 0);

        // Use L
        word[index] = 'L';
        res += compute(word, index + 1, 0, consonantsInRow + 1);

        // Use other consonant
        word[index] = 'B';
        res += 20 * compute(word, index + 1, 0, consonantsInRow + 1);

        word[index] = '_';

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(compute(stdin.readLine().toCharArray(), 0, 0, 0));
    }
}
