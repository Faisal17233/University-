package lec7;

public class Test{

	static {                                   //static block
		System.out.println("hello sabeeh");
	}
 	public static void main(String[] args) {
 	    System.out.println(Main.add(2,4));
 		
 		Main a1=new Main("faisal","6028");
 	    Main a2=new Main("sameer","0000");
 	   a1.display();
 	  System.out.println("gap"); 
 	   a2.display();
 	   System.out.println(Main.add(2.2, 4));
 	   System.out.println(Main.counter);
 	   //a1.name="fa"; can't change it because final 	
 	   a1.counter=3; 
 	   System.out.println(Main.counter);
 	}

}

