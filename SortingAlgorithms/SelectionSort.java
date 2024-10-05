import java.io.*;
import java.util.*;

public class SelectionSort{
    static void selection_sort(int[] list){
        int min, temp;

         for(int i = 0; i < list.length; i++){
                min = i;     //Store min: This tracks the position of the smallest element found in the unsorted portion.

             for(int j = i + 1; j < list.length; j++){  //nner loop starts at i + 1: This ensures you're only comparing unsorted elements.
                if(list[j] < list[min]){
                    min = j;    // if a smaller min found update min with its index                              
                }
             }

                // Swap outside the inner loop: Once the smallest element is found, it is swapped with the element at position i.
               
            if (min != i) {      // If a new minimum is found, swap it with the element at index i
                temp = list[min];
                list[min] = list[i];
                list[i] = temp; 
              }   
         }
    }
   //// Function to print the array  
      static void printArray(int[] arr){
        for (int val : arr) {
            System.out.print(val + " ");
        }
        System.out.println();
    }


        public static void main(String[] args) {
        int[] list = {64, 25, 12, 22, 11};
        selection_sort(list);

        // Print sorted list
        System.out.println(Arrays.toString(list));
        }
}