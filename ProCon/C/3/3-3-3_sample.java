// http://tookunn.hatenablog.com/entry/2016/11/10/215714
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
class P implements Comparable<P>{
	int x,y;
	public P(int x,int y){
		this.x = x;
		this.y = y;
	}
	public int compareTo(P p){
		if(this.x == p.x){
			return this.y - p.y;
		}
		return this.x - p.x;
	}
}
public class Main {
	int N,D;
	P[] points;
	
	public boolean check(){
		for(int i = 0;i < N;i++){
			if(points[i].y > D){
				return false;
			}
		}
		return true;
	}

	public void solve() {
		int cnt = 1;

		while(true){
			N = nextInt();
			D = nextInt();

			if(N + D == 0)break;

			points = new P[N];

			for(int i = 0;i < N;i++){
				int x = nextInt();
				int y = nextInt();
				points[i] = new P(x,y);
			}

			Arrays.sort(points);

			int ans = 1;
			
			if(!check()){
				out.println("Case " + cnt + ": " + "-1");
			}else{
				double X = points[0].x;
				double Y = points[0].y;
				
				double radarX = X + Math.sqrt(D * D - Y * Y);

				for(int i = 1;i < N;i++){
					int x = points[i].x;
					int y = points[i].y;
					
					double pointLeft = x - Math.sqrt(D * D - y * y);
					
					if(pointLeft > radarX){
						X = points[i].x;
						Y = points[i].y;
						
						radarX = X + Math.sqrt(D * D - Y * Y);
						ans++;
					}else{
					    radarX = Math.min(radarX, x + Math.sqrt(D * D - y * y));
					}
				}

				out.println("Case " + cnt + ": " + ans);
			}

			cnt++;
		}
	}

	public static void main(String[] args) {
		out.flush();
		new Main().solve();
		out.close();
	}
	
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}

	private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}

	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}