//https://leetcode.com/problems/boats-to-save-people/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int minBoat = 0;
        int startPos = 0;
        int endPos = (int)people.size()-1;
        
        sort(people.begin(), people.end());
        
        while(startPos<=endPos){
            if(people[startPos] + people[endPos] <= limit){
                endPos--;
                startPos++;
                minBoat++;
            }
            else{
                endPos--;
                minBoat++;
            }
        }
        return minBoat;
    }
};
