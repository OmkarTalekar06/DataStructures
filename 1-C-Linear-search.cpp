#include<iostream>
using namespace std;

int main(){

    int arr[100], n, i, val, found = 0;

    cout<<"Enter the size of Array : ";
    cin>>n;

    cout<<"Enter "<<n<<" number of elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter value to search : ";
    cin>>val;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == val){
            found = 1;
            cout<<"Element found at position : "<<i + 1<<endl;
            break;
        }
    }
    if (!found)
    {
        cout<<"Element not found !"<<endl;
    }

    return 0;
    
    
}