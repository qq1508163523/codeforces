#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
//#define LOCAL 
#define MAXN 200005
 
using namespace std;
int arr[MAXN],dp[MAXN],n;
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&n);
   memset(dp,-1,sizeof(dp));
   dp[0] = 1;
   scanf("%d",&arr[0]);
   for(int i = 1;i < n;i++){
       scanf("%d",&arr[i]);
       if(arr[i] > arr[i - 1]) dp[i] = dp[i - 1] + 1;
       else dp[i] = 1; 
   }
 
   int ans = -1;
   for(int i = 1;i < n - 1;i++){
        if((arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) || (arr[i] <= arr[i - 1] && arr[i] <= arr[i + 1])){
            if(arr[i - 1] < arr[i + 1]){
                int j = i + 2;
                while(j < n && dp[j] != 1) j++;
                ans = max(ans,dp[i - 1] + j - i - 1);             
            }
        }
   }
   
   for(int i = 0;i < n;i++) ans = max(ans,dp[i]);
 
   printf("%d",ans == -1?n:ans);
   return 0;
}