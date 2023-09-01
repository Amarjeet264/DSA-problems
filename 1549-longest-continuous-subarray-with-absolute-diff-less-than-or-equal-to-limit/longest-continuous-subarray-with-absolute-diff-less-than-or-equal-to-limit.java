class Solution {
    public int longestSubarray(int[] nums, int limit) {
        PriorityQueue<Integer> min=new PriorityQueue<Integer>();
        PriorityQueue<Integer> max=new PriorityQueue<Integer>(Collections.reverseOrder());
        int n=nums.length;
        int i=0;
        int j=0;
        int len=0;
        while(j<n){
            min.add(nums[j]);
            max.add(nums[j]);
            while(i<j && max.peek()-min.peek()>limit){
                min.remove(nums[i]);
                max.remove(nums[i]);
                i++;
                // System.out.println(max.peek()-min.peek());
            }
            j++;
            len=Math.max(len,j-i);
            // break;
        }
        return len;
    }
}