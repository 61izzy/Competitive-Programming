import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int month = scanner.nextInt(), day = scanner.nextInt();
        
        System.out.println(month < 2 ? "Before" : month > 2 ? "After" : day < 18 ? "Before" : day > 18 ? "After" : "Special");
    }
}
