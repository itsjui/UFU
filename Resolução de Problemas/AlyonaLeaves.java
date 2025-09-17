import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class AlyonaLeaves{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();
        
        Set<String> uniqueLeaves = new HashSet<>();
        for(int i = 0; i < n; i++){
            String leaf = sc.nextLine();
            uniqueLeaves.add(leaf);
        }
        System.out.println(uniqueLeaves.size());
        sc.close();
    }
}