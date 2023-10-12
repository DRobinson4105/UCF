// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase03.java
// ========================
// Several small test cases to help you determine whether printThirdLargest()
// is working correctly.


public class TestCase03
{
	public static void main(String [] args)
	{
		Bonfire.printThirdLargest(new int[] {1, 2, 3, 7, 10, 146, 2944198});
		Bonfire.printThirdLargest(new int[] {10, 294198, 7, 146, 1, 3, 2});
		Bonfire.printThirdLargest(new int[] {7, 7, 2, 7, 2, 7, 2, 2, 2});
		Bonfire.printThirdLargest(new int[] {2, 7, 2, 7, 2, 7, 2, 2, 2});
		Bonfire.printThirdLargest(new int[] {2, 7, 2, 2, 2, 7, 2, 2, 2});

		// What kinds of things haven't we checked for here?
	}
}
