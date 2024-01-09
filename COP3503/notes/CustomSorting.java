import java.util.List;
import java.util.Collections;
import java.util.ArrayList;

/**
 * 1. Implement {@link Comparable} interface
 * <p>
 * 2. Override {@link Comparable#compareTo(Object)} method that returns a negative if the current
 * object should be first or a positive if the other object should be first
 */

class Point implements Comparable<Point> {
    int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Point other) {
            return this.x != other.x ? (this.x - other.x) : (this.y - other.y);
    }

    @Override
    public String toString() {
        return "(" + this.x + "," + this.y + ")";
    }
}

public class CustomSorting {
    public static void main(String[] args) {
        List<Point> points = new ArrayList<Point>();
        for (int i = 0; i < 9; i++)
            points.add(new Point(i / 3, i % 3));
        
        Collections.shuffle(points);
        
        System.out.println("Before Sorting:");
        points.forEach((Point p) -> System.out.println(p));

        Collections.sort(points);

        System.out.println("\nAfter Sorting:");
        points.forEach((Point p) -> System.out.println(p));
    }
}