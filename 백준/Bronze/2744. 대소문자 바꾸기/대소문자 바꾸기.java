import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	

	public static void main(String[] args) throws Exception {

		String s = br.readLine();
		
		for(int i=0; i<s.length(); ++i) {
			char c = s.charAt(i);
			
			if(Character.isUpperCase(c)) {
				System.out.print(String.valueOf(c).toLowerCase());
			}
			else {
				System.out.print(String.valueOf(c).toUpperCase());
			}
		}
		
	}

}
