import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {

		int idx = 1, sum = 0;
		boolean tk = true;
		String s = br.readLine();

		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '+') {
				idx++;
			}
			if (s.charAt(i) == '-') {
				tk = false;
				break;
			}
		}

		String[] arr = s.split("\\+|-");

		if (tk) {
			for (int i = 0; i < arr.length; ++i) {
				sum += Integer.parseInt(arr[i]);
			}
		}

		else {
			for (int i = 0; i < idx; ++i) {
				sum += Integer.parseInt(arr[i]);
			}
			for (int i = idx; i < arr.length; ++i) {
				sum -= Integer.parseInt(arr[i]);
			}
		}
		
		System.out.println(sum);

	}

}
