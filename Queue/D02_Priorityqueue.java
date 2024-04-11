package Queue;
import java.util.*;

public class D02_Priorityqueue {

    // Priority Queue = A LiFO data structure that serves elements
    //                  with the highest priorities first
    //                  before elements with lower priority

    public static void main(String args[]) {

        // Queue<Double> queue = new LinkedList<>();
        Queue<Double> queue = new PriorityQueue<>();

        queue.offer(3.0);
        queue.offer(3.8);
        queue.offer(2.0);
        queue.offer(2.5);
        queue.offer(2.1);

        while(!queue.isEmpty()) {
            System.out.println(queue.poll());
        }

        

        Queue<String> queue2 = new PriorityQueue<>(Collections.reverseOrder());

        queue2.offer("B");
        queue2.offer("C");
        queue2.offer("A");
        queue2.offer("F");
        queue2.offer("D");

        while(!queue.isEmpty()) {
            System.out.println(queue.poll());
        }


    }
}
