import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
class main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BigInteger result=new BigInteger("1");//n=2;
		int n;
		BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(sc.readLine());
		int i=2;
		for(i=3;i<=n;i++)
		{ // rs= 1+(i-1)*rs;
			String a=""+(i-2);
			result=result.multiply(new BigInteger(a));
			//System.out.println(result);
			result=result.add(new BigInteger("1"));
			//System.out.println(result);
			
		}
		System.out.print(result);
	}

}
