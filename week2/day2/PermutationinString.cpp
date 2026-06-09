class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        // If s1 is longer than s2, it can't be a substring
        if (len1 > len2) return false;
        
        // Arrays to store character frequencies
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        // Populate frequencies for the first window
        for (int i = 0; i < len1; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        
        // Check if the very first window is a match
        if (s1_count == window_count) return true;
        
        // Slide the window through the rest of s2
        for (int i = len1; i < len2; i++) {
            // Add the new character on the right
            window_count[s2[i] - 'a']++;
            
            // Remove the old character from the left
            window_count[s2[i - len1] - 'a']--;
            
            // If the frequency arrays match, we found a permutation
            if (s1_count == window_count) return true;
        }
        
        return false;
    }
};
