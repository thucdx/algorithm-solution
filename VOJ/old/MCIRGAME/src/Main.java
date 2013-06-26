import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
		int n;
		int i;
		BigInteger rs=BigInteger.valueOf(1);
		do
		{
			rs=BigInteger.ONE;
			n=Integer.parseInt(bf.readLine());
			if(n==-1) break;
			for(i=n+2;i<=2*n;i++)
				rs=rs.multiply(new BigInteger(""+i));
			for(i=2;i<=n;i++)
				rs=rs.divide(new BigInteger(""+i));
			System.out.print(rs+"\n");
		}
		while(true);
		
	}

}
