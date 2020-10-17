public class Laboratory {
    public static void main(String[] args) {
		/*a)Adds an integral amount to the highest primitive value of each primitive type.*/
		System.out.println("a)");
		System.out.println("For integer type +1 :");
		int a=Integer.MAX_VALUE;
		a+=1;
        System.out.println(a);
		System.out.println("For float type +1:");
		float b=Float.MAX_VALUE;
		b+=1;
        System.out.println(b);
		System.out.println("For double type +1:");
		double c=Double.MAX_VALUE;
		c+=1;
        System.out.println(c);
		System.out.println("For long type +1:");
		long d=Long.MAX_VALUE;
		d+=1;
        System.out.println(d);
		System.out.println("b)");
		
		System.out.println("For integer type -1 :");
		a=Integer.MAX_VALUE;
		a-=1;
        System.out.println(a);
		System.out.println("For float type -1:");
		b=Float.MAX_VALUE;
		b-=1;
        System.out.println(b);
		System.out.println("For double type -1:");
		c=Double.MAX_VALUE;
		c-=1;
        System.out.println(c);
		System.out.println("For long type -1:");
		d=Long.MAX_VALUE;
		d-=1;
        System.out.println(d);
		
    }
}

