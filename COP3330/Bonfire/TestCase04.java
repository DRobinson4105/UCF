// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase04.java
// ========================
// Several small test cases to help you determine whether isRotation() is
// working correctly.


public class TestCase04
{
	private static void checkTest(int [] array1, int [] array2, boolean expectedResult)
	{
		boolean result = Bonfire.isRotation(array1, array2);

		System.out.println(result);
		System.out.println((result == expectedResult) ? "Hooray!" : "fail whale :(");
		System.out.println();
	}

	public static void main(String [] args)
	{
		int [] array1;
		int [] array2;

		array1 = new int[] {5, 16, 33, 498, 19, 5151, 444, 729, 164, 5, 16, 33, 498, 22};
		array2 = new int[] {729, 164, 5, 16, 33, 498, 22, 5, 16, 33, 498, 19, 5151, 444};
		checkTest(array1, array2, true);

		array1 = new int[] {5, 16, 33, 498, 19, 5151, 444, 729, 164, 5, 16, 33, 498, 22};
		array2 = new int[] {5, 16, 33, 498, 22, 5, 16, 33, 498, 19, 5151, 444, 729, 164};
		checkTest(array1, array2, true);

		array1 = new int[] {5, 16, 33, 498, 19, 5151, 444, 729, 164,
		                    5, 16, 33, 498, 19, 5151, 444, 729, 164};
		array2 = new int[] {5, 16, 33, 498, 19, 5151, 444, 729, 164};
		checkTest(array1, array2, false);

		array1 = new int[] {5, 2, -4, 2};
		array2 = new int[] {5, 2, -4, 2};
		checkTest(array1, array2, true);

		array1 = new int[] {5, 2, -4};
		array2 = new int[] {5, 2, -4, 2};
		checkTest(array1, array2, false);

		array1 = new int[] {5, 2, -4, 2};
		array2 = new int[] {5, 2, -4};
		checkTest(array1, array2, false);

		array1 = new int[] {};
		array2 = new int[] {};
		checkTest(array1, array2, true);

		// What kinds of things haven't we checked for here? What are some of the
		// requirements for this method that are listed in the PDF but not tested
		// for here in code?
	}
}
