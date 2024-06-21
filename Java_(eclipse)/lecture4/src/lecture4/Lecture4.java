package lecture4;


public class Lecture4 {
		public String acctitle;
		public int accno;
		public double accbalance;
		public void deposit (double ammount) {
			accbalance = accbalance+ammount;
		}
		public void takeout (double amount) {
			accbalance = accbalance-amount;
		} 
		public void minus (double amount) {
			accbalance = accbalance -500;
		}
		public void show () {
			System.out.println(acctitle);
			System.out.println(accno);
			System.out.println(accbalance);
		}
			
	}

