import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class DIGIT {	
	
	
	public static void main(String[] args) throws IOException {
		BigInteger dp[][] = new BigInteger[10005][2];
		InputStream input = System.in;
		InputReader in = new InputReader(input);		
		int n, k;
		n = in.nextInt();
		k = in.nextInt();
		
		BigInteger K = new BigInteger(k + "");
		BigInteger K_1 = K.subtract(BigInteger.ONE);
		
		dp[1][0] = BigInteger.ONE;	
		dp[1][1] = K_1;
		dp[2][0] = dp[1][1];
		dp[2][1] = dp[1][1].multiply(K_1);
		
		for (int i = 3; i <= n; ++i) {
			dp[i][0] = dp[i - 1][1];		
			dp[i][1] = dp[i - 1][0].add(dp[i- 1][1]).multiply(K_1);
		}
		
		System.out.print(dp[n][0].add(dp[n][1]));
	}
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}

