/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(1)
*/
public class RandomizedSet {

    private Map<Integer,Integer> dict;
    private int[] arr;
    private int tot;
    private Random rnd;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        dict = new HashMap<Integer,Integer>();
        arr = new int[111000];
        tot = 0;
        rnd = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(dict.containsKey(val) == true)
            return false;
        arr[++ tot] = val;
        dict.put(val, tot);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(dict.containsKey(val) == false)
            return false;
        int idx = dict.get(val).intValue();
        dict.put(arr[tot], idx);
        dict.remove(val);
        arr[idx] = arr[tot];
        -- tot;
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return arr[rnd.nextInt(tot) + 1];
    }
}
