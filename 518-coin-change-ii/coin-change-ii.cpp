class Solution {
public:
int f(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
    if(ind==0){
        return (amount%coins[0]==0);
    }
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int nottake=f(ind-1,amount,coins,dp);
    int take=0;
    if(coins[ind]<=amount) take=f(ind,amount-coins[ind],coins,dp);
    return dp[ind][amount]=nottake+take;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n-1,amount,coins,dp);
    }
};