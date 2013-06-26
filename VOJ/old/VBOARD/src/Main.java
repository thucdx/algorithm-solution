import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	final static int max=501;
	static int n;
	static int q;
	static int cb[][];
	static int L[][];
	static int R[][];
	public static void main(String[] args) throws IOException {
		cb=new int[max][max];
		L=new int[max][max];
		R=new int[max][max];
		// TODO Auto-generated method stub
		int i,j;
		BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
	    int xa,ya,xb,yb;
	    n=Integer.parseInt((sc.readLine()).split(" ")[0]);
	    for(i=0;i<n;i++)
	    {	String s[]=sc.readLine().split(" ");
		    for(j=0;j<n;j++)
		    {
		     cb[i][j]=Integer.parseInt(s[j]);     
		    }
	    }
	    proces();
	    q=Integer.parseInt((sc.readLine()).split(" ")[0]);
	    for(i=1;i<=q;i++)
	    {	
	       String s[]=(sc.readLine().split(" "));
	                  
	       xa= Integer.parseInt(s[0]);
	       ya= Integer.parseInt(s[1]);
	       xb= Integer.parseInt(s[2]);
	       yb= Integer.parseInt(s[3]);
	       xa--;
	       ya--;
	       xb--;
	       yb--;
	       //Tinh
	       int sum=0;
	       for(j=xa;j<=xb;j++)
	       {
	        //sum+=r[j][ya][yb];
	    	   int a=((j+ya)%2==0 ? cb[j][ya]: -cb[j][ya]);
	    	   int b=((j+yb)%2==0 ? cb[j][yb]: -cb[j][yb]);
	        sum+= (L[j][n-1]-(L[j][ya]-a+R[j][yb]-b));
	       }
	       if(sum<0) sum=-sum;
	       System.out.println(sum);
	    }

	}
	public static void proces()
	{
		int rs=0;
		int sum=0;
		 int i,j,t;
		 for(i=0;i<n;i++)
		 {
		  //Left	 
	      L[i][0]=(i%2==0 ? cb[i][0]: -cb[i][0]);
		  for(j=1;j<n;j++)
			  L[i][j]=L[i][j-1]+((i+j)%2==0 ? cb[i][j] : -cb[i][j]);
		  //Right
		  R[i][n-1]=((i+n-1)%2==0 ? cb[i][n-1]: -cb[i][n-1]);
		  for(j=n-2;j>=0;j--)
			  R[i][j]=R[i][j+1]+((i+j)%2==0 ? cb[i][j] : -cb[i][j]);
		 }
			           
	
	}

}
