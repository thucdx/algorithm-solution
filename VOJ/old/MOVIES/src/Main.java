import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

class point implements Comparable<point>{
	point(){
		x=0;y=0;
		
	}
	int x;
	int y;
	public int compareTo(point o) {
		if(this.x>o.x) return 1;
		else if(this.x< o.x) return -1;
		else return(this.y-o.y);
	}
}
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String line;
		point ls[]=new point[50];
		
		int i,j,n,m,nSitChair=0;
		
		BigInteger result;
		for(i=0;i<50;i++)
			ls[i]=new point();
		
		do{
			line=br.readLine();
			if(line.equals("[END]")) break;
			if(line.equals("[CASE]")) //Start new case
			{	
				//input tung test case
				
				nSitChair=0;
				line=br.readLine();
				n=Integer.parseInt(line);
				line=br.readLine();
				m=Integer.parseInt(line);
				line=br.readLine();
				
				do{
					line=br.readLine();
					if(line.equals(">>")) break;
					nSitChair++;
				
					ls[nSitChair].x=Integer.parseInt(line);
				} while(true);
				line=br.readLine(); //"<<"
				for(i=1;i<=nSitChair;i++){
					line=br.readLine();
					ls[i].y=Integer.parseInt(line);
				}
				line=br.readLine();//">>"
				line=br.readLine();//">>"
				//sort lai.
				for(i=1;i<nSitChair;i++)
					for(j=i+1;j<=nSitChair;j++)
					{
						if(ls[j-1].compareTo(ls[j])>0) {
						//System.out.println("swapped"+ls[j-1].x+" "+ls[j-1].y+"with (>)"+ ls[j].x+" "+ls[j].y);
						point tmp=ls[j];
						ls[j]=ls[j-1];
						ls[j-1]=tmp;
						}
					}
				int num=0;
				ls[0].x=ls[1].x;
				ls[0].y=0;
				ls[nSitChair+1].x=0;
				i=0;
				for (i=1;i<=nSitChair;i++)
			    {
			        if (ls[i].y>1) num--;
			        if (ls[i].y<m) num--;
			        if ((ls[i+1].x==ls[i].x)&&(ls[i+1].y==ls[i].y+1)) num++;
			    }
				//System.out.println(numOfRow);
				//System.out.println("num= "+num+"\n"+n+'\n'+(n-numOfRow));
				result=(new BigInteger(""+n).multiply (new BigInteger(""+(m-1)))).add(new BigInteger(""+num));
				System.out.print(result+"\n");
			}
		}
		while(true);
		
	}

}
