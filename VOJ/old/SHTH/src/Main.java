import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {
	static int n,k;
	static BigInteger s;
	static BigInteger c[];//c[i]= C_k^n;
	static int lNum[];
	static boolean flag[];
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String list[]=br.readLine().split(" ");
		n=Integer.parseInt(list[0]);
		k=Integer.parseInt(list[1]);
		s=new BigInteger(br.readLine());
		
		//System.out.println(s+ " "+ " "+n+ " "+k );
		// khoi tao mang C[k]
		init();
		calc();
		//Doc list
		int i;
		list=(br.readLine()).split(" ");
		for(i=0;i<k;i++){
			lNum[i]=Integer.parseInt(list[i].trim());
		}
		for(i=0;i<=n;i++){
			flag[i]=true;
		}
		count();
	}
	static void init()
	{	int i;
		c=new BigInteger[n+1];
		lNum=new int[n+1];
		flag=new boolean[n+1];
		for(i=0;i<=n;i++){
			flag[i]=true;
		}
		c[0]=BigInteger.ONE;
		c[1]=new BigInteger(""+(n-k+1));
		for(i=2;i<k;i++){
			c[i]=(c[i-1].multiply(new BigInteger(""+(n-k+i))));
			//System.out.println("KQ: "+i+" "+c[i]);
		}
	}
	static void calc(){
		int i=k-1,j=0,t=0;
		s=s.add(new BigInteger(""+(-1)));
		while(i>=0){
			j=Integer.parseInt((s.divide(c[i])).toString());
			//Tim trong list flag
			t=0;
			j++;
			while(true){
				if(flag[t]){
					j--;
					if(j<=0) break;
				}
				t++;
				if(t>=n) break;
			}
			//chon t.
			flag[t]=false;
			if(i>0)
				System.out.print((t+1)+" ");
			else System.out.print((t+1)+"\n");
			//Cap nhat lai s
			s=s.mod(c[i]);
			i--;
		}
	}
	static void count(){
		int i,a,b;
		BigInteger rs=BigInteger.ONE;
		for(i=0;i<k;i++){
			a=lNum[i];
			b=pos(a);
			//System.out.println(a+ " " +b+" "+c[k-1-i].multiply(new BigInteger(""+(b-1))));
			flag[a-1]=false;
			rs=rs.add(c[k-1-i].multiply(new BigInteger(""+(b-1))));
		}
		System.out.print(rs+"\n");
	}
	static int pos(int a){
		//tim a trong flag.
		int b=a-1;
		int i=0,dem=0;
		for(i=0;i<=b;i++){
			if (flag[i]) dem++;
		}
		return dem;
	}
	
}
