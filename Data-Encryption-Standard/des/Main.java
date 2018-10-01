package des;

public class Main {
    public static void main(String[] args) {

    }
}

class DES {
    private static final int MLength = 64;
    private static final int LLength = 32;
    private static final int RLength = 32;
    private static final int KLength = 64;
    private static final int KPlusLength = 56;
    private static final int subKeyLength = 48;
    private static final int subKeyNums = 16;

    private static int[] PC1(int[] K) {
        int[] KPlus = new int[KPlusLength];
        int[] translateTable = new int{
            57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51,
            43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28,
            20, 12, 4
        }
        int cnt = 0;
        for (int t : translateTable) {
            KPlus[cnt++] = K[t];
        }
        return KPlus;
    }

    private static int[] generateSubkey(int[] key) {
        int[] subKeys = new int[subKeyNums];
        int[] shifts = new int{
            1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
        }
        result[0] = 0;
        for (int i = 0; i < key.length; ++i) {
            subKeys[0] += (key[i] << i);
        }
        for (int i = 1; i <= 16; ++i) {
            subKeys[i] = subKeys[i-1] << shifts[i-1];
        }
        return subKeys;
    }

    private static int[] IP(int[] M) {
        int[] result= new int[64];
        int[] translateTable = new int{
            58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62,
            54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49,
            41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37,
            29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
        }
        int cnt = 0;
        for (int t : translateTable) {
            result[cnt++] = M[t];
        }
        return result;
    }

    private static encryptWithSubkey(int[] IP, int[] Ks) {
        int[] L0 = new int[32];
        int[] R0 = new int[32];
        for (int i = 0; i < IP.length / 2; ++i) {
            L0[i] = IP[i];
            R0[i] = IP[i+IP.length/2];
        }

    }
}

