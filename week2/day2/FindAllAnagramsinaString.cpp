class Solution {
public:
    vector<int> findAnagrams(std::string s, std::string p) {
        vector<int> result;
        int len_s = s.length();
        int len_p = p.length();
        
        // If p is longer than s, it can't be a substring
        if (len_p > len_s) return result;
        
        // Arrays to store character frequencies
        vector<int> p_count(26, 0);
        vector<int> window_count(26, 0);
        
        // Populate frequencies for the first window
        for (int i = 0; i < len_p; i++) {
            p_count[p[i] - 'a']++;
            window_count[s[i] - 'a']++;
        }
        
        // Check if the very first window is a match
        if (p_count == window_count) {
            result.push_back(0);
        }
        
        // Slide the window through the rest of s
        for (int i = len_p; i < len_s; i++) {
            // Add the new character on the right
            window_count[s[i] - 'a']++;
            
            // Remove the old character from the left
            window_count[s[i - len_p] - 'a']--;
            
            // If the frequency arrays match, record the start index of the window
            if (p_count == window_count) {
                result.push_back(i - len_p + 1);
            }
        }
        
        return result;
    }
};
