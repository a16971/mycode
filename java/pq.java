import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;


public class pq{
	
	public static void main(String[] args){

		Map<Integer, 
		Queue<Integer> intPQ = new PriorityQueue<Integer>(7);

		Random rand = new Random();

		for(int i = 0; i < 7; i++){
			intPQ.add(new Integer(rand.nextInt(100)));
		}
		for(int i = 0; i < 7; i++) { 
			Integer in = intPQ.poll();
			System.out.println("Porcessing Integer: " + in);
		}
	}
}	
