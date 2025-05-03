// Consider a scenario for Hospital to cater services to different kinds of patients as Serious
// (top priority), b) non-serious (medium priority), c) General Checkup (Least priority).
// Implement the priority queue to cater services to the patients

// Prioirty Queue

#include <bits/stdc++.h>
using namespace std;

struct Patient{
    string name;
    int priority;
    // 1: Serious, 2: Non-serious, 3: General checkup
};

class priorityQueue
{
    public:
        Patient arr[100];
        int size;

        priorityQueue(){
            size = 0;
        }
};

void addPatient(priorityQueue &pq){
    if(pq.size >= 100){
        cout << "Queue is full" << endl;
        return;
    }

    Patient p;
    cout << "Enter patient name : ";
    getline(cin, p.name);
    cout << "Enter priority (1 = Serious, 2 = Non-serious, 3 = General Checkup): ";
    cin >> p.priority;

    int i = pq.size - 1;
    while(i>=0 && pq.arr[i].priority > p.priority){
        pq.arr[i+1] = pq.arr[i];
        i--;
    }
    i++;
    pq.arr[i] = p;
    pq.size++;
}

void removePatient(priorityQueue &pq){
    if(pq.size == 0){
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Removed patient : " << pq.arr[0].name << " with priority " << pq.arr[0].priority << endl;

    for(int i=0; i<pq.size-1; i++){
        pq.arr[i] = pq.arr[i+1];
    }
    pq.size--;
}

void displayQueue(priorityQueue &pq){
    if(pq.size == 0){
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Patient details: " <<endl;
    cout << setw(20) << left << "Patient name"  << setw(15) << left << "Priority" << endl;
    for(int i=0; i<pq.size; i++){
        int priority = pq.arr[i].priority;
        string prior;
        if(priority == 1) prior = "Serious"; else if(priority = 2) prior = "Non-serious"; else prior = "General Checkup";
        cout << setw(20) << left << pq.arr[i].name  << setw(15) << left << prior << endl;
    }
}

int main()
{
    priorityQueue pq;
    int choice;

    do
    {
        cout << "\n--- Hospital Priority Queue Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Remove Patient (Serve)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addPatient(pq);
            break;
        case 2:
            removePatient(pq);
            break;
        case 3:
            displayQueue(pq);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}