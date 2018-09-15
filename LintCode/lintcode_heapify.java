/*
*
* Tag: Data Structure (Heap)
* Time: O(n)
* Space: O(1)
*/
public class Solution {
    /**
     * @param A: Given an integer array
     * @return: void
     */
    public void heapify(int[] A) {
        int start = A.length/2;
        for (int i=start;i>=0;i--)
            shiftDown(i, A);
    }
    
    private void shiftDown(int ind, int[] A){
        int size = A.length;
        int left = ind*2+1;
        int right = ind*2+2;
        while (left<size || right<size){
            int leftVal = (left<size) ? A[left] : Integer.MAX_VALUE;
            int rightVal = (right<size) ? A[right] : Integer.MAX_VALUE;
            int next = (leftVal<=rightVal) ? left : right;
            if (A[ind]<A[next]) break;
            else {
                swap(A, ind,next);
                ind = next;
                left = ind*2+1;
                right = ind*2+2;
            }
        }
    }
    
    private void swap(int[] A, int x, int y){
        int temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }
}
