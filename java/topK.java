import java.util.*;

public class topK {
    public static List<Integer> topKFrequent(int[] nums, int k) {

	class Tuple {
	    
	    public Integer key;
	    public Integer value; 
	    
	    public Tuple(Integer k, Integer v){
		this.key = k; 
		this.value = v;
	    }
	}
        List<Integer> ret = new ArrayList<Integer>();
	Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
	
	for (int i = 0; i < nums.length; ++i) {
	    if(!hashMap.containsKey(nums[i])) {
		hashMap.put(nums[i], 1);
	    }else{
                Integer v = hashMap.get(nums[i]);
                System.out.println("key: " + nums[i] + " value: " + v);
                hashMap.put(nums[i], v+1);
	    }
        }

	Iterator<Integer> keySetIterator = hashMap.keySet().iterator();
	PriorityQueue<Tuple> pQueue = new PriorityQueue<Tuple>(hashMap.size(), (a,b) -> (b.value - a.value));

	while(keySetIterator.hasNext()){
	    Integer key = keySetIterator.next();
	    Tuple tuple = new Tuple(key, hashMap.get(key));
	    pQueue.add(tuple);
	}

        System.out.print("top" + k + " frequent elements in array {");

        for( int n = 0; n < nums.length; ++n)
            System.out.print(nums[n] + ", " );
        System.out.println("}");

	for(int j = 0; j < k; ++j) {
            Tuple tuple =  pQueue.poll();
            ret.add(tuple.key);
            System.out.println(tuple.key + ": " + tuple.value);
        }        
        
        return ret;

    }
    
    public static void main(String[] args){
        Random rand = new Random();
        int[] array = new int[100];


        for(int i = 0; i < 100; ++i)
            array[i] = rand.nextInt(10); 

        topKFrequent(array, 10);
    
    }
}
