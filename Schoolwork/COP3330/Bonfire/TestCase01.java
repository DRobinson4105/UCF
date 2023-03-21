// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase01.java
// ========================
// Several small test cases to help you determine whether containsValueAfterIndex() is working
// correctly.


public class TestCase01
{
	private static void checkTest(int needle, int [] haystack, int index, boolean expectedResult)
	{
		boolean result = Bonfire.containsValueAfterIndex(needle, haystack, index);

		System.out.println(result);
		System.out.println((result == expectedResult) ? "Hooray!" : "fail whale :(");
		System.out.println();
	}

	public static void main(String [] args)
	{
		checkTest(9, new int[] {3, 5, 3, 9, 6}, 1, true);
		checkTest(9, new int[] {3, 5, 3, 9, 6}, 2, true);
		checkTest(9, new int[] {3, 5, 3, 9, 6}, 3, false);
		checkTest(9, new int[] {3, 5, 3, 9, 6}, -1, true);

		// What kinds of things haven't we checked for here?
	}
}
