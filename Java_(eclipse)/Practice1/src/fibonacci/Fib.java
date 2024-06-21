package fibonacci;
import java.util.Scanner;
public class Fib {
	public static void main(String[] fa) {
	       int  first,second,third,inp;
			first=0;
			second=1;
	       Scanner sc=new Scanner(System.in);
	       System.out.print("input no.");
	        inp = sc.nextInt();
			sc.close();
			 System.out.println(0);
			if (inp>1)System.out.println(1);
			for (int i=2;inp>i;inp--) {
				third=first+second;
				System.out.println(third);
				first = second;
				second=third;
				
			}
}
}