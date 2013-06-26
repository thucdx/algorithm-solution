 class TestFraction {
 private int tuso;
 private int mauso;

 public TestFraction(int tu, int mau) {
	tuso = tu; mauso = mau;
 }
 public String toString(){
	 return (tuso+"\\"+mauso);
 }
 
 //ham thuc hien phep cong
 public static TestFraction add(TestFraction f, TestFraction a) {
	 TestFraction kq = new TestFraction(0,0);
	 kq.tuso = a.tuso*f.mauso + f.tuso*a.mauso;
	 kq.mauso = a.mauso*f.mauso;
	 return kq;
	}
}
public class TestFraction{
	public static void  main(String[] args){
		TestFraction f1 = new TestFraction (1,2);
		TestFraction f2 = new TestFraction (1,3);
		TestFraction r;
	
		
		System.out.println("Test add method: ");
		r =  TestFraction.add(f1,f2);
		System.out.println(f1+"+"+f2+"="+r);
	}
}