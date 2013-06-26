import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Main {
	public static void main(String args[]) throws NumberFormatException, IOException
	{	
		//Scanner sc=new Scanner(System.in);
		BufferedReader sc
		   = new BufferedReader(new InputStreamReader(System.in) );
		int n,l;
		String s;
		int val;
		n=Integer.parseInt(sc.readLine());
		for(l=1;l<=n;l++)
		{	
			String reads= sc.readLine();
			String at[]=reads.split(" ");
			val=Integer.parseInt(at[0]);
			s=at[1];
			//val=sc.();
			//s=sc.next();
			System.out.println("POLYNOMIAL "+l);
			System.out.println(s);
			if(isNumber(s)){
				System.out.println("0");
				System.out.println("0");
				System.out.println("0");
				System.out.println("0");
			}
			else
			{
				s=s.replaceAll("\\-", " -");
				s=s.replaceAll("\\+", " +");
				if(s.charAt(0)==' ') s=s.substring(1);
				String spl[]=s.split(" ");
				int i;
				for(i=0;i<spl.length;i++)
				{	
					//xoa dau cong
					if(spl[i].charAt(0)=='+')
					{
					spl[i]=spl[i].substring(1);	
					}
					//System.out.println(spl[i]);
				}
				//tach.
				int len=spl.length;
				if(!spl[len-1].contains("x"))
					len=len-1;
				int hs[]=new int[len];
				int mu[]=new int[len];
				for(i=0;i<len;i++)
				{   
					if(spl[i].indexOf('x')==0) hs[i]=1;
					else
					if(spl[i].charAt(0)=='-'&&spl[i].charAt(1)=='x')
					{
						hs[i]=-1;
					}
					else hs[i]=Integer.parseInt(spl[i].substring(0, spl[i].indexOf('x')));
					if(spl[i].indexOf('^')>0)
						mu[i]=Integer.parseInt(spl[i].substring(spl[i].indexOf('^')+1));
					else mu[i]=1;
				}
				
				//Derivative
				for(i=0;i<len;i++)
				{
					hs[i]=hs[i]*mu[i];
					mu[i]--;
				}
				//In ra
				for(i=0;i<len;i++)
				{
					if(i==0) System.out.print(print(hs[0],mu[0]));
					else
					{
						if(hs[i]>0)
							System.out.print("+"+print(hs[i],mu[i]));
						else System.out.print(print(hs[i],mu[i]));
					}
				}
				//Thay so.
				System.out.println();
				for(i=0;i<len;i++)
				{
					if(i==0) System.out.print(printVal(val,hs[0],mu[0]));
					else
					{
						if(hs[i]>0)
							System.out.print("+"+printVal(val,hs[i],mu[i]));
						else System.out.print(printVal(val,hs[i],mu[i]));
					}
				}
				//Tinh tung bieu thuc
				System.out.println();
				long gt[]=new long[len];
				boolean neg[]=new boolean [len];
				
				for(i=0;i<len;i++)
				{	neg[i]=false;
					gt[i]=Math.round(hs[i]* Math.pow(val, mu[i]));
					if(i==0) 
						System.out.print(gt[i]);
					else
					{	
						if(hs[i]<0) 
							{hs[i]=-hs[i];
							neg[i]=true;
							gt[i]=-gt[i];
							System.out.print("-"+gt[i]);
							}
						else System.out.print("+"+gt[i]);
					}
				}
				//Final result;
				System.out.println();
				long rs=0;
				for(i=0;i<len;i++)
				{	if(neg[i]) rs=rs-gt[i];
					else rs+=gt[i];
				}
				System.out.println(rs);
			}
		}
		
		
	}
	public static boolean isNumber(String s)
	{
		int i=0;
		while(i<s.length()){
			if(s.charAt(i)=='-'||(s.charAt(i)>='0' &&s.charAt(i)<='9'))
			i++;
			else return false;
		}
		return true;
		
	}
	public static String print(int a, int b)
	{		String rs;
			if (b==0)
			    return ""+a;
			if(b==1)
				return ""+a+"x";
			if(b>=2)
				return ""+a+"x^"+b;
			return null;
	}
	public static String printVal(int val,int a, int b)
	{		String rs;
			if (b==0)
			    return ""+a;
			if(b==1)
				return ""+a+"("+val+")";
			if(b>=2)
				return ""+a+"("+val+")^"+b;
			return null;
	}
}
