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
#define MAXN 105000
#define ll long long int
 
using namespace std;
int t;
int nums[MAXN];
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&t);
   for(int i = 1;i < MAXN;i++) nums[i] = nums[i - 1] + i;
 
   while(t--){
       int a,b;
       scanf("%d%d",&a,&b);
       for(int i = 0;i < MAXN;i++){
           if((nums[i] + a + b) % 2 == 0 && (nums[i] + a + b) / 2 >= max(a,b)){
               printf("%d\n",i);
               break;
           }
       }
   }
   
   return 0;
}