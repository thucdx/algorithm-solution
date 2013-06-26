import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
		String cow[]=new String[10001];
		String god[]=new String [10001];
		int i,j;
		int c,g;
		String rl=sc.readLine();
		String n[]=rl.split(" ");
		c=Integer.parseInt(n[0]);
		g=Integer.parseInt(n[1]);
		for(i=0;i<c;i++)
		{
			cow[i]=(sc.readLine()).toLowerCase();
		}
		for(i=0;i<g;i++)
		{
			god[i]=(sc.readLine()).toLowerCase();
		}
		for(i=0;i<c;i++)
		{
			int count=0;
			for(j=0;j<g;j++)
				if(contain(cow[i],god[j])) count++;
			System.out.println(count);
		}
	}
	public static boolean contain(String a,String b){
		int i,j;
		for(i=0,j=0;i<a.length() &&j<b.length();)
		{
			if(a.charAt(i)==b.charAt(j)) {i++;j++;}
			else i++;
		}
		if(j==b.length())
		return true;
		else return false;
	}
}
