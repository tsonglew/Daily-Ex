public class LiftOff implements Runnable {
    protected int count = 10;
    private static int taskCount = 0;
    private final int taskId = ++taskCount;
    public LiftOff() {
    }
    private String status() {
        return "#" + taskId + "(" + (count > 0 ? count : "LiftOff!") + ") ";
    }
    public void run() {
        while (count-- > 0) {
            System.out.print(status());
            //Thread.yield();
        }
    }
}
