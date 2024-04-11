package Linked_List;
import java.util.*;

public class Linkedlist{
    public static void main(String[] args) {
        
    // ********************************************************************
    
    // LinkedList =  Nodes are in 2 parts (data + address)
    //                        Nodes are in non-consecutive memory locations
    //                        Elements are linked using pointers
            
    //    advantages?
    //    1. Dynamic Data Structure (allocates needed memory while running)
    //    2. Insertion and Deletion of Nodes is easy. O(1) 
    //    3. No/Low memory waste
  
    //    disadvantages?
    //    1. Greater memory usage (additional pointer)
    //    2. No random access of elements (no index [i])
    //    3. Accessing/searching elements is more time consuming. O(n)

    //    uses?
    //    1. implement Stacks/Queues
    //    2. GPS navigation
    //    3. music playlist
  
  // *****************************************************
        
  
        // bad at searching o(n)

        // insertion/deletion o(1)

        //sll:
        //dll:
        LinkedList<String> linkedList = new LinkedList<String>();

        linkedList.offer("A");
        linkedList.offer("B");
        System.err.println(linkedList);        
        // terminal: [A,B]

        linkedList.offer("C");
        linkedList.offer("D");
        linkedList.offer("F");
        // linkedList.pop();
        // System.out.println(linkedList);

        linkedList.add(4,"E");
        linkedList.remove("E");

        System.out.println(linkedList.peekFirst());
        System.out.println(linkedList.peekLast());
        linkedList.addFirst("0");
        linkedList.addFirst("G");

        System.out.println(linkedList);
        
        // terminal: [B, C, D, F]
    }
}

