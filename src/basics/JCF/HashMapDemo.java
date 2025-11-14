package JCF;
import java.util.Map;
import java.util.HashMap;

public class HashMapDemo {
    public static void main(String[] args){
        //HashMap (map) prints key & their values, keys are unique (it cant be repeated)
        //implementation of TreeMap in rhs is same as below, it just prints in sorted order or alphabetical u can say

        Map<String, Integer> nums = new HashMap<>();
        nums.put("one", 1);
        nums.put("two", 2);
        nums.put("two", 23); //overrides the key two
        nums.putIfAbsent("two", 23); //puts only if key absent (won't add since "two" exists)
        
        // Fixed: Store or use the results of contains methods
        boolean hasKey66 = nums.containsKey("66"); //gives boolean - Fixed: should be String not int
        System.out.println("Contains key '66': " + hasKey66);
        
        boolean hasValue77 = nums.containsValue(77); //gives boolean
        System.out.println("Contains value 77: " + hasValue77);
        
        boolean empty = nums.isEmpty(); //gives boolean
        System.out.println("Is empty: " + empty);
        
        nums.remove("two"); //removes key
        System.out.println("\nAfter removing 'two': " + nums);

        System.out.println("\nIterating through entries:");
        for(Map.Entry<String, Integer> e: nums.entrySet()){
            System.out.println(e); //prints the key=value pair
            System.out.println("Key: " + e.getKey()); //prints key
            System.out.println("Value: " + e.getValue()); //prints value
            System.out.println("---");
        }

        System.out.println("\nIterating through keys:");
        for(String key : nums.keySet()){
            System.out.println(key); // Fixed: prints the key
        }

        System.out.println("\nIterating through values:");
        for(Integer value : nums.values()){
            System.out.println(value); // Fixed: prints the value
        }
    }
}