#include<bits/stdc++.h>
using namespace std; 

int main(void){
    freopen("derivation.txt", "r", stdin);
    int n;
    cin>>n;

    double x0, x1, x2, f0, f1, f2;
    cin>>x0>>f0;
    cin>>x1>>f1;
    
    // first point
    cout<<(f1-f0)/(x1-x0)<<endl;

    for(int i=3; i<=n; i++){
        cin>>x2>>f2;
        cout<<(f2-f0)/(x2-x0)<<endl;
        swap(x0,x1);
        swap(f0,f1);
        swap(x1,x2);
        swap(f1,f2);
    }
    
    // last point
    cout<<(f1-f0)/(x1-x0)<<endl;

    return 0;
}