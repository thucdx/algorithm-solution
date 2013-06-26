import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class sheet{
	int lPage,rPage;
	public sheet() {
		lPage=-1;
		rPage=-1;
	}
}
public class Main {
	public static void main(String []args ) throws NumberFormatException, IOException{
		int n;
		BufferedReader br=new BufferedReader(new InputStreamReader((System.in)));
		do
		{
			n=Integer.parseInt(br.readLine());
			if (n==0) break;
			process(n);
			
		}
		while(true);
		
	}
	static void process(int n){
		System.out.println("Printing order for "+n+" pages:");
		if(n==1)
			{
			System.out.println("Sheet 1, front: Blank, 1");
			return ;
			}
		int nSheetdouble=n; //so chan nho nhat lon hon hoac bang n/2;
		if(nSheetdouble%4!=0){
			nSheetdouble+=(4-nSheetdouble%4);
			nSheetdouble/=2;
		}
		else nSheetdouble/=2;
		int i,j;
		if (nSheetdouble%2==1) nSheetdouble++;
		sheet st[]=new sheet[n+1];
		//System.out.println(n+" "+nSheetdouble);
		for(i=0;i<=n;i++)
			st[i]=new sheet();
		if (nSheetdouble%2==1) nSheetdouble++;
		for(i=1;i<=nSheetdouble;i++){
			if(i%2==0){ 
				st[i].lPage=i;
			//System.out.println(i+" left");
			}
			else 
				{
					st[i].rPage=i;
					//System.out.println(i+" right");
				}
			
		}
		j=nSheetdouble;
		for(i=nSheetdouble+1;i<=n;i++){
			if( j%2==0) st[j].rPage=i;
			else st[j].lPage=i;
			j--;
		}
		//in ket qua;
		
		for(i=1;i<=nSheetdouble;i++){
			if (i%2==1)
				System.out.print("Sheet "+(i+1)/2+", front: ");
			else System.out.print("Sheet "+i/2+", back: ");
			
			String leftPage,righPage;
			if(st[i].lPage==-1) leftPage="Blank"; 
			else leftPage=""+st[i].lPage;
			if(st[i].rPage==-1) righPage="Blank";
			else righPage=""+st[i].rPage;
			
			System.out.println(leftPage+","+righPage);
		}
	}
	
}
