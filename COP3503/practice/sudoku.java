import java.util.*;
import java.io.*;

public class sudoku {
    private static boolean valid(int[][] grid, int x, int y, int val) {
        for (int i = 0; i < 9; i++) {
            if (grid[i][y] == val || grid[x][i] == val || 
                grid[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == val) return false;
        }

        return true;
    }

    private static boolean solve(int[][] grid, int x, int y) {
        if (x == 9) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++)
                    System.out.print(grid[i][j] + " ");
                
                System.out.println();
            }
            return true;
        }

        int nx = y == 8 ? (x + 1) : x;
        int ny = y == 8 ? 0 : (y + 1);

        if (grid[x][y] != 0) {
            return solve(grid, nx, ny);
        }

        for (int val = 1; val <= 9; val++) {
            if (!valid(grid, x, y, val)) continue;

            grid[x][y] = val;
            
            if (solve(grid, nx, ny)) return true;

            grid[x][y] = 0;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(stdin.readLine());

        while (n-- != 0) {
            int[][] grid = new int[9][9];
    
            for (int i = 0; i < 9; i++) {
                StringTokenizer st = new StringTokenizer(stdin.readLine());
                
                for (int j = 0; j < 9; j++)
                    grid[i][j] = Integer.parseInt(st.nextToken());
            }
        
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    int val = grid[i][j];
                    if (val == 0) continue;

                    grid[i][j] = 0;
    
                    if (!valid(grid, i, j, val)) {
                        System.out.println("No solution possible.");
                        return;
                    }

                    grid[i][j] = val;
                }
            }

            if (!solve(grid, 0, 0)) System.out.println("No solution possible.");
        }
    }
}
