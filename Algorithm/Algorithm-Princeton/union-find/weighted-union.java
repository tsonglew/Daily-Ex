public class QuickUnionUF
{
    private int[] id;
    private int[] sz;

    public QuickUnionUF(int N)
    {
        id = new int[N];
        for(int i = 0; i < N; i++)
        {
            id[N] = i;
            sz[N] = 1;
        }
    }

    private int root(int i)
    {
        while(id[i] != i)
        {
            // path compression
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    public boolean connected(int p, int q)
    {
        return root(p) == root(q);
    }

    public void union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if(i==j) return;
        if(sz[i] < sz[j]) {id[p] = j; sz[j] += sz[i]}
        else {id[q] = i; sz[i] += sz[j]}
    }
}
