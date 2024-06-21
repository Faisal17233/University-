package lec5;

public class Userr extends Main {
Userr (){
	 System.out.println("hello");

}
public static void main(String[] args) {
Userr a1=new Userr();//
Main ob = new Main();
System.out.println(ob.getdes());
ob.setdes("saw");
System.out.println(ob.getdes());
	}

}
