import java.util.Scanner;
class f1
{
    public int sq(int n)
    {
        return n*n;
    }
    public int qu(int n)
    {
        return n*n*n;
    }
}
class ram
{
    public static void main(String args[])
    {
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter any number : ");
        n=sc.nextInt();
        System.out.println("You Entered : "+n);
        f1 f=new f1();
        System.out.println("Square : "+f.sq(n));
        System.out.println("Cube : "+f.qu(n));
    }
}