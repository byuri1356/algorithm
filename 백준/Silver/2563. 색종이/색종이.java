import java.util.Scanner;

public class Main {

	static int a,b;
	
	static boolean _map[][] = new boolean[100][100];
	
	static int ans =0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		for(int i = 0; i < N; ++i) {
			a = sc.nextInt();  //3
			b = sc.nextInt();  //7
			
			for(int j=a; j<a+10; ++j) {
				for(int k=b; k<b+10; ++k) {
					if(!_map[j][k]) {
						_map[j][k] = true;
						ans++;
					}
				
				}
			}
		}
		
		System.out.println(ans);
	}

}
