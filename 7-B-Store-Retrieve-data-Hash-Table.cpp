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

bool search(int key){
    int index = hashFunction(key);
    for (int item : table[index]){
        if (item==key)
        {
            return true;
        }
    }
     return false;
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
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    ht.display();
    
    int key;
    cout<<"\nEnter key to search : ";
    cin>>key;
    if (ht.search(key))
    {
        cout<<key<<" found in hash table";
    }else{
        cout<<key<<" not found in Hash Table";
    }

}