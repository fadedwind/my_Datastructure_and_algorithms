package Stack;
import java.util.Stack;

public class D01_stack{
    public static void main(String[] args) {

        Stack<String> stack = new Stack<String>();

        // stack: LIFO(last in first out)

        // push() to add to the top
        // pop() to remove from the top
        // peak() examine the top element and return

                                              // position
        stack.push("Minecraft");         // 5
        stack.push("Slay the spire");    // 4
        stack.push("balatro");           // 3
        stack.push("arcaea");            // 2
        stack.push("chrono ark");        // 1
        // System.out.println(stack.empty());

        stack.pop();

        // stack.pop(); // pop out an obj(last in
        // stack.pop();
        // stack.pop();
        // ...

        // System.out.println(stack.pop());
        // System.out.println(stack.search("arcaea"));
        // System.out.println(stack.search("Fallout76"));
        
        System.out.println(stack.peek());
        System.out.println(stack);

        // for(int i = 0; i < 1000000000; i++) {
        //     stack.push("Fallout76");
        // }

        //   uses:
        //   1.undo/redo features in text editors
        //   2.moving back forward through browser history
        //   3.backtracking algorithms
        //   4.calling functions

    }
}

