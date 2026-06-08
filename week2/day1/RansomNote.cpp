class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26]={0};
        if(magazine.size()<ransomNote.size()){
            return false;
        }
        for(int j=0;j<magazine.size();j++){
            hash[magazine[j]-97]++; 
        }
        for(int j=0;j<ransomNote.size();j++){
            hash[ransomNote[j]-97]--; 
           if(hash[ransomNote[j]-97]<0){
            return false;
           }                                   
        }
        return true;
    }
};
