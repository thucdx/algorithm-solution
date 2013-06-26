import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.TreeSet;

class Node implements Comparable<Node>{
	BigInteger val;
	int n;
	Node(BigInteger v,int nn){
		val=v;
		n=nn;
	}
	@Override
	public int compareTo(Node a) {
		if(val.compareTo(a.val)>0) return 1;
		else if(val.compareTo(a.val)<0) return -1;
		else return (n-a.n);
	}
	
}
public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int nTest,n,i,j;
		BigInteger result,p1,p2,sum;
		Node tNode;
		String list[];
		int num;
		nTest=Integer.parseInt(br.readLine());
		for(i=1;i<=nTest;++i){
			TreeSet<Node> a=new TreeSet<Node>();
			result=BigInteger.ZERO;
			n=Integer.parseInt(br.readLine());
			list =br.readLine().split(" ");
			num=0;
			for(j=0;j<n;++j){
				a.add(new Node(new BigInteger(""+Integer.parseInt(list[j])),++num));
			}
			
			while(!a.isEmpty()){
				tNode=a.first();
				p1= tNode.val;
				a.remove(tNode);
				if(a.isEmpty()) {System.out.print(result+"\n");break;}
				p2=a.first().val;
				tNode=a.first();
				p2= tNode.val;
				a.remove(tNode);
				sum=p1.add(p2);
				//System.out.println(p1+" "+p2);
				result=result.add(sum);
				a.add(new Node(sum,++num));
			}

	}

	}
}
