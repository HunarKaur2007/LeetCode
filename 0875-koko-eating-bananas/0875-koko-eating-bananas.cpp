class Solution {
public:
    bool caneat(vector<int>&piles, int h, int speed){
        long long hours =0;
        for(int p:piles){
            hours+=(p+speed-1)/speed;
            if(hours>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= *max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid =low+(high-low)/2;
            if(caneat(piles,h,mid)) high =mid -1;
            else low = mid+1;
        }
        return low;
    }
};