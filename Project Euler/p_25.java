import java.util.*;
import java.io.*;
import java.math.*;

public class p_25 {
    public static BigInteger fib (int n) {
        BigInteger a = BigInteger.valueOf(0);
        BigInteger b = BigInteger.valueOf(1);
        BigInteger c = BigInteger.valueOf(1);

        for (int i = 2; i < n; i++) {
            c = a.add(b);

            a = b;
            b = c;
        }

        return c;
    }

    public static void main(String[] args) {
        for (int i = 4000; i < 5000; i++) {
            if (fib(i).toString().length() >= 1000) {
                System.out.println(i);

                break;
            }
        }
    }
}