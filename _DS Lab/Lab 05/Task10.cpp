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
    int l=0,r=n-1,mid;
    bool found=false;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==x){
            found=true;
            break;
        }
        else if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    if(found) cout<<"Found";
    else cout<<"Not Found";
    return 0;
}
