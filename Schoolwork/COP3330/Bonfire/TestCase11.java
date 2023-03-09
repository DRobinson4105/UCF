// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase11.java
// ========================
// A brief test case to help ensure you've implemented the difficultyRating() method correctly.
//
// For detailed compilation and testing instructions, see the assignment PDF.


import java.io.*;
import java.util.*;

public class TestCase11
{
	public static void main(String [] args)
	{
		double difficulty = Bonfire.difficultyRating();
		System.out.println((difficulty < 1.0 || difficulty > 5.0) ? "fail whale :(" : "Hooray!");
	}
}
