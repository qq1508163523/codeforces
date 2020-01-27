
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
#define MAXN 400005
 
using namespace std;
int t,n;
int arr[MAXN];
int nums[MAXN];
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&t);
 
   while(t--){
      scanf("%d",&n);
      memset(nums,0,sizeof(nums));     
      int tmp,curr = 1;
      scanf("%d",&tmp);
      nums[curr]++;
      for(int i = 1;i < n;i++){
          scanf("%d",&arr[i]);
          if(tmp != arr[i] && i < n/2){
             tmp = arr[i];
             curr++;
             nums[curr] = 1;
          }else if(i < n/2){
             nums[curr]++;
          }
      }
      if(n < 10 || curr < 3){
          printf("0 0 0\n");
          continue;
      }
 
      if((n/2 - nums[1])/2 <= nums[1]){
          printf("0 0 0\n");
          continue;
      }
 
      int silver = 0;
      for(int j = 2;j <= curr;j++){
          silver += nums[j];
          if(silver > nums[1]){
              break;
          }
      }
 
      if(n/2 - silver <= 2 * nums[1]){
          printf("0 0 0\n");
          continue;
      }
 
      if(arr[n/2] == arr[n/2 - 1]){
          if(n/2 - silver - nums[curr] <= 2 * nums[1]){
              printf("0 0 0\n");
          }else{
              printf("%d %d %d\n",nums[1],silver,n/2 - silver - nums[1] - nums[curr]);
          }
      }else{
          printf("%d %d %d\n",nums[1],silver,n/2 - silver - nums[1]);
      }
 
   }
   
   return 0;
}