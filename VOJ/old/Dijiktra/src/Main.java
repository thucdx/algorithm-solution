import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Graph
{
	int g[][];
	int n;
	int d[][];
	int p[][];
	static final int INF =100000;
	BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
	
	Graph(){}
	void input() throws IOException{
		int i,m,nQues,type;
		int pA,pB,wei;
		boolean t=true;
		String []tmp;
		tmp=(sc.readLine()).split(" ");
		n=Integer.parseInt(tmp[0]);
		//Khoi tao g
		g=new int[n+2][n+2];
		for(i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=INF;
		for(i=1;i<=n;i++)
			g[i][i]=0;
		
		//Doc tiep
		m=Integer.parseInt(tmp[1]);
		nQues=Integer.parseInt(tmp[2]);
		for(i=1;i<=m;i++)
		{
			tmp=(sc.readLine()).split(" ");
			pA=Integer.parseInt(tmp[0]);
			pB=Integer.parseInt(tmp[1]);
			wei=Integer.parseInt(tmp[2]);
			g[pB][pA]=wei;
			g[pA][pB]=wei;
		}
		//Floyd
		
		floyd();
		for(i=1;i<=nQues;i++)
		{	
			tmp=(sc.readLine()).split(" ");
			type=Integer.parseInt(tmp[0]);
			pA=Integer.parseInt(tmp[1]);
			pB=Integer.parseInt(tmp[2]);
			if(type==0) //in ra do dai
			{
				System.out.print(d[pA][pB]+"\n");
			}
			else findPath(pA,pB);
		}
	}
	void floyd()
	{
		d=new int[n+2][n+2];
		p=new int[n+2][n+2];
		int i,j,k;
		//Initial
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				d[i][j]=g[i][j];
				if(g[i][j]==INF)
					p[i][j]=-1;
				else p[i][j]=i;
			}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if(d[i][j]>d[i][k]+d[k][j] && i!=k &&j!=k)
					{
						d[i][j]=d[i][k]+d[k][j];
						p[i][j]=p[k][j];//dinh truoc cua j tren duong tu i-> j, chinh la dinh truoc cua j tren duogn tu k->j
					}
				}
		}
		
	}
	void findPath(int i,int j)
	{
		Stack <Integer> st=new Stack<Integer>();
		int m=j;
		st.push(m);
		do
		{
			m=p[i][m];
			st.push(m);
		}
		while(m!=i);
		//in path.
		System.out.print(st.size());
		while(!st.isEmpty()){
			System.out.print(" "+st.pop());
		}
		System.out.println();
	}
	void shortestPath(int i, int j, boolean type){
		int label[]=new int[n+2];
		boolean set[]=new boolean[n+2];
		int prev[]=new int[n+2];
		int r,s,t;
		int min=INF, pos=-1;
		//khoi tao mang label;
		for(r=1;r<=n;r++)
		{ set[r]=false; //dinh r chua duoc chon vao list set
		  label[r]=g[i][r];
		  prev[r]=i;
		}
		while(!set[j]) //j chua duoc chon
		{
			//Tim dinh chua duoc chon, gan i nhat
			pos=-1;
			min=INF;
			for(s=1;s<=n;s++)
			{
				if(!set[s] && label[s]<min)
				{
					pos=s;
					min=label[s];
				}	
			}
			if (pos!=-1) //ton tai
			{	
				set[pos]=true; //cho pos vao set[].
				
				//Danh dau lai mang
				for(s=1;s<=n;s++)
				{
					if(!set[s]){
						if(label[s]>label[pos]+g[pos][s])
						{
							label[s]=label[pos]+g[pos][s];
							prev[s]=pos;
							
						}
					}
				}
			}
			else break;
		}
		if(pos==-1) System.out.println(" Khong co duong di!");
		if(!type) //type=0; ghi ra do dai ngan nhat
		{
			System.out.print(label[j]+"\n");
		}
		else //in ra cac dinh
		{
			Stack<Integer> st=new Stack<Integer>();
			int m=j;
			int size=1;
			while(m!=i)
			{
				st.push(m);
				m=prev[m];
				size++;
				
			}
			//in ra
			
			System.out.print(size+" ");
			System.out.print(i+" ");
			while(!st.isEmpty())
			{
				System.out.print(st.pop()+" ");
			}
			System.out.print("\n");
			
		}
		
		
	}
	
}
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Graph a=new Graph();
		a.input();
		
	}

}
