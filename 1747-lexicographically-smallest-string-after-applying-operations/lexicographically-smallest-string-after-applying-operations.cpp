class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string>st;
        queue<string>q;
        q.push(s);
        st.insert(s);
        string mini=s;
        while(!q.empty()){
            string fr=q.front();
            mini=min(mini,fr);
            q.pop();
            string ad=fr;
            // cout<<fr<<"ll ";
            for(int i=1;i<ad.size();i+=2){
                int x=ad[i]-'0';
                x=(x+a)%10;
                ad[i]=x+'0';
            }
            if(st.find(ad)==st.end()){
                // cout<<ad<<" ";
                st.insert(ad);
                q.push(ad);
            }
            string first=fr.substr(0,fr.length()-b);
            string last=fr.substr(fr.length()-b,fr.length());
            if(st.find(last+first)==st.end()){
                st.insert(last+first);
                q.push(last+first);
                // cout<<last+first<<" ";
            }
        }
        return mini;
    }
};