class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        while(low<=high){
            long long mid=(low+high)/2;
            long long val=mid*mid;
            if(val<x){
                low=mid+1;
            }
            else if(val==x){
                return mid;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};