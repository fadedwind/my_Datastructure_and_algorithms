package Queue;
import java.util.Queue;
import java.util.LinkedList;

public class D01_queue {
    public static void main(String[] args) {

        Queue<String> queue = new LinkedList<String>();

        System.err.println(queue.isEmpty());

        // Queue: FIFO(fist in first out)

        // enqueue: to add to the head      -----offer()
        // dequeue: to remove from the head ------poll()
        // peak() examine the top element and return

                                         // position
        queue.offer("Minecraft");         // 1
        queue.offer("Slay the spire");    // 2
        queue.offer("balatro");           // 3
        queue.offer("arcaea");            // 4
        queue.offer("chrono ark");        // 5
        // System.out.println(Queue.empty());

        queue.poll();
        queue.poll();

        // Queue.poll; // poll out an obj(last in
        // Queue.poll;
        // Queue.poll;
        // ...

        // System.out.println(Queue.poll);
        // System.out.println(Queue.search("arcaea"));
        // System.out.println(Queue.search("Fallout76"));
        
        System.out.println(queue.peek());
        System.out.println(queue.contains("Minecraft"));

        // for(int i = 0; i < 1000000000; i++) {
        //     Queue.offer("Fallout76");
        // }

        //   uses:
        //   1.keyboard buffer
        //   2.Printer Queue
        //   3.Used in LinkedLists, PriorityQueue, Breadth-first search

    }
}


