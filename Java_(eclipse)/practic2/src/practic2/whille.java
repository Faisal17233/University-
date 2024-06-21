package practic2;
import java.util.Scanner;

public class whille {

	public static void main(String[] args) {
		int i,random,attempt;
		attempt =0;
		random = 69;		
		Scanner sabeeh = new Scanner(System.in);
		System.out.println("enter no. between 1 to 100,enter -1 to quit");
		i=sabeeh.nextInt();
		while (true) {
		   if (i==-1)break;
		   else if (i<random) {
			   System.out.println("no. is less you piece of shit");
		   }
		   else if (i>random) {
			   System.out.println("no. is greater you worthless garbage");
		   }
		   else if (i==random) {
			   System.out.println("you won idiot");
			   attempt=attempt+1;
			   break;
		   }
		   attempt=attempt+1;
		   i=sabeeh.nextInt();
		}
sabeeh.close();
System.out.println("attempts are:"+attempt);
	}

}
