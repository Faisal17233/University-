package lec9;

public class Address {

	private int streetNum;
	String city;
	String State;
     String country;
	Address(int street,String c,String st,String coun){
		this.streetNum=street;
		this.city=c;
		this.State=st;
		this.country = coun;
		
	}
public int getstr() {
	return streetNum;
}
public void setstr(int a) {
	streetNum=a;
}

}

	class Student{
	int rollNum;
	String studentName;
	//creating HAS-A relationship with Address class
	Address studentAddr;
	Student(int roll,String name,Address adr){
		this.rollNum=roll;
	    this.studentName=name;			
	    this.studentAddr=adr;
	}
	public static void main(String[] args) {
		Address a1= new Address(55,"Agra","up","Bajwa harami");
		Student a2=new Student(10,"Faisal",a1);
		System.out.println(a2.rollNum);
		System.out.println(a2.studentName);
		System.out.println(a2.studentAddr.country);
		System.out.println(a2.studentAddr.getstr());
		a2.studentAddr.setstr(20);
		System.out.println(a2.studentAddr.getstr());
	    a1.setstr(420);
	    System.out.println(a2.studentAddr.getstr());
	    System.out.println(a1.getstr());
	    System.out.println(a2.studentAddr.equals(a1));
	}
	

}
