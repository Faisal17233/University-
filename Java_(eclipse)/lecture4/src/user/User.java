package user;

import lecture4.Lecture4;

public class User  {
	    public static void main(String[] args) {
		Lecture4 a1= new Lecture4();
		a1.accbalance=1000;
		System.out.println(a1.accbalance);
		a1.deposit(500);
		System.out.println(a1.accbalance);
		a1.takeout(400);
		System.out.println(a1.accbalance);
		a1.minus(400);
		System.out.println(a1.accbalance);
		a1.show();
		}
}

