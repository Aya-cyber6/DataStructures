import java.io.*;
import java.util.*;

public class Interpolation{
    static int interpolation(int[] a, int key){
         int Hi = a.length - 1;
         int Lo = 0;
         int mid = -1;
         int index = -1;

         while(Hi >= Lo){

            mid = Lo + ((Hi - Lo) / (a[Hi] - a[Lo])) * (key - a[Lo]);

            if(Hi == Lo || a[Lo] == a[Hi]){
                System.out.println("No result");
            }

            if(a[mid] == key){
                index = mid;
                break;
            }
            else{
                if(a[mid] < key){
                    Lo = mid + 1;
                }
                if(a[mid] > key){
                    Hi = mid - 1;          
                }

                }
         }
         return index;
    }
    public static void main(String args[]){
        int[] list = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
        int location =  interpolation(list, 33);

        if(location != -1)
         System.out.println("Element found at location: " + (location+1));
      else
         System.out.println("Element not found.");
   }
 }
