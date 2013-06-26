
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
		//initial
		BigInteger rs[]=new BigInteger[1002];
		int i;
		rs[1]=BigInteger.ONE;
		rs[2]=new BigInteger("2");
		for(i=3;i<=1000;i++)
		{
			rs[i]=rs[i-1].add(rs[i-2]);
		}
		//
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int nTest;
		int t;
		//nTest=Integer.parseInt(br.readLine());
		//
		String c;
		boolean cont=true;
		do
		{
		try{c=br.readLine();
		
			t=Integer.parseInt(c);
			//=Integer.parseInt(br.readLine());
			BigInteger fR=(rs[t].multiply(rs[t-2])).multiply(new BigInteger("12"));
			fR=fR.multiply(rs[t-1].pow(2));		
			fR=fR.add(((rs[t].multiply(rs[t-2])).pow(2)).multiply(new BigInteger("2")));
			fR=fR.add((rs[t-1].pow(4)).multiply(new BigInteger("2")).add(new BigInteger("2")));
			System.out.print(fR+"\n");
		}
		catch (Exception e) {
			cont=false;
			break;
			// TODO: handle exception
		}
		} while(cont);
		

	}

}
