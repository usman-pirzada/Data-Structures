#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int x;
    cin>>x;
    int l=0,r=n-1,pos;
    bool found=false;
    while(l<=r && x>=a[l] && x<=a[r]){
        if(l==r){
            if(a[l]==x) found=true;
            break;
        }
        pos=l+((double)(r-l)/(a[r]-a[l]))*(x-a[l]);
        if(a[pos]==x){
            found=true;
            break;
        }
        if(a[pos]<x) l=pos+1;
        else r=pos-1;
    }
    if(found) cout<<"Found";
    else cout<<"Not Found";
    return 0;
}
