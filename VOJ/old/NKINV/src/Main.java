import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
class Node{
	int val;
	Node left, right;
	Node(){left=right=null;}
	Node(int v){
		val=v;
		left=right=null;
	}
}
class Tree{
	Node root;
	void add(int val){
		Node b=new Node(val);
		if(root==null) root=b;
		else 
			add(root,b);
	}
	void add(Node a, Node b){
		if(a.val< b.val){
			if(a.right==null) a.right=b;
			else add(a.right, b);
		}
		else if(a.val >b.val)
		{
			if(a.left==null) a.left=b;
			else add(a.left,b);
		}
	}
	int count(Node a){
		return traverse(a)
	}
	int traverse(Node a){
		if(a==null) return 0;
		else return(1+traverse(a.left)+traverse(a.right));
	}
}

public class Main{
	static int list[]=new int[60000];
	static long result=0;
	static int n;
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws NumberFormatException, IOException {
		int i,j;
		n=Integer.parseInt(br.readLine());
		for()
		
	}

}
