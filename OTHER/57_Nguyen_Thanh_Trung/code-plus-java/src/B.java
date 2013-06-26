import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.InetSocketAddress;
import java.net.Proxy;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class B implements Runnable {

	private static final String URL = "http://semantics.i2r.a-star.edu.sg/~qamli/dice.cgi?roll=%c%c";
	private static final Proxy PROXY = new Proxy(Proxy.Type.HTTP,
			new InetSocketAddress("proxy", 8080));

	private static final int NUM_TRY = 10;
	private static final int NUM_EACH_TRY = 10;

	private static double[] EXPECTED = new double[13];
	static {
		Arrays.fill(EXPECTED, 0f);
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				EXPECTED[i + j] += 1f / 36;
			}
		}
	}

	/* Don't touch this */
	private static int NUM_DICE = 5;
	private static int NUM_COMB = NUM_DICE * (NUM_DICE - 1) / 2;

	/* Variables */
	private Integer done = 0;

	@SuppressWarnings("unchecked")
	private List<Pair<Integer, Double>>[][] result = new List[NUM_DICE][NUM_DICE];

	@Override
	public void run() {
		for (int diceOne = 0; diceOne < NUM_DICE; diceOne++) {
			for (int diceTwo = diceOne + 1; diceTwo < NUM_DICE; diceTwo++) {
				new Thread(new Roller(diceOne, diceTwo)).start();
			}
		}

		while (true) {
			synchronized (done) {
				if (done >= NUM_COMB) {
					break;
				}
			}
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
			}
		}

		int[][] almost = new int[NUM_DICE][NUM_DICE];
		for (int diceOne = 0; diceOne < NUM_DICE; diceOne++) {
			for (int diceTwo = diceOne + 1; diceTwo < NUM_DICE; diceTwo++) {
				int[] m = new int[13];
				System.out.println(String.format("%c %c:", diceOne + 'A',
						diceTwo + 'A'));
				for (Pair<Integer, Double> p : result[diceOne][diceTwo]) {
					System.out.println(String.format("    %2d: %.2f", p.key,
							p.value));
					m[p.key]++;
				}
				System.out.println();
				int MAX = 0;
				for (int i = 2; i <= 12; i++) {
					if (m[i] * 2 >= NUM_TRY) {
						MAX = i;
					}
				}
				almost[diceOne][diceTwo] = almost[diceTwo][diceOne] = MAX;
			}
		}

		outerLoop: for (int diceOne = 0; diceOne < NUM_DICE; diceOne++) {
			for (int diceTwo = diceOne + 1; diceTwo < NUM_DICE; diceTwo++) {
				for (int diceThree = diceTwo + 1; diceThree < NUM_DICE; diceThree++) {
					if (almost[diceOne][diceTwo] == 0
							|| almost[diceOne][diceThree] == 0
							|| almost[diceTwo][diceThree] == 0) {
						continue;
					}
					int total = (almost[diceOne][diceTwo]
							+ almost[diceOne][diceThree] + almost[diceTwo][diceThree]) / 2;
					int one = total - almost[diceTwo][diceThree];
					int two = total - almost[diceOne][diceThree];
					int three = total - almost[diceOne][diceTwo];
					System.out
							.println(String
									.format("The weighted dices is: (%c, %d-preferred), (%c, %d-preferred), (%c, %d-preferred)",
											diceOne + 'A', one, diceTwo + 'A',
											two, diceThree + 'A', three));
				}
			}
		}
	}

	private void notify(int diceOne, int diceTwo,
			List<Pair<Integer, Double>> strangers) {
		result[diceOne][diceTwo] = strangers;
		synchronized (done) {
			done++;
		}
	}

	private Pair<Integer, Double> stranger(List<Integer> list) {
		double[] a = new double[13];
		for (Integer i : list) {
			a[i] += 1f / list.size();
		}
		double MAX = 0;
		int result = 0;
		for (int i = 2; i <= 12; i++) {
			double d = Math.abs(a[i] - EXPECTED[i]);
			if (d > MAX) {
				MAX = d;
				result = i;
			}
		}
		return new Pair<Integer, Double>(result, MAX);
	}

	final class Roller implements Runnable {

		public final int diceOne;
		public final int diceTwo;

		public List<Pair<Integer, Double>> strangers;

		public Roller(int diceOne, int diceTwo) {
			this.diceOne = diceOne;
			this.diceTwo = diceTwo;
		}

		@Override
		public void run() {
			try {
				doThat();
			} catch (IOException e) {
			}
		}

		public void doThat() throws IOException {
			BufferedReader f = new BufferedReader(
					new InputStreamReader(new FileInputStream(String.format(
							"%d%d", diceOne, diceTwo))));
			strangers = new ArrayList<Pair<Integer, Double>>();
			for (int k = 0; k < NUM_TRY; k++) {
				List<Integer> result = new ArrayList<Integer>();
				for (int t = 0; t < NUM_EACH_TRY; t++) {
					result.addAll(fakeRoll(f.readLine()));
				}
				strangers.add(stranger(result));
			}
			f.close();
			B.this.notify(diceOne, diceTwo, strangers);
		}

		public void doThis() throws IOException {
			FileWriter f = new FileWriter(String.format("%d%d", diceOne,
					diceTwo));
			for (int i = 0; i < NUM_TRY * NUM_EACH_TRY; i++) {
				String s = print(diceOne, diceTwo);
				f.write(s + "\n");
			}
			f.close();
		}

	}

	final class Pair<K, V> {

		public final K key;
		public final V value;

		public Pair(K key, V value) {
			this.key = key;
			this.value = value;
		}

	}

	private List<Integer> roll(int i, int j) {
		String url = String.format(URL, (char) (i + 'A'), (char) (j + 'A'));
		String content;
		while (true) {
			try {
				content = get(url);
				break;
			} catch (IOException e) {
				System.err.println(e.getMessage());
			}
		}
		return fakeRoll(content);
	}

	private List<Integer> fakeRoll(String content) {
		StringTokenizer t = new StringTokenizer(content, "[,]");
		List<Integer> result = new ArrayList<Integer>();
		while (t.hasMoreTokens()) {
			result.add(Integer.valueOf(t.nextToken()));
		}
		return result;
	}

	private String print(int i, int j) {
		String url = String.format(URL, (char) (i + 'A'), (char) (j + 'A'));
		String content;
		while (true) {
			try {
				content = get(url);
				break;
			} catch (IOException e) {
				System.err.println(e.getMessage());
			}
		}
		return content;
	}

	private String get(String url) throws IOException {
		HttpURLConnection conn = (HttpURLConnection) new URL(url)
				.openConnection(PROXY);
		conn.setConnectTimeout(10000);
		conn.setReadTimeout(5000);
		return new BufferedReader(new InputStreamReader(conn.getInputStream()))
				.readLine();
	}

	public static void main(String[] args) {
		new B().run();
	}

}