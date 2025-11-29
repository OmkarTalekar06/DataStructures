#include<iostream>
using namespace std;

int main(){
    int arr[100],n, i, pos;

    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter " << n << " elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Array before insertion : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    cout<<"Enter position to delete : ";
    cin>>pos;

    for (int i = pos-1; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
    

    cout<<"Array after  deletion : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}