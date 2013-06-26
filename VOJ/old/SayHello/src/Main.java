import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class Node{
	char symbol;
	Node left,right;
	double pR,pL;
	Node()
	{
		symbol='N';
		left=right=null;
		pR=0;pL=0;
	}
	
	Node(double p)
	{
		this.pR=p;
		this.pL=1-p;
	}
	void set(char c)
	{
		symbol=c;
	}
	void set(double p){
		this.pR=p;
		this.pL=1-p;
	}
	void set(Node l, Node r){
		left=l;
		right=r;
	}
	Node(Node l, Node r){
		left=l;
		right=r;
	}
}
class solve{
	Node []g;
	int path=0;
	double prob=0;
	solve(Node[]a)
	{
		g=a;
	}
	int count(Node a,Node b)
	{	
		if(a==null) return 0;
		if(a.left==b || a.right==b) return 1;
		else
		{
			return count(a.left,b)+count(a.right,b);
		}	
	}
	double pro(Node a, Node b)
	{
		if(a==null) return 0;
		if(a==b) return 1;
		return a.pL*pro(a.left,b)+a.pR*pro(a.right,b);
	}
}
public class Main {
	
	
	public static void main(String args[])
	{
		int i;
		String reads="";
		//Scanner sc=new Scanner(System.in);
		 BufferedReader sc
		   = new BufferedReader(new InputStreamReader(System.in) );
		int n=0;
		try {
			n=Integer.parseInt(sc.readLine());
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		for(int k=1;k<=n;k++)
		{
			Node[]gr=new Node[24];
			for(i=0;i<24;i++) gr[i]=new Node();
			//for(i=0;i<18;i++)
			i=0;
			for(int p=1;p<=4;p++)
			{
				try {
					reads=sc.readLine();
					
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				String cap[]=reads.split(" ");
				int j=0;
				while(j<cap.length)
				{
					String r[]=cap[j].split("\\/");
					gr[i].set(Double.parseDouble(r[0])/Double.parseDouble(r[1]));
					i++;
					j++;
				}
					//System.out.println(r[0]+"!"+r[1]);	
				
			}
			gr[0].set('a');  //Node A
			gr[1].set('b'); //Node B
			gr[2].set('c');//Node C
			gr[3].set('d'); //Node D
			gr[4].set('e'); //Node E
			/*.....*/
			gr[18].set('A');  //Node A
			gr[19].set('B'); //Node B
			gr[20].set('C');//Node C
			gr[21].set('D'); //Node D
			gr[22].set('E'); //Node E
			//set do thi.
			for(i=0;i<18;i++)
			{
				if(gr[i].pR>0)
				{
					gr[i].right=gr[i+5];
				}
				if(gr[i].pL >0)
				{
					gr[i].left=gr[i+4];
				}
			}
			char a[]=new char[3],b[]=new char[3];
			//count(gr,'C','E');
			
			for(int j=0;j<3;j++)
			{	
				String m;
				try {
					m = sc.readLine();
					a[j]=m.charAt(0);
					b[j]=m.charAt(2);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} 
				
			}
			System.out.println("data set #"+k);
			for(int j=0;j<3;j++)
			{	
				count(gr,a[j],b[j]);
			}
			
		}
	}
	public static void count(Node[] gr,char m,char n)
	{
		int start=0,end=0;
		switch(m)
		{
		case'A': start= 0;break;
		case'B': start= 1;break;
		case'C': start= 2;break;
		case'D': start= 3;break;
		case'E': start= 4;break;
		}
		switch(n)
		{
		case'A': end= 18;break;
		case'B': end= 19;break;
		case'C': end= 20;break;
		case'D': end= 21;break;
		case'E': end= 22;break;
		}
		solve r=new solve(gr);
		System.out.print(m+"->"+n+" "+r.count(gr[start],gr[end])+" paths, ");
		System.out.print((int)Math.floor(100*(r.pro(gr[start],gr[end])+0.001))+"% chance\n");
	}
}
