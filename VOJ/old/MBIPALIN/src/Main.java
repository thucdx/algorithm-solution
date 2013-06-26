import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	static String make(String k,boolean b){
		String rs=""+k;
		if(b){//12344321
			rs=rs.concat(reverse1(""+k));
		}
		else rs=rs.concat(reverse2(""+k));
		return rs;
		
	}
	public static void main(String[] args) throws IOException {
		int n=0,k=0,num=0;
		BigInteger bigNum;
     	int LMod[]=new int [1000000+4];
		int RMod[]=new int[1000000+4];
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String list[]=br.readLine().split(" ");
		n=Integer.parseInt(list[0]);
		k=Integer.parseInt(list[1]);
		//Xu li
		boolean b;
		int i;
			if(n%4==0) b=true; else b=false;
		int start=1,end=1;
		long mun=1;
		for(i=1;i<=n/2;i++)
			mun*=10;
		long du=mun%k;
		//System.out.print(du+ "    ");
		int len=(n/2+1)/2;
		for(i=1;i<=len;i++)
			end*=10;
		start=end/10;
		int l,r;
		String left,right,tmp,newNum;
		i=0;
		//Khoi tao.
		for(i=0;i<=k;i++){
			LMod[i]=0;RMod[i]=0;
		}
		for(l=start;l<=end-1;l++)
		{   left=make(""+l,b);
			int hehe=(int)(Long.parseLong(left)%k);
			RMod[hehe]++;
			LMod[ (int) (hehe*du%k)]++;
			i++;
		}
		
		for(r=0;r<start;r++)
		{	
			tmp=""+r;
		    int lenR=tmp.length();
		    tmp="";
		    for(i=1;i<=len-lenR;i++)
		    	tmp=tmp.concat("0");
		    tmp=tmp.concat(""+r);
			right=make(""+tmp,b);
			RMod[(int) (Long.parseLong(right)%k)]++;
		}
		num=0;
		for(i=0;i<k;i++){
			//System.out.println(i+" "+LMod[i]+ " "+RMod[i]);
			num+=LMod[i]*RMod[(k-i)%k];
		}
		System.out.println(num);
	}
	
	static String reverse1(String a){
		String rs="";
		int i;
		for(i=a.length()-1;i>=0;i--){
			rs=rs.concat(""+a.charAt(i));
		}
		return rs;
	}
	static String reverse2(String a){
		String rs="";
		int i;
		for(i=a.length()-2;i>=0;i--){
			rs=rs.concat(""+a.charAt(i));
		}
		return rs;
	}
}
