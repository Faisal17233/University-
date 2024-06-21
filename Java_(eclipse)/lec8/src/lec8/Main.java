package lec8;

abstract public class Main {
	public String acctitle;
	public int accno;
	public double accbalance;
	public abstract void deposit (double ammount);
	public void takeout (double amount) {
		accbalance = accbalance-amount;
	} 
	public void minus (double amount) {
		accbalance = accbalance -500;
	}
		
}

