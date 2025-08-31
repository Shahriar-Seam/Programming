import java.util.Scanner;

public class temp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += sumOfDigits(i);
        }

        System.out.println("Total sum of digits from 1 to " + n + " is: " + sum);
    }

    public static int sumOfDigits(int n) {
        int sum = 0;
        
        while (n != 0) {
            sum += n % 10;

            n /= 10;
        }

        return sum;
    }
}