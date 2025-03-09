class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<colors.size();i++){
            if(colors[i]!=colors[(i+1)%n] && colors[i]==colors[(i+2)%n]){
                ans++;
            }
        }
        return ans;
    }
};