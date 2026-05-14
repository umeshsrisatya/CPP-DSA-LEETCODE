class Solution {
public:
    bool isAnagram(string s, string t) {//good thought process im taking a nap txt me in ws // ok
        map<char, int> mpp;
        if(s.size() != t.size()){
            return false;
        }
        for(char i:s){
            mpp[i]++;
        }
        for(char i : t){
            if(mpp.find(i)!=mpp.end()){
                mpp[i]--;//hey fucker this approach will make the map element second to 0// that's why i asked u is this correct //this is ok. change the code
            }
        } 
        bool flag = true;
        for(auto i : mpp){
            if(i.second >0) flag = false;
        }
        if(flag == true )return true;
        return false;        // solve this test case my fucking lady
        //osey rondu size veru vunnai ey bujji s &t
    }
};