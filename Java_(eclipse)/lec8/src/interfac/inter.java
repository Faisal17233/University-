package interfac;

interface A extends B{
	abstract void method1();
	abstract int method2(int a,int b);
}

interface B{ 
	abstract int method1(int x); // can have same method because only signature but can't have different return type if signature is same
}

interface C extends A{// now while implementing in class you can write class inter implements C
	int a=10;    //it is always public,static,final so you have to give it value when initializing
}

class inter implements C {                //you get error if you dont implement method of interface so either make this class abstract or define methods in class
public void method1() {
	System.out.println("method 1");
}

public int method2(int x,int y) {
	return x * y;
}
public int method1(int a) {
	return a*a*a*a*a*a;
}

public static void main(String[] args) {
		inter a1=new inter();
       a1.method1();
       System.out.println(a1.method2(5,3));
       System.out.println(a1.a);
       System.out.println(inter.a);
       System.out.println(a1.method1(2));
      
}

}
