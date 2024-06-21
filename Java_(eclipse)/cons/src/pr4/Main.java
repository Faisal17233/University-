package pr4;

public class Main {
String ear,eye;
	
    public Main(String d,String a){
	eye="eye";
	ear="ear";
}
 public Main(){
	 
 }
    
	 
	public static void main(String[] args) {
    Main a=new Main("s","a");
    User u=new User();
    System.out.println(a.eye);
    System.out.println(u.ear);
    System.out.println(u.eye);
    System.out.println(a instanceof User);
	}

}
