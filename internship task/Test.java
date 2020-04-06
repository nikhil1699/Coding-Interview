import java.io.*;
import java.util.*;

class User implements Serializable {

    private int userID;
    double latitude;
    double longitude;
    boolean gender; // True for Female, False for Male
    boolean preferredGender; // True for Female, False for Male

    User(int userID, double latitude, double longitude, boolean gender, boolean preferredGender) {
        this.userID = userID;
        this.latitude = latitude;
        this.longitude = longitude;
        this.gender = gender;
        this.preferredGender = preferredGender;
    }

    void displayDetails() {
        System.out.println(userID);
        System.out.println(latitude);
        System.out.println(longitude);
        System.out.println(gender);
        System.out.println(preferredGender);
    }
}

class Simulator {

    Map<User, User> match;
    Map<User, User> unmatched;
    private int n;

    Simulator(int n) {
        match = new HashMap<>();
        this.n = n;
    }

    private static double haversine(User u1, User u2) {
        double lat1 = u1.latitude;
        double lon1 = u1.longitude;
        double lat2 = u2.latitude;
        double lon2 = u2.longitude;

        // distance between latitudes and longitudes
        double dLat = Math.toRadians(lat2 - lat1);
        double dLon = Math.toRadians(lon2 - lon1);

        // convert to radians
        lat1 = Math.toRadians(lat1);
        lat2 = Math.toRadians(lat2);

        // apply formulae
        double a = Math.pow(Math.sin(dLat / 2), 2) + Math.pow(Math.sin(dLon / 2), 2) * Math.cos(lat1) * Math.cos(lat2);
        double rad = 6371;
        double c = 2 * Math.asin(Math.sqrt(a));
        return rad * c * 1000;
    }

    private static boolean possibleGenderMatch(User u1, User u2) {
        return u1.preferredGender == u2.gender && u2.preferredGender == u1.gender;
    }

    void generateUsers() {
        System.out.println("Generating " + n + " random users.");
        User[] u = new User[n];

        final double latMin = 10.49;
        final double latMax = 10.5;
        final double longMin = 70.49;
        final double longMax = 70.5;

        for (int i = 0; i < n; i++) {
            Random r = new Random();
            double randomLatitude = latMin + (latMax - latMin) * r.nextDouble();
            double randomLongitude = longMin + (longMax - longMin) * r.nextDouble();
            boolean randomGender = r.nextBoolean();
            boolean randomPreferredGender = r.nextBoolean();
            u[i] = new User(i + 1, randomLatitude, randomLongitude, randomGender, randomPreferredGender);
        }

        try {
            FileOutputStream f = new FileOutputStream(new File("myObjects.txt"));
            ObjectOutputStream o = new ObjectOutputStream(f);

            for (int i = 0; i < n; i++) {
                o.writeObject(u[i]);
            }
            o.close();
            f.close();

        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            System.out.println("Error initializing stream");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void findMatches() {
        ArrayList<User> al = new ArrayList<>();

        try {
            FileInputStream fi = new FileInputStream(new File("myObjects.txt"));
            ObjectInputStream oi = new ObjectInputStream(fi);

            for (int i = 0; i < n; i++) {
                User temp = (User) oi.readObject();
                al.add(temp);
            }
            oi.close();
            fi.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        unmatched = new HashMap<>();
        for (int i = 0; i < n; i++) {
            User u1 = al.get(i);
            for (int j = i + 1; j < n; j++) {
                User u2 = al.get(j);
                double dist = haversine(u1, u2);
                boolean genderPreferred = possibleGenderMatch(u1, u2);
                // System.out.println(dist + " " + genderPreferred);
                if (dist < 500 && genderPreferred) {
                    match.put(u1, u2);
                } else {
                    unmatched.put(u1, u2);
                }

            }
        }

    }
}

public class Test {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Number of users: ");
        int n = s.nextInt();
        s.nextLine();
        Simulator simulator = new Simulator(n);
        simulator.generateUsers();

        simulator.findMatches();

        System.out.println("Matches found: " + simulator.match.size());
        for (Map.Entry mE : simulator.match.entrySet()) {
            System.out.println("===================================");
            ((User) mE.getKey()).displayDetails();
            ((User) mE.getValue()).displayDetails();
            System.out.println("===================================");
        }

        System.out.println("****************************************");
        System.out.println("****************************************");
        System.out.println("****************************************");
        System.out.println("****************************************");
        System.out.println("****************************************");

        System.out.println("Unmatched people :");
        for (Map.Entry umE : simulator.unmatched.entrySet()) {
            System.out.println("===================================");
            ((User) umE.getKey()).displayDetails();
            ((User) umE.getValue()).displayDetails();
            System.out.println("===================================");
        }

    }
}

// How to run:
/*
 * 
 * javac test.java java test
 * 
 * 
 * Just input total number of random users you want to generate in the first
 * input prompt Thats it !
 * 
 * Output shows total number of matches as well as details of all the matches in
 * a radius of 500 meters and also all the unmatched people separately.
 * 
 */