import java.util.*;
import java.io.*;
import java.lang.*;

class CLASS01 {
    public void f() throws Exception {
        System.out.println("Inside CLASS01 fun()");
    }
}

class CLASS02 extends CLASS01 {
    // @Override
    public void f() throws Exception {
        System.out.println("Inside CLASS02 fun()");
    }
}

class CLASS03 extends CLASS02 {
    // @Override
    public void f() throws Exception {
        System.out.println("Inside CLASS03 fun() ");
    }
}

public class threeLevel {
    public static void main(String args[]) {
        CLASS01 c1 = new CLASS03();
        try {
            c1.f();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}