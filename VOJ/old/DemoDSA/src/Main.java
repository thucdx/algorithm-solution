
class A
 {int x;
 }
public class Main
{
		static void test1(A  t)
	   {t = new A();
	    t.x += 100;
	   }
	  static void test2(A  t)
	   {t.x += 100;
	   }
	public static void main(String [] args)
	   {A t = new A();
	    t.x = 10; 
	    System.out.println("\n x before running test1 is: " + t.x);
	    test1(t);
	    System.out.println("\n x after running test1 is: " + t.x);
	    System.out.println("\n x before running test2 is: " + t.x);
	    test2(t);
	    System.out.println("\n x after running test2 is: " + t.x);
	    System.out.println("\n"); 
	   }
 } 

