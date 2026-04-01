//----------Length of Longest Substring Without Repeating Characters------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int left=0;
     int right=0;
     int maxlen=0;
     int vis[256]={0};

    while(right<s.length()){
        while(vis[s[right]]==1){
            vis[s[left]]=0;
            left++;
        }
       
        vis[s[right]]=1;
        maxlen=max(maxlen,right-left+1);

        right++;
    }

    return maxlen;
    }
};