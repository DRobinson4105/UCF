// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Bonfire: TestCase05.java
// ========================
// Several small test cases to help you determine whether generateNthRotation()
// is working correctly.


import java.util.Arrays;

public class TestCase05
{
	private static void checkTest(int [] array, int n, int [] expectedResult)
	{
		int [] result = Bonfire.generateNthRotation(array, n);

		System.out.println(Arrays.toString(result));
		System.out.println(Arrays.equals(result, expectedResult) ? "Hooray!" : "fail whale :(");
		System.out.println();
	}

	public static void main(String [] args)
	{
		int [] array;
		int [] expectedResult;
		int n;

		array = new int[] {5, 16, 33, 498, 19, 5151, 444, 729, 164, 5, 16, 33, 498, 22};
		expectedResult = new int[] {5, 16, 33, 498, 22, 5, 16, 33, 498, 19, 5151, 444, 729, 164};
		n = 5;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {2, 5, 2, -4};
		n = 1;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {-4, 2, 5, 2};
		n = 2;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {2, -4, 2, 5};
		n = 3;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {5, 2, -4, 2};
		n = 4;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {2, -4, 2, 5};
		n = -1;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {5, 2, -4, 2};
		n = 100;
		checkTest(array, n, expectedResult);

		array = new int[] {5, 2, -4, 2};
		expectedResult = new int[] {2, 5, 2, -4};
		n = 101;
		checkTest(array, n, expectedResult);

		// What kinds of things haven't we checked for here? What are some of the
		// requirements for this method that are listed in the PDF but not tested
		// for here in code?
	}
}
