import java.io.*;
import java.util.*;

public class Linearsearch{
    static void linearSearch(int a[], int n, int key){
      int i, count = 0;  
        for (i = 0; i < n; i++){
            if(a[i] == key){
                System.out.println("key is found at position: "+ (i+1));
                count += 1;
            }
        }
        if(count == 0){
            System.out.println("key not found!");
        }
    }
    public static void main(String[] args){
        int n, key;
        int a[] = {1, 5, 4, 12, 68, 22};
         n = 6;
         key = 12;
      linearSearch(a, n, key);
         key = 20;
      linearSearch(a, n, key);         
    }
}