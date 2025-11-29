#include<iostream>
using namespace std;
 int main(){
    int arr[100];
    int n,i,pos,value;

    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter "<<n<<" elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the position to insert : ";
    cin>>pos;
    cout<<"Enter value to insert : ";
    cin>>value;

    for ( i = n; i > pos; i--)
    {
        arr[i] = arr[i-1];
    }
    
    arr[pos] = value;
    n++;

    cout<<"Array after insertion : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] << "  ";
    }
    
 }