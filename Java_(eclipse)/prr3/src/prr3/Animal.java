package prr3;


public class Animal {
	String fur,eye;
	Animal(String d,String a) {
		this.fur = d;
		eye = a;}
		public static void main(String[] args) {
			Animal l = new Animal("yes","No");
			Dog a = new Dog("2", "yes");
			//System.out.println(a.bark);
			System.out.println(l instanceof Dog);
			a.getbark();
			System.out.println(l.eye);
			System.out.println(a.eye);
		}
}
		
		
		

