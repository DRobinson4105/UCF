package Schoolwork.COP3330;

public class Exceptional
{
   public static void soManyExceptions()
   {
      int [] array1 = null;
      int [] array2 = new int[10];

      int i = -1;

      try
      {
         array2[i] = 12;
         array1[i] = 12;
      }
      catch (NullPointerException e)
      {
         System.out.println("That's a Null Nelly!");
      }
      catch (ArrayIndexOutOfBoundsException e)
      {
         System.out.println("Out of bounds!");
      }
      catch (Exception e)
      {
         System.out.println("Generic problem!");
      }
      finally
      {
         System.out.println("Finished!");
      }

      System.out.println("Tada!");
   }

   public static void main(String [] args)
   {
      soManyExceptions();
      System.out.println("Bloop!");
   }
}
