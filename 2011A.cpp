#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int n){
    unordered_set<int>us; //unordered_set has insertion time complexity of O(1). Insertion isn't a costly operation here
    for(int i=0;i<=sqrt(n);i++){
        
        long long int square=i*i;
        long long int diff=n-square;
        long long int sqrtDiff=sqrt(diff);
        if(sqrtDiff*sqrtDiff==diff){
                us.insert(i+sqrtDiff);
        }
    }
    return us.size();
    
}
int main() {
    
    int t,i=1;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        cout<<"Case #"<<i<<": "<<solve(n)<<endl;
        i++;
    }
    
    return 0;
}
