import java.awt.List;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
	String name;
	int info;
	Node left,right;
	Node(String name, int info){
		this.name=name;
		this.info=info;
	}
}
class TreeName{
	Node root;
	boolean isEmpty(){
		return root==null;
	}
	boolean add(Node x){
		if(isEmpty()){
			root=x;
			return true;
		}
		Node f=null;
		Node p=root;
		while(p!=null){
			if(p.name.equals(x.name)||p.info==x.info){
				return false;
			}
			f=p;
			if(x.info<p.info){
				p=p.left;
			}
			else
				p=p.right;
		}
		if(x.info<f.info)
			f.left=x;
		else
			f.right=x;
	}
	int search(String xName){
		if(isEmpty()){
			return -1;
		}
		Node p=root;
		while(p!=null){
			if(p.name.equals(xName)){
				return p.info;
			}
			if(xName.compareTo(p.name)<0)
				p=p.left;
			else
				p=p.right;
		}
		return -1;
	}
	String search(int xInfo){
		if(isEmpty()){
			return null;
		}
		Node p=root;
		while(p!=null){
			if(p.info==xInfo){
				return p.name;
			}
			if(xInfo<p.info)
				p=p.left;
			else
				p=p.right;
		}
		return null;
	}
}
public class Main {	
	public static void main(String[] args) throws NumberFormatException, IOException {
		ArrayList<String>[] list = new ArrayList[100];
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
		String s;
		TreeName tn = new TreeName();
		while(!(s=br.readLine()).equals("0 0")){	
			String arr[]=s.split(" ");
			int numMem=Integer.parseInt(arr[0]);
			int numWritter=Integer.parseInt(arr[1]);
			String temp[];
			for(int i=0;i<numWritter;i++){
				list[i]=new ArrayList<String>();
				temp=br.readLine().split(" ");
				for(int k=0;k<temp.length;i++){
					list[i].add(temp[0]);
				}
			}
			for(int i=0;i<numWritter;i++){
				for(int k=1;k<list[i].size();i++){
					for(int j=0;i<numWritter;j++){
						
					}
				}
			}
		}
	}

}
