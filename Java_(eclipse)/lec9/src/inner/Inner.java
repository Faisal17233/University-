package inner;

public class Inner {
   private int F=10;
	private class Inn {//inner class can be protected and private 
		private int A=10;
		
		public void get() {
			System.out.println(F);
		    F=20;
		}
	}
    public static void main(String[] args) {
Inner a1=new Inner();
Inner.Inn a2=a1.new Inn();
	a2.get();
	a2.get();
    a2.A=3;
    }

}
