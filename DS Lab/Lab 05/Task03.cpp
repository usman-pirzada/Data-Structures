#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printArray(int a[],int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int bubbleSort(int a[],int n){
    int c=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            c++;
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    return c;
}

int insertionSort(int a[],int n){
    int c=0;
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && (++c && a[j]>key)){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    return c;
}

int selectionSort(int a[],int n){
    int c=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            c++;
            if(a[j]<a[min]) min=j;
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    return c;
}

int shellSort(int a[],int n){
    int c=0;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=a[i];
            int j=i;
            while(j>=gap && (++c && a[j-gap]>temp)){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=temp;
        }
    }
    return c;
}

int main(){
    srand(time(0));
    int n1=20,n2=100;
    int arr1[20],arr2[100];
    for(int i=0;i<n1;i++) arr1[i]=rand()%100+1;
    for(int i=0;i<n2;i++) arr2[i]=rand()%100+1;

    cout<<"Array of 20 random numbers:"<<endl;
    printArray(arr1,n1);

    int b1[20],i1[20],s1[20],sh1[20];
    for(int i=0;i<n1;i++){b1[i]=arr1[i];i1[i]=arr1[i];s1[i]=arr1[i];sh1[i]=arr1[i];}
    cout<<"Bubble Sort:"<<endl;
    cout<<"Comparisons: "<<bubbleSort(b1,n1)<<endl;
    printArray(b1,n1);
    cout<<"Insertion Sort:"<<endl;
    cout<<"Comparisons: "<<insertionSort(i1,n1)<<endl;
    printArray(i1,n1);
    cout<<"Selection Sort:"<<endl;
    cout<<"Comparisons: "<<selectionSort(s1,n1)<<endl;
    printArray(s1,n1);
    cout<<"Shell Sort:"<<endl;
    cout<<"Comparisons: "<<shellSort(sh1,n1)<<endl;
    printArray(sh1,n1);

    cout<<endl<<"Array of 100 random numbers:"<<endl;
    printArray(arr2,n2);

    int b2[100],i2[100],s2[100],sh2[100];
    for(int i=0;i<n2;i++){b2[i]=arr2[i];i2[i]=arr2[i];s2[i]=arr2[i];sh2[i]=arr2[i];}
    cout<<"Bubble Sort:"<<endl;
    cout<<"Comparisons: "<<bubbleSort(b2,n2)<<endl;
    printArray(b2,n2);
    cout<<"Insertion Sort:"<<endl;
    cout<<"Comparisons: "<<insertionSort(i2,n2)<<endl;
    printArray(i2,n2);
    cout<<"Selection Sort:"<<endl;
    cout<<"Comparisons: "<<selectionSort(s2,n2)<<endl;
    printArray(s2,n2);
    cout<<"Shell Sort:"<<endl;
    cout<<"Comparisons: "<<shellSort(sh2,n2)<<endl;
    printArray(sh2,n2);

    return 0;
}
