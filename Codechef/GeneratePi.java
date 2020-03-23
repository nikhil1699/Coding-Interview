package classes_and_objects;
import java.util.*;
import java.io.*;
import java.util.Arrays;
import java.lang.*;
public class GeneratePi {
    public static void main(String[] args){
        ComputationThread c= new ComputationThread();
            c.run();
    
        }
    private static class ComputationThread extends Thread {
    final int BATCH_SIZE = 47700000;
    long trialCount;
    long inCircleCount;
    public ComputationThread() {
        setDaemon(true);
        setPriority(Thread.currentThread().getPriority() - 1);
    }

    public void run() {
    while (true) {
    for (int i = 0; i < BATCH_SIZE; i++) {
    double x = Math.random();
    double y = Math.random();
    trialCount++;
    if (x*x + y*y < 1)
    inCircleCount++;
    }
    double estimateForPi = 4 * ((double)inCircleCount / trialCount);
    System.out.println(estimateForPi);
    break;
    }
}
}
}

public class TestUniqueIdNotAtomic {

    private final UniqueIdNotAtomic uniqueId = new UniqueIdNotAtomic();

    private long firstId;

    private long secondId;

    private void updateFirstId() {

        firstId  = uniqueId.nextId();

    }

    private void updateSecondId() {

        secondId = uniqueId.nextId();

    }

   

