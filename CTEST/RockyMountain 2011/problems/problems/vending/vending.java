import java.io.*;
import java.util.*;
/**

Laszlo Szuecs
10/17/2011

*/

public class vending
{

    public static void main (String[] args)
    {

		int price = 0, tended = 0;
		int caseNumber = 0;
	    Scanner input= new Scanner (System.in);
        try
        {
            price = input.nextInt();
            tended = input.nextInt();
        	while (price > 0)
            {
				System.out.print("Case " + (++ caseNumber) + ": ");
              	ProblemInstance instance = new ProblemInstance(price, tended);
				instance.crunch();

	            price = input.nextInt();
    	        tended = input.nextInt();
          }
        }
        catch (java.util.NoSuchElementException iox)
        {
        }
    }  // end main
}	//   end class vending

class ProblemInstance
{
	int price, tended;
	public ProblemInstance(int p, int t)
	{
		price = p;
		tended = t;
	}
	public void crunch()
	{
		int change = tended - price;
		int tens = change / 10;
		int afterTens = change % 10;
		int fives = afterTens / 5;
		int ones = afterTens % 5;

		System.out.print(change + " = ");
		System.out.print (tens + " * 10 + ");
		System.out.print (fives + " * 5 + ");
		System.out.println (ones + " * 1");
	}
}