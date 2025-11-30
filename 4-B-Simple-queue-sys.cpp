#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> ServiceQueue;
    int choice;
    string name;
    cout << "...........Welcome...........\n";

    do
    {
        cout << "\n1.Add customer.\n2.Serve customer.\n3.Display queue.\n4.Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter customer name : ";
            cin >> name;
            ServiceQueue.push(name);
            cout << name << " added to Queue..\n";
            break;

        case 2:
            if (ServiceQueue.empty())
            {
                cout << "No customers to serve !" << endl;
            }
            else
            {
                cout << ServiceQueue.front() << " is being served\n";
                ServiceQueue.pop();
            }
            break;
        case 3:
        {
            cout << "Queue : ";
            if (ServiceQueue.empty())
            {
                cout << " (empty)\n";
            }
            else
            {
                queue<string> temp = ServiceQueue; // copy the queue
                while (!temp.empty())
                {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << "\n";
            }
            break;
        }
        case 4:
            cout<<"Exiting....";
            return 0;

        default:
            cout<<"Invalid choice";
            break;
        }
    } while (choice < 5);
}