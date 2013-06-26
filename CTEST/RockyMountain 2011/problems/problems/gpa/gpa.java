import java.io.*;
import java.util.*;
import java.text.*;

public class gpa
{
    public static void main( String[] args )
    {
		int caseNumber = 0;
    	Scanner input = new Scanner(System.in);

        try
        {
         	String line = input.nextLine();
            while (line != null)
            {
	         	System.out.print ("Case " + (++caseNumber) + ": ");
            	ProblemInstance instance = new ProblemInstance(line);
            	instance.crunch();
            	instance.wrapUp();

            	line = input.nextLine();
            }
        }
        catch(java.util.NoSuchElementException iox)
         {
         }
    }
}

class ProblemInstance
{
    StringTokenizer tokenizer;
    int gradePointSum = 0;
    int numGrades = 0;
    boolean validInput;
    public ProblemInstance (String line)
    {
    	tokenizer = new StringTokenizer(line);
    }
    public void crunch()
    {
    	while (tokenizer.hasMoreTokens())
      	{
        	String letterStr = tokenizer.nextToken();
        	char letter = letterStr.charAt(0);
        	if (!isValidLetter(letter))
        	{
          		validInput = false;
          		return;
        	}
        	else
        	{
          		gradePointSum += letterToGradePoint(letter);
          		numGrades++;
        	}
      	}
      	validInput = true;
    }	// end method crunch


    boolean isValidLetter(char ch)
    {
      return ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D'
             || ch == 'F';
    }

    /**
     * When this method is called, the letter has already been
     * validated.
     */
    int letterToGradePoint(char letter)
    {
      switch (letter)
      {
        case 'A':
          return 4;
        case 'B':
          return 3;
        case 'C':
          return 2;
        case 'D':
          return 1;
        case 'F':
          return 0;
        default:
          return -1;
      }
    }	// end method letterToGradePoint

    public void wrapUp()
    {
		if (validInput)
			System.out.printf("%.2f\n", gradePointSum/(double)numGrades);
		else
			System.out.println("Unknown letter grade in input");
    }
}	// end class ProblemInstance


