import java.util.Arrays;
import java.util.Scanner;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import static java.lang.System.*;
//import java.lang.Math;
class XY implements Comparable<XY>{
    public int x;
    public int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public int compareTo(XY xy){
        return (this.x == xy.x)? this.y - xy.y: this.x - xy.x;
    }
}
public class Main{
    public int n, R;
    public XY[] xy;
    public static void main(String[] args) throws Exception {
        //get();
        new Main().execute();
    }
    public void execute(){
        //try{
            Scanner sc = new Scanner(in);
            //BufferedReader br = new BufferedReader(new InputStreamReader(in));
            int cs=1;
        
            while(true){
                //String[] str = br.readLine().split(" ");
                //n = parseI(str[0]);
                //R = parseI(str[1]);
            
                n = sc.nextInt();
                if(n==0){break;}
                R = sc.nextInt();
            
                xy = new XY[n];
                for(int i=0; i<n; i++){
                    //str = br.readLine().split(" ");
                    xy[i] = new XY(sc.nextInt(), sc.nextInt());//parseI(str[0]), parseI(str[1]));
                }
                //br.readLine();
            
                out.printf("Case %d: %d%n", cs, solve());
                cs++;
            }
        //}catch (IOException e){
        //    err.println(e);
        //}
    }
    public int solve(){
        Arrays.sort(xy);
        int r = 1;
        int x = xy[0].x;
        int y = xy[0].y;
        double rightEdge = x + dR(y);
        for(int i=1; i<n; i++){
            int xi = xy[i].x;
            int yi = xy[i].y;
            if(yi > R){return -1;}
            if(x+dR(y) < xi-dR(yi)){
                r++;
                x = xi;
                y = yi;
                rightEdge = x + dR(y);
            }else{
                rightEdge = Math.min(rightEdge, xi+dR(y));
            }
        }
        return r;
    }
    public double dR(int y){
        return Math.sqrt(R*R-y*y);
    }
    public int parseI(String s){
        return Integer.parseInt(s);
    }
}
