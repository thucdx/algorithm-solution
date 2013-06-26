import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node{
	int value;
	Node next[];
	Node(){
		value=0;
		next=new Node[26];
	}
}
public class Main {
	static Node r=new Node();
	static String s;
	public static void Add(){
		Node l=r;
		int i,index;
		for(i=0;i<s.length();++i){
			index=s.charAt(i)-'a';
			if(l.next[index]==null) 
				l.next[index]=new Node();
			l=l.next[index];
		}
		l.value=1;
	}
	public static int MaxL(Node a){
		int result=0,i;
		for(i=0;i<26;++i){
			if(a.next[i]!=null){
				int z=MaxL(a.next[i]);
				if(z>result) result=z;
			}
		}
		return result+a.value;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		
		n=Integer.parseInt(br.readLine());
		for(i=1;i<=n;++i)
		{
			s=br.readLine();
			Add();
		}
		System.out.println(MaxL(r));
	}

}
