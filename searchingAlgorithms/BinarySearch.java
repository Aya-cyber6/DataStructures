import java.io.*;
import java.util.*;

      //// My implementation (did not use recursion)

public class BinarySearch{
    static void binarysearch(int a[], int n, int key){

        int i, middle_index, upperBound, lowerBound;
        upperBound = n;
        lowerBound = 1;
        
        middle_index = lowerBound + ( upperBound - lowerBound ) / 2;
        while (a[middle_index] != key){

            if (upperBound < lowerBound){
                System.out.println("No key...");
                return;
            }
           
            if (key > a[middle_index]){
                lowerBound = middle_index + 1;
                middle_index = lowerBound + ( upperBound - lowerBound ) / 2;
            }
            else if (key < a[middle_index]){
                 upperBound = middle_index - 1;
                 middle_index = lowerBound + ( upperBound - lowerBound ) / 2;
            }   
        }
        System.out.println("key found at position: " + (middle_index + 1));
        }

      public static void main(String[] args){

        int n, key;
        int a[] = {1, 3, 4, 12, 18, 23};
         n = 6;
         key = 12;
      binarysearch(a, n, key);
         key = 18;
      binarysearch(a, n, key);         
    }
}