import java.io.*;
import java.util.*;

public class sortofsorting {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        int n;
        
        while ((n = Integer.parseInt(stdin.readLine())) != 0) {
            List<String> strings = new ArrayList<String>(n);
            for (int i = 0; i < n; i++) strings.add(stdin.readLine());
            
            Collections.sort(strings, (s1, s2) -> s1.charAt(0) == s2.charAt(0) ?
                    (s1.charAt(1) - s2.charAt(1)) : (s1.charAt(0) - s2.charAt(0)));
                
            for (String s : strings) System.out.println(s);
            
            System.out.println();
        }
    }
}