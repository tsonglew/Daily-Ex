import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final double meanVal;
    private final double stddevVal;
    private final double confidenceLoVal;
    private final double confidenceHiVal;
    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) {
            throw new IllegalAccessError();
        }
        double[] thresholds = new double[trials];
        for (int i = 0; i < trials; ++i) {
            Percolation p = new Percolation(n);
            int times = 0;
            while (!p.percolates()) {
                int row = StdRandom.uniform(1, n+1);
                int col = StdRandom.uniform(1, n+1);
                if (p.isOpen(row, col) || p.isFull(row, col)) {
                    continue;
                }
                p.open(row, col);
                times += 1;
            }
            thresholds[i] = (double) times / (double) (n*n);
        }
        meanVal = StdStats.mean(thresholds);
        stddevVal = StdStats.stddev(thresholds);
        double conf = 1.96 * stddevVal / Math.sqrt(trials);
        confidenceLoVal = meanVal - conf;
        confidenceHiVal = meanVal + conf;
    }

    public double mean() {
        return meanVal;
    }
    public double stddev() {
        return stddevVal;
    }
    public double confidenceLo() {
        return confidenceLoVal;
    }
    public double confidenceHi() {
        return confidenceHiVal;
    }
 
    public static void main(String[] args) {
        PercolationStats ps = new PercolationStats(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        System.out.println("mean                    = " + ps.mean());
        System.out.println("stddev                  = " + ps.stddev());
        System.out.println("95% confidence interval = " + ps.confidenceLo()
                             + ", " + ps.confidenceHi());
    }
 }