package p1;

public class BankAccount {
	String acctitle;
	int accno;
	double accbalance;
	void deposit (double ammount) {
		accbalance = accbalance+ammount;
	}
	void takeout (double amount) {
		accbalance = accbalance-amount;
	} 
	void minus (double amount) {
		accbalance = accbalance -500;
	}
	void minu (double amount) {
		accbalance = accbalance * 500;
	}
	
}
