package p1;
public class prinnt extends BankAccount {
	public static void main(String[] args) {
		BankAccount a1= new BankAccount();
		System.out.println(a1.accbalance);
		a1.deposit(500);
		System.out.println(a1.accbalance);
		a1.takeout(400);
		System.out.println(a1.accbalance);
		a1.minus(400);
		System.out.println(a1.accbalance);
		}
	}