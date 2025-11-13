package JCF;
import java.util.Arrays;

public class ArraysClassDemo {
    public static void main(String[] args){
        //ArraysClass

        int[] numbering = {1, 2, 3, 4, 5, 6, 7};
        
        // Fixed: Store or use the result of binarySearch
        int index = Arrays.binarySearch(numbering, 7);  //binarysearch works in sorted array only, gives index of the element
        System.out.println("Index of 7: " + index);

        Arrays.sort(numbering); //sorts array if not in order (already sorted in this case)
        
        System.out.println("Sorted array:");
        for(int i : numbering){
            System.out.println(i); // Fixed: prints each element of the sorted array
        }

        Arrays.fill(numbering, 12); //fills whole array with 12
        
        // Added: Print the filled array to show the result
        System.out.println("\nArray after fill:");
        for(int i : numbering){
            System.out.println(i);
        }
        
        // Alternative: Print entire array at once
        System.out.println("\nArray as string: " + Arrays.toString(numbering));
    }
}