#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Array to store the last seen index of each ASCII character
        std::vector<int> last_seen(128, -1);
        
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            // If the character is in the current window, move the left pointer
            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }
            
            // Update the last seen index of the current character
            last_seen[current_char] = right;
            
            // Update the maximum length found so far
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

