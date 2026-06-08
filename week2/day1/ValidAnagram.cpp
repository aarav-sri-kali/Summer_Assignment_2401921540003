class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26]={0};
        int i=0;
        if(s.size()!=t.size()){
            return false;
        }
        else{
            while(i<s.size()){
                hash[s[i]-97]++;                
                hash[t[i]-97]--;                
                i++;
            }
            for(int j=0;j<26;j++){
                if(hash[j]!=0){
                    return false;
                }
            }
            return true;
        }
    }
};
