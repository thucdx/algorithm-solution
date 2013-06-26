import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		TreeMap<String, String> tree=new TreeMap();	
		String str[]={
		"A	.- 	J	.--- 	S	... 	1	.---- 	.	.-.-.- 	:	---...",
		"B	-... 	K	-.- 	T	- 	2	..--- 	,	--..- - 	;	-.-.-.",
		"C	-.-. 	L	.-.. 	U	..- 	3	...- - 	?	..- -.. 	=	-...-",
		"D	-.. 	M	-- 	V	...- 	4	....- 	'	.----. 	+	.-.-.",
		"E	. 	N	-. 	W	.-- 	5	..... 	!	-.-.-- 	-	-....-",
		"F	..-. 	O	--- 	X	-..- 	6	-.... 	/	-..-. 	_	..--.-",
		"G	- -. 	P	.--. 	Y	-.-- 	7	--... 	(	-.- -. 	a	.-..-.",
		"H	.... 	Q	--.- 	Z	--.. 	8	---.. 	)	-.--.- 	@	.--.-.",
		"I	.. 	R	.-. 	0	----- 	9	----. 	&	.-...",
		};
		int i;
		String key,value;
		for(i=0;i<str.length;i++)
		{
			String split[]=str[i].split(" ");
			for(int j=0;j<split.length;)
			{
				value=split[j];
				j++;
				if(value.equals("a")) value=""+'"';
				key=split[j];
				j++;
				tree.put(key,value);
			}
			
		}
		tree.put(" ","space");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int nTest;
		String test;
		nTest=Integer.parseInt(br.readLine());
		for(i=1;i<=nTest;i++){
			test=br.readLine();
			test.replaceAll("  ", " space ");
			String sp[]=test.split(" ");
			for(int j=0;j<sp.length;j++){
				System.out.print(tree.get(sp[j]));
			}
		}
		
	}

}
