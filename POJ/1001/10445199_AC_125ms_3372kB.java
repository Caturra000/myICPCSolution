import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			BigDecimal a = sc.nextBigDecimal();
			int N = sc.nextInt();
			a=a.pow(N);
			String s = a.stripTrailingZeros().toPlainString();
			if(s.startsWith("0.")) {
				System.out.println(s.substring(1));
			}
			else {
				System.out.println(s);
			}
		}
	}
}