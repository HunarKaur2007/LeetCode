class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.size() != goal.size())
            return false;
        int n = s.size();
        for(int i = 0; i < n; i++) {
             char first = s[0];
            // Shift all characters one position to the left
            for(int j = 0; j < n - 1; j++) {
                s[j] = s[j + 1];
            }
            // Put the first character at the end
            s[n - 1] = first;
            if(s == goal)
                return true;
        }
        return false;
    }
};