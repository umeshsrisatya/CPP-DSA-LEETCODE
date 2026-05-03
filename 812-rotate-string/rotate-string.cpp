class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.size()!= g.size()) return false;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s == g){
                return true;
            }
            char lastChar = s.back();

            // 2. Remove the last character
            s.pop_back();

            // 3. Insert it at the front (position 0)
            s.insert(0, 1, lastChar);
        }
        return false;
    }
};