import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		int n, x;
		int i,j;
		BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(sc.readLine());
		
		for(i=1;i<=n;i++)
		{
			x=Integer.parseInt(sc.readLine());
			calc(x);
		}
		
		

	}
	public static void calc(int x)
	{
		BigInteger make=new BigInteger("0");
		String tmp="";
		BigInteger zero=new BigInteger("0");
		BigInteger bX=new BigInteger(""+x);
		String num;
		int i,j;
		for(i=0;i<=200;i++)
			tmp=tmp+"6";
		System.out.println(tmp);
		int t;
		i=(int)Math.log10(x);
		System.out.println("i= "+i);
		boolean found=false;
		for(;i<200;i++)
		{	
			num=tmp.substring(0,i);
			for(j=0;j<=i;i++)
			{
				num=setCharAt(num, j, '8');
				make=new BigInteger(num);
				if(make.mod(bX)==zero)
				{
					System.out.println(make);
					found=true;
					break;
				}
				if(found) break;
			}
		}
	}
	public static String setCharAt(String a, int i,char c)
	{	
		if(i<0 || i>a.length()) return a;
		 return (a.substring(0,i)+c+a.substring(i+1,a.length()));
	}

}
