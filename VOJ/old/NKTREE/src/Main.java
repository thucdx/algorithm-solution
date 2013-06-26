import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node
{	
	int info;
	Node r, l;
	Node(int a){
		info=a;
	}
}
class myTree{
	Node root;
	Node prevAdd;
	myTree(){
		root=null;
		prevAdd=null;
	}
	void makeRoot(int a){
		root=new Node(a);
		prevAdd=root;
	}
	boolean isEmpty(){
		return (root==null);
	}
	boolean add(int a){
		Node nA=new Node(a);
		if(isEmpty()) {
			makeRoot(a);
			return true;
		}
		Node ind=root,prev=null;
		while(ind!=null){
			prev=ind;
			if(ind.info<a) ind=ind.r;
			else ind=ind.l;
		}
		if(prev!=prevAdd) return false;
		else { //add to tree
			if(prev.info<a )prev.r=nA;
			else prev.l=nA;
			prevAdd=nA;
		}
		return true;	
	}
}
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		boolean answer=true;
		myTree mt=new myTree();
		int numToAdd=0;
		int i,j;
		String line;
		BufferedReader br=new BufferedReader((new InputStreamReader(System.in)));
		while ((line = br.readLine()) != null) {
				if(answer){
					String list[]=line.split(" ");
					for(i=0;i<list.length;i++){
						numToAdd=Integer.parseInt(list[i]);
						answer=mt.add(numToAdd);
						//System.out.print(numToAdd+" "+answer+"\n");
						if (!answer) break;
					}
				}
				else break;
		}
		if(answer) System.out.print("YES\n");
		else System.out.print("NO\n");
	}
}
