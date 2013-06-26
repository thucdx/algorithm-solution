import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int nTest,i,j;
		nTest=Integer.parseInt(br.readLine());
		for(i=1;i<=nTest;++i){
			String s[]=br.readLine().split(" ");
			//in ra
			System.out.print("Case #"+i+": ");
			for(j=s.length-1;j>=0;--j){
				System.out.print(s[j]+" ");
			}
			System.out.println();
			
		}

	}

}
