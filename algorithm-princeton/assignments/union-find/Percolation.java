import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final WeightedQuickUnionUF wqu;
    private int openSites = 0;
    private boolean[] opened;
    private boolean[] filled;
    private final int size;
    private final int topIndex;
    private final int bottomINDEX;


    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException();
        }
        size = n;
        topIndex = size * size;
        bottomINDEX = size * size + 1;
        wqu = new WeightedQuickUnionUF(size * size + 2);
        opened = new boolean[size * size];
        for (int i = 0; i < size * size; ++i) {
            opened[i] = false;
        }
    }

    private int toSitesIndex(int x, int y) {
        if (!(1 <= x && x <= size && 1 <= y && y <= size)) {
            throw new IllegalArgumentException();
        }
        return (x - 1) * size + (y - 1);
    }

    public void open(int row, int col) {
        int arrayIndex = toSitesIndex(row, col);
        opened[arrayIndex] = true;
        openSites += 1;

        // connect to virtual top and bottom node
        if (row == 1) {
            wqu.union(arrayIndex, topIndex);
        } 
        if (row == size) {
            wqu.union(arrayIndex, bottomINDEX);
        }

        // connect to adjoining nodes
        if ((row > 1) && (isOpen(row-1, col))) {
            int adjoinIndex = toSitesIndex(row-1, col);
            wqu.union(adjoinIndex, arrayIndex);
        }
        if ((row < size) && (isOpen(row+1, col))) {
            int adjoinIndex = toSitesIndex(row+1, col);
            wqu.union(adjoinIndex, arrayIndex);
        }
        if ((col > 1) && (isOpen(row, col-1))) {
            int adjoinIndex = toSitesIndex(row, col-1);
            wqu.union(adjoinIndex, arrayIndex);
        }
        if ((col < size) && (isOpen(row, col+1))) {
            int adjoinIndex = toSitesIndex(row, col+1);
            wqu.union(adjoinIndex, arrayIndex);
        }
    }

    public boolean isOpen(int row, int col) {
        return (opened[toSitesIndex(row, col)]);
    }

    public boolean isFull(int row, int col) {
        return wqu.connected(topIndex, toSitesIndex(row, col));
    }

    public int numberOfOpenSites() {
        return openSites;
    }

    public boolean percolates() {
        return wqu.connected(topIndex, bottomINDEX);
    }

    public static void main(String[] args) {
    }
}