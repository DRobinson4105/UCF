// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase02.java
// ========================
// Several small test cases to help you determine whether getThirdLargest()
// is working correctly.


public class TestCase02
{
	private static void checkTest(int [] array, int expectedResult)
	{
		int result = Bonfire.getThirdLargest(array);

		System.out.println(result);
		System.out.println((result == expectedResult) ? "Hooray!" : "fail whale :(");
		System.out.println();
	}

	public static void main(String [] args)
	{
		checkTest(new int[] {1, 2, 3, 7, 10, 146, 2944198}, 10);
		checkTest(new int[] {10, 294198, 7, 146, 1, 3, 2}, 10);
		checkTest(new int[] {7, 7, 2, 7, 2, 7, 2, 2, 2}, 7);
		checkTest(new int[] {2, 7, 2, 7, 2, 7, 2, 2, 2}, 7);
		checkTest(new int[] {2, 7, 2, 2, 2, 7, 2, 2, 2}, 2);

		// What kinds of things haven't we checked for here?
	}
}
