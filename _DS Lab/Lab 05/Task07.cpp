#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    int gap=n;
    bool swapped=true;
    while(gap>1 || swapped){
        gap=(gap*10)/13;
        if(gap<1) gap=1;
        swapped=false;
        for(int i=0;i+gap<n;i++){
            if(a[i]>a[i+gap]){
                int t=a[i];
                a[i]=a[i+gap];
                a[i+gap]=t;
                swapped=true;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
