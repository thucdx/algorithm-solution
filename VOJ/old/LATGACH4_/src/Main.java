import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		int nTest,i,n;
		double a= ((1+Math.sqrt(5))/2);
		double b= ((1-Math.sqrt(5))/2);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BigDecimal result=new BigDecimal(BigInteger.ZERO);
		BigDecimal n1,n2,can=new BigDecimal(Math.sqrt(5));
		nTest=Integer.parseInt(br.readLine());
		for(i=1;i<=nTest;++i){
			n=Integer.parseInt(br.readLine());
			//Tinh result;
			n1=new BigDecimal(a);
			n1=n1.pow(n+1);
			n2=new BigDecimal(b);
			n2=n2.pow(n+1);
			result=(n1.subtract(n2));
			result=result.divide(new BigDecimal(Math.sqrt(5)));
			String fr[]=(result.toString()).split("\\.");
			//System.out.println(result+"\n");
			System.out.println(fr[0]+"\n");
		}
		

	}

}
