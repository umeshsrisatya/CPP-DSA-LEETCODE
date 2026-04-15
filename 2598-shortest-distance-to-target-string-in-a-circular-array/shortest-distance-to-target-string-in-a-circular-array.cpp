class Solution {
public:
    int closestTarget(vector<string>& word, string target, int startIndex) {
        if(word[startIndex] == target){
            return 0;
        }
        int currentIndex = startIndex;
        int mini = INT_MAX;
        int n = word.size();
        bool flag = true;
        //right direction
        for(int i = 1; i < n; i++){
            currentIndex = ((startIndex+i)%n);
            if(word[currentIndex] == target){
                flag = false;
                mini = min(mini, i);
                break;
            }
        }

        //left direction
        for(int i = 1; i < n; i++){
            currentIndex = ((startIndex-i+n)%n);
            if(word[currentIndex] == target){

                mini = min(mini, i);
                break;
            }
        }
        if(flag == true)return -1;
        return mini;
    }
};