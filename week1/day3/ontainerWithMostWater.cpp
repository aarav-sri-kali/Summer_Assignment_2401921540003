class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int area;
        int maxH=0;
        while(i<j){
            int w=j-i;
            int H=min(height[i],height[j]);
            area=w*H;
            maxH=max(maxH,area);
            height[i]>height[j]?j--:i++;
        }
        return maxH;
    }
};
