import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static String arr[];

    public static void main(String[] args) {
        FastReader fs = new FastReader();
        int n = fs.nextInt();int k = fs.nextInt();int l = fs.nextInt();
        int c = fs.nextInt();int d = fs.nextInt();int p = fs.nextInt();
        int nl = fs.nextInt();int np = fs.nextInt();
        int toasts = (k*l)/nl;int limes = c*d;int salt = p/np;
        System.out.println(Math.min(toasts,Math.min(limes,salt))/n);

    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

}
