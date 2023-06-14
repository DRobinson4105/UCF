// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase12.java
// ========================
// A brief test case to help ensure you've implemented the hoursSpent() method correctly.
//
// For detailed compilation and testing instructions, see the assignment PDF.

public class TestCase12
{
	public static void main(String [] args)
	{
		double hours = Bonfire.hoursSpent();
		System.out.println((hours <= 0.0) ? "fail whale :(" : "Hooray!");
	}
}
