#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index])
            min_index=j;
        }
        swap(arr[min_index],arr[i]);
    }

}
 
 int main(){
    int i,j,n;
    cout<<"Enter The Size Of The Array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the Element Of the Array"<<endl;
    for(i=0;i<n;i++){
        cout<<i+1<<" "<<"element"<<endl;
        cin>>arr[i];
    }
    cout<<"Ater Enter All Element the Array is:"<<endl;
    for(i=0;i<n;i++){
        cout<<'\t'<<arr[i];
    }
    //Now I am going to apply Selection Sort ;
    
    //after Appling Selectionn Sort The Sorting Array :
    cout<<endl<<"After Apling Selection Sort The Array Is: "<<endl;
selectionsort(arr,n);
    for(i=0;i<n;i++){
        cout<<'\t'<<arr[i];
    }

    return 0;
 }
