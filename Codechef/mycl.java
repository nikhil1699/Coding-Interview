

import java.util.*;
import java.io.*;
import java.util.Arrays;
import java.lang.*;
import java.util.concurrent.ThreadLocalRandom;

class InvalidAgeException extends Exception {
    InvalidAgeException(String s) {
        super(s);
    }
}

class InvalidNameException extends Exception {
    InvalidNameException(String s) {
        super(s);
    }
}

class TestCustomException1 {
    static void validate(int age, String name) throws Exception {
        if (age < 18)
            throw new InvalidAgeException("not valid");
        else
            System.out.println("Inside TestCustom");
        if (name.trim().equalsIgnoreCase("NA")) {
            throw new InvalidNameException("Some Exception in TestCustom");
        } else {
            System.out.println("Hello "+ name );
        }
    }

public static void main(String args[]){
try{
validate(21,"Nikhil");
}
catch(Exception m){
if(m instanceof InvalidNameException){
System.out.println("Invalid name has been entered and a exception has occured");
}
if(m instanceof InvalidAgeException){
System.out.println("Invalid age has been entered and a exception has occured");
}

System.out.println("Lorem Ipsum");
}
}
}