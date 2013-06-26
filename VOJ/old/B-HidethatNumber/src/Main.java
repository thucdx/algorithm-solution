import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
 
 public static void main(String args[]) throws IOException{
	 BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	 String a,b;
	 int i=1;
	 do
	 {	
		 
		 a=br.readLine();
		 if(a.equals("0")) break;
		 //if(check(a)==0) System.out.print(i+". IMPOSSIBLE\n")
			//tinh toan lai
			 //b=check(a)+"";
			 //b=b+a;
			 System.out.print(i+". ");
			 div11(a);
			 System.out.print("\n");
		     i++;
		 
	 }
	 while(true);
	 
 }
 /*
 public static int check(String a)
 {
	int i;
	int sum=0;
	for(i=0;i<a.length();i++){
		if(i%2==0)
		 sum=sum-(a.charAt(i)-'0');
		else sum=sum+(a.charAt(i)-'0');
	}
  // System.out.println("sum="+sum);
   return ((11-sum)%11);
 }
 
 */
 public static void div11(String a){
	
	int n=0;
	int len=a.length();
	char s[]=new char[len+1];
	int i=0;
	int j=len-1;
	s[0]=a.charAt(j);
	int mem=0;
	char pre=s[0];
	for(i=1;i<=len-1;i++){
		j--;
		char m=a.charAt(j);
		if(m>=pre+mem){
			s[i]=(char) (m-pre-mem+'0');
			pre=s[i];
			mem=0;
			//System.out.print(s[i]);
		}
		else
		{ 
		   s[i]=(char) (10+m-pre-mem+'0');
		   //System.out.print("_"+s[i]+"_");
		   mem=1;
		   pre=s[i];
		}
	}
	if(pre=='0') System.out.print("IMPOSSIBLE");
	else
	for(i=len-1;i>=0;i--)
		System.out.print(s[i]);
 }
}
