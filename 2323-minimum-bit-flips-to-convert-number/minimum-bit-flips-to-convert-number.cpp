class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long int count=0;
        while(goal||start){
            int bitst=0;
            // if(start){
                bitst=start%2;
            // }
            int bitg=0;
            // if(goal){
                bitg=goal%2;
            // }
            if(bitst!=bitg){
                count++;
            }
           start= start/2;
           goal= goal/2;
        }
        return count;
    }
};