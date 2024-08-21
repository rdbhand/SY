import java.util.Scanner;

public class Arr
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of Array : ");
        int n=sc.nextInt();
        int []arr=new int[n];
        String []srr=new String[n];
        System.out.println("Enter array num and names : ");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
            srr[i]=sc.next();
        }
        for(int i=0;i<n;i++)
        {
            System.out.println(" "+arr[i]+" "+srr[i]);
        }
    }
}