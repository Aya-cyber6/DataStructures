import java.io.*;
import java.util.*;

public class Binary_recursion{
    static void binary(int a[], int lowerBound, int upperBound, int key){
        int mid = (upperBound + lowerBound) / 2;
        if(lowerBound <= upperBound){
            if (a[mid] == key){
                    System.out.println("key found at index: " + (mid));
            }
            else if(a[mid] < key){
                binary( a, mid + 1, upperBound, key);
            }
            else if(a[mid] > key){
                binary( a, lowerBound, mid - 1, key);
            }
        }
        else if(lowerBound > upperBound){
            System.out.println("No result");
        }
    }
    public static void main( String args[] ){
      int n, key, low, high;
      n = 5;
      low = 0;
      high = n-1;
      int a[] = {12, 14, 18, 22, 39};
      key = 22;
      binary(a, low, high, key);
      key = 23;
      binary(a, low, high, key);
    }
    
}