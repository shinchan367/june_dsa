class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        int n=fruits.size();
        
        for(int i=0;i<n;i++){
            int unset=1;
            for(int j=0;j<baskets.size();j++){
            if(fruits[i]<=baskets[j]){
             baskets[j]=0;
             unset=0;
              break;
            }
            }
        count+=unset;
        }
        return count;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced=0;
        int n=fruits.size();
        vector<int>basket=baskets;
        for(int i=0;i<n;i++){
            for(int j=0;j<basket.size();j++){
            if(fruits[i]<=basket[j]){
             basket.erase(basket.begin()+j);
              break;
            }
            }

        }
        return basket.size();
    }
};
