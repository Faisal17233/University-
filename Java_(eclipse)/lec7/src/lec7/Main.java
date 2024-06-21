package lec7;

class Parent{

}
	public class Main extends Parent{
	

	static int counter =0;
    final String name;
    String seatno;
    
    Main (String d,String a){
    counter ++;
    this.name=d;
    this.seatno=a;
    }
    
    void display() {
    add(2,4); //calling static method in non static
    System.out.println(counter);
    System.out.println(name);
    System.out.println(seatno);
    }
    
    static int add(int x,int y) {
    	System.out.println("int");
    	int c=x+y;
        return c;
    }
    static double add(double x,double y) {
    	System.out.println("long");
    	double c=x+y;
        return c;
    }
    
   
}
