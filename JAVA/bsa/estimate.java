package bsa;
import java.util.Random;
    
class estimate {

    public static void main(String args[]) {

	Random r = new Random();
	
	System.out.print("Enter a number of points: ");
	int N = Integer.parseInt(System.console().readLine());

	int hit=0;
	double x,y,d;
	for (int i=0; i < N; i++) {
	    // generate a random point (x,y) between (0,0) and (1,1)
	    x = r.nextDouble();
	    y = r.nextDouble();
	    d = Math.sqrt(x*x+ y*y);
	    if ( d < 1)
		hit++;
	}

	double pi = 4 * (double) hit / (double)N;

	System.out.println("Your estimate for pi is " + String.valueOf(pi) + "\n");
	
    }

}
