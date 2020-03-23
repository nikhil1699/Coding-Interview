import java.util.Scanner; // Import the Scanner class
import java.util.Arrays; // Import the Arrays class

public class MeshGrid{
    public static void main(String[] args)
    {
         if(args.length!=3){
            System.out.println("No arguments!");
            System.exit(1);
        }
        int nx = Integer.parseInt(args[0]);
        int ny = Integer.parseInt(args[1]);
        int nz = Integer.parseInt(args[2]);
        int [] x = new int[nx];
        int [] y = new int[ny];
        int [] z = new int[nz];
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter x coordinates: ");
        for(int i=0;i<nx;i++){
            x[i] = scan.nextInt();
        }
        System.out.println("Enter y coordinates: ");
        for(int i=0;i<ny;i++){
            y[i] = scan.nextInt();
        }
        System.out.println("Enter z coordinates: ");
        for(int i=0;i<nz;i++){
            z[i] = scan.nextInt();
        }

        Arrays.sort(x);
        Arrays.sort(y);
        Arrays.sort(z);
        int rows  = y.length;
        int cols = x.length ;
        int dim = z.length ;
        int [][] X = new int[rows][cols];
        int [][] Y = new int[rows][cols];
        int [][][] Z = new int[dim][rows][cols];

        for(int i=0;i<rows;i++)
        {
            for (int j = 0; j <cols; j++) {
                X[i][j] = x[j];
                Y[i][j] = y[i];
            }
        }

        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    int h=z[i];
                    Z[i][j][k] = h;
                }
            }
        }



        //Printing 2D Mesh :

        System.out.println("2D - Mesh: ");
        System.out.println("X = ");

        for(int i=0;i<rows;i++)
        {
            for (int j = 0; j <cols; j++) {
                System.out.print(X[i][j]+" ");
            }
            System.out.println("");
        }

        System.out.println("Y = ");

        for(int i=0;i<rows;i++)
        {
            for (int j = 0; j <cols; j++) {
                System.out.print(X[i][j]+" ");
            }
            System.out.println("");
        }

        System.out.println("3-D Mesh : ");

        for (int k = 0; k < dim; k++) {
            System.out.println("X[,,"+(k+1)+"] = ");
            for(int i=0;i<rows;i++)
            {
                for (int j = 0; j <cols; j++) {
                    System.out.print(X[i][j]+" ");
                }
                System.out.println("");
            }
        }

        System.out.println("");

        for (int k = 0; k < dim; k++) {
            System.out.println("Y[,,"+(k+1)+"] = ");
            for(int i=0;i<rows;i++)
            {
                for (int j = 0; j <cols; j++) {
                    System.out.print(Y[i][j]+" ");
                }
                System.out.println("");
            }
        }

        System.out.println("");

        for (int k = 0; k < dim; k++) {
            System.out.println("Z[,,"+(k+1)+"] = ");
            for(int i=0;i<rows;i++)
            {
                for (int j = 0; j <cols; j++) {
                    System.out.print(Z[k][i][j]+" ");
                }
                System.out.println("");
            }
        }











    }
}