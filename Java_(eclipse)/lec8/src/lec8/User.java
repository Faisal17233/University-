package lec8;


public class User extends Main {
	public void deposit (double ammount) {
		accbalance = accbalance+ammount;
	}
	
	public static void main(String[] args) {
		Main a1= new User();            //cant make Main() bec cant instansiate bec abstract
		a1.accbalance=1000;
		System.out.println(a1.accbalance);
		a1.deposit(500);
		System.out.println(a1.accbalance);
		a1.takeout(400);
		System.out.println(a1.accbalance);
		a1.minus(400);
		System.out.println(a1.accbalance);
		}
}
