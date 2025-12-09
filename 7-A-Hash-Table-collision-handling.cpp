#include<iostream>
#include<list>
using namespace std;

class HashTable{
    static const int size = 10;
    list<int> table[size];

public:

int hashFunction(int key){
    return key % size;
}

void insert(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}

void display(){
    for (int i = 0; i < size; i++)
    {
        cout<<i<<"-->";
        for (int key : table[i])
        {
            cout<<key<<"-->";
        }
        cout<<"NULL\n";
    }
}
};

int main(){

    HashTable Ht;
    int arr[] = {10, 20, 15, 25, 35, 5};

    for(int key : arr){
        Ht.insert(key);
    }

    cout<<" Hash Table (seprate chaining): \n";
    Ht.display();

    return 0;
}