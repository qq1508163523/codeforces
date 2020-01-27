#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>
//#define LOCAL
#define MAXN 105
#define ull unsigned long long int
 
using namespace std;
 
ull powers[40];
bool checker[40];
int t;
ull n;
 
 
ull solve(){
   int largest = log(n)/log(3);
   ull t = n;
   for(int i = largest;i >= 0;i--){
       if(powers[i] <= t){
		   t -= powers[i];
           checker[i] = 1;
           if(t == 0) return n;		   
	   }
   }
 
   ull sum = 0;
   for(int i = 0;i <= largest;i++){
	   if(checker[i] == 0){
           ull ans = powers[i];
		   for(int j = i + 1;j <= largest;j++){
			   if(checker[j] == 1) ans += powers[j];
		   }
		   return ans;
       }	   
   }
   
   return powers[largest + 1];
}
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
 
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> t;
   for(int i = 0;i < 40;i++) powers[i] = pow(3,i);
   while(t--){
	   memset(checker,0,sizeof(checker));
	   cin >> n;
       cout << solve() << endl;
	  /*int largest = log(n)/log(3);
	  ull t = n;
	  for(int i = largest;i >= 0;i--){
        if(powers[i] <= t){
		   t -= powers[i];
           checker[i] = 1;
           cout << i << " ";		   
	    }
      }
	  cout << endl;*/
	  
   }
   
   return 0;
}