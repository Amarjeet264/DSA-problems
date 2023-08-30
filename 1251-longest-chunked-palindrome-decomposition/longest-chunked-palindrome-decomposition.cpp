class Solution {
public:
    int longestDecomposition(string text) {
        // "ghiabcdefhelloadamhelloabcdefghi"
        int n=text.size();
        int i=0;
        int j=n-1;
        int half=n/2;
        int last=n;
        int cnt=0;
        while(i<=j&&j>=half){
            if(i==j){
                cnt++;
                break;
            }
            if(text[i]==text[j]){
                int x=i;
                int y=j;
                while(y<last){
                    if(text[x]!=text[y]){
                        break;
                    }
                    x++;
                    y++;
                }
                if(y>=last){
                    cnt+=2;
                    last=j;
                    i=x;
                }
            }
            j--;
        }
        if(i<half&&j<half){
            return cnt+1;
        }
        if(j<half&&i>=half)return cnt;
        return cnt;
    }
};