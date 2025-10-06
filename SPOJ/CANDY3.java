import java.io.*;
import java.math.*;

public class CANDY3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            br.readLine();
            int n = Integer.parseInt(br.readLine().trim());

            long total = 0;
            for (int i = 0; i < n; i++) {
                long x = Long.parseLong(br.readLine().trim());
                total = (total + x) % n;
            }

            System.out.println(total % n == 0 ? "YES" : "NO");
        }
    }
}
