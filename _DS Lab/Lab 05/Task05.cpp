#include <iostream>
using namespace std;
int main() {
    int myarr[] = {9,5,1,4,3,14,119};
    int n = sizeof(myarr)/sizeof(myarr[0]);
    for(int i=1;i<n;i++){
        int key=myarr[i];
        int j=i-1;
        while(j>=0 && myarr[j]>key){
            myarr[j+1]=myarr[j];
            j--;
        }
        myarr[j+1]=key;
    }
    for(int i=0;i<n;i++) cout<<myarr[i]<<" ";
    return 0;
}
