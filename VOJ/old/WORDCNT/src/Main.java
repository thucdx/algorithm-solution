import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int i,j,
		n;
		int prev,cur,maxLen,len;
		n=Integer.parseInt(br.readLine());
		for(j=1;j<=n;j++){
			String list[]=(br.readLine()).split(" ");
			prev=-1;cur=0;maxLen=0;len=1;
			for(i=0;i<list.length;i++){
				list[i]=list[i].trim();
				cur=list[i].length();
				if(cur==0) continue;
				if(cur==prev)  len++;
				else{
					prev=cur;
					if(len>maxLen) maxLen=len;
					len=1;
				}	
			}
			if(len>maxLen) maxLen=len;
			System.out.print(maxLen+"\n");
		}
	}

}
/*
9
a aa bb cc def ghi       g 
a a a a a bb bb bb bb c c
bgds df gfd dsf dfgdfsg dfg fg fg df gdf
a aa bb cc def ghi   
a a a a a bb bb bb bb c c
bgds df gfd dsf dfgdfsg dfg fg fg df gdf
a aa bb cc def ghi   
a a a a a bb bb bb bb c c
bgds df gfd dsf dfgdfsg dfg fg fg df gdf

 */
