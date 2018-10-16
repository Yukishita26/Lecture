import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.*;

class XY implements Comparable<XY> {
    int x, y;
    public XY(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public int compareTo(XY xy) {
        return (this.x == xy.x) ? this.y - xy.y : this.x - xy.x;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        new Main().execute();
    }

    public void execute() {
        Scanner sc = new Scanner(in);
        int cs = 1;
        while (true) {
            n = sc.nextInt();
            R = sc.nextInt();
            if (n == 0 && R == 0) {
                break;
            }

            xy = new XY[n];
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                xy[i] = new XY(x, y);
            }

            out.printf("Case %d: %d%n", cs, solve());
            cs++;
        }
    }
    int n, R;
    XY[] xy;

    int solve() {
        for(XY ab: xy){
            if(ab.y > R) return -1;
        }
        Arrays.sort(xy);
        int r = 1;
        int x = xy[0].x;
        int y = xy[0].y;
        double rightEdge = x + dR(y);
        for (int i = 1; i < n; i++) {
            int xi = xy[i].x;
            int yi = xy[i].y;
            //if (yi > R) {return -1;}
            if (xi - dR(yi) > rightEdge) {
                r++;
                x = xi;
                y = yi;
                rightEdge = x + dR(y);
            } else {
                rightEdge = Math.min(rightEdge, xi + dR(yi));
            }
        }
        return r;
    }

    double dR(int y) {
        return Math.sqrt(R * R - y * y);
    }
}
