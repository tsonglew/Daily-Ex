public class QuickFindUF
{
    private int[] id;

    // Set id of each object to itself
    public QuickFindUF(int N)
    {
        id = new int[N];
        for(int i = 0; i < N; i++)
            id[N] = i;
    }

    // check if p and q are in the same component
    public boolean connected(int p, int q)
    {
        return id[p] == id[q];
    }

    // change all entries with id[p] to id[q]
    public void union(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];
        for(int i = 0; i < id.length; i++)
        {
            if(id[i] == pid)
                id[i] = qid;
        }
    }
}
