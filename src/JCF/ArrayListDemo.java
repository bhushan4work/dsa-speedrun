package JCF;
import java.util.List;
import java.util.ArrayList;

public class ArrayListDemo {
    public static void main(String[] args){
        //ArrayList
        //LHS is interface & RHS is implementation
        ArrayList<String> name = new ArrayList<>(); // makes empty array
        name.add("sam"); // can add no of strings in this array

        List<Integer> list = new ArrayList<>(); //to do LinkedList (List) just change ArrayList to LinkedList here
        list.add(4);
        list.add(9);
        list.add(1, 67); // adds 67 at index1 in this array

        List<Integer> newlist = new ArrayList<>();
        newlist.add(10);
        newlist.add(34);
        //list.addAll(newlist);   //adds newlist to the list

        list.remove(Integer.valueOf(4)); //removes 4 once from the array
        //list.clear(); //clears all elements from the list
        list.set(1, 100); //replaces value at index1 to 100
        
        // Fixed: Store the result of contains() or use it in a condition
        boolean exists = list.contains(50); //gives boolean if 50 exists in array or not
        System.out.println("Does list contain 50? " + exists);

        // Print the final list
        System.out.println("Final list: " + list);

        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));  //iterates the array
        }
        
        for (Integer element : list) {
            System.out.println("element is " + element); // 'for each' loop
        }
    }
}