import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.stream.LongStream;

public class Main {

private static long gcd(long a, long b) {
    while(b != 0) {
        long tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;
    // 1. sum 2. gcd
 
    st = new StringTokenizer(br.readLine());

    long firstElement = Long.parseLong(st.nextToken());
    long index = Long.parseLong(st.nextToken());

    int n = Integer.parseInt(br.readLine());

    while(n-->0) {

        st = new StringTokenizer(br.readLine());

        int query = Integer.parseInt(st.nextToken());
        long first = Long.parseLong(st.nextToken());
        long second = Long.parseLong(st.nextToken());

        if(query == 1) {
            sb.append(
                        LongStream.iterate(firstElement + (index * (first - 1)), i -> i + index)
                                 .limit(second - first + 1)
                                 .sum()).append("\n");
            continue;
        }

        sb.append(
                    LongStream.iterate(firstElement + (index * (first - 1)), i -> i + index)
                             .limit(second - first + 1)
                             .reduce(Main::gcd)
                             .getAsLong()

        ).append("\n");

    }

    bw.write(sb.toString());
    bw.flush();
    bw.close();
    br.close();
}
}