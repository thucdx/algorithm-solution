import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
	static BigInteger f[]=new BigInteger[1005];
	public static void main(String[] args) throws IOException {
		init();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n;
		String line;
		while((line=br.readLine())!=null){
			n=Integer.parseInt(line);
			System.out.print(f[n]+"\n");
		}

	}
	static void init(){
		int i;
		f[1]=f[0]=BigInteger.ZERO;
		f[3]=f[2]=BigInteger.ONE;
		BigInteger mu=f[2];
		BigInteger two=new BigInteger(""+2);
		for(i=4;i<=1000;++i)
		{	
			mu=mu.multiply(two);
			f[i]=f[i-2].add(mu);
		}
		
	}

}
