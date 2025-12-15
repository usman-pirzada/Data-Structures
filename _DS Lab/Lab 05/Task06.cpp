#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i;
            while(j>=gap && a[j-gap]>temp){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=temp;
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
