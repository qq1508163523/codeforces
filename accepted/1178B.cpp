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
//#define LOCAL
#define MAXN 1000005
 
using namespace std;
 
typedef long long int ll;
char str[MAXN];
ll factors = 0;
ll ans = 0;
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   cin >> str;
   
   int n = strlen(str);
   
   for(int i = 0;i < n;i++){
	  if(str[i] == 'v'){
         int j = i + 1;
		 while(j < n && str[j] == 'v') j++;
		 factors += j - i - 1;
		 i = j;
      }	  
   }
   
   //cout << factors << endl;
   ll curr = 0;
   for(int i = 0;i < n;){
	   if(str[i] == 'o'){
		   ans += curr * (factors - curr);
		   i++;
	   }else{
		   int j = i + 1;
		   int len = 1;
		   while(j < n && str[j] == 'v') j++;
		   curr += j - i - 1;
		   i = j;
	   }
   }
   
   cout << ans;
   
   return 0;
}