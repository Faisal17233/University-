package practice;

public class While {
static int method(int a) {
a+=a;
	return a;	
}

	public static void main(String[] args) {
		While a2=new While();
		fo a1=new fo();
	System.out.println(a1.method(231));
	System.out.println(a2.method(231));
	}
}
class fo extends While{
	static int method(int a) {
		a=a+5;
		return a;
	}
	}