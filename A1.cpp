// Consider telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find a set of
// telephone numbers

#include <bits/stdc++.h>
using namespace std;

void linearProbing(string arr[][2], int n, string name, int tele){
    int hashkey = tele % n;
    int i = 0;

    while (arr[hashkey][0] != "" && i < n){
        i++;
        hashkey = (hashkey + 1) % n;
    }

    if (i == n){
        cout << "Database is full, cannot add\n";
        return;
    }

    arr[hashkey][0] = name;
    arr[hashkey][1] = to_string(tele);
    cout << "Client entry added, no of comparisons required: " << i << endl;
}

void doubleHashing(string arr[][2], int n, string name, int tele){
    int primaryHashkey = tele % n;
    int secondaryHashkey = 7 - (tele % 7);
    int i = 0;

    int newhashkey = primaryHashkey;

    while (arr[newhashkey][0] != ""){
        newhashkey = (primaryHashkey + (i * secondaryHashkey)) % n;
        i++;
    }

    if (i == n){
        cout << "Database is full, cannot add\n";
        return;
    }

    arr[newhashkey][0] = name;
    arr[newhashkey][1] = to_string(tele);
    cout << "Client entry added, no of comparisons required: " << i << endl;
}

void addToHash(string arr[][2], int n){
    int tele;
    string name;
    cout << "Enter client name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter client telephone number: ";
    cin >> tele;

    int hashkey = tele % n;

    if (arr[hashkey][0] == ""){
        arr[hashkey][0] = name;
        arr[hashkey][1] = to_string(tele);
        cout << "Client entry added, no of comparisons required: 0" << endl;
    } else {
        int method;
        cout << "Collision occurred!\nSelect collision handling method:\n1. Linear Probing\n2. Double Hashing\n";
        cin >> method;

        if (method == 1)
            linearProbing(arr, n, name, tele);
        else if (method == 2)
            doubleHashing(arr, n, name, tele);
        else
            cout << "Invalid method, phone number not added\n";
    }
}

void searchHash(string arr[][2], int n){
    cout << "Enter the number to search: ";
    int searchnum;
    cin >> searchnum;

    int hashkey = searchnum % n;
    int comparisons = 0;

    while (arr[hashkey][1] != ""){
        comparisons++;

        if (stoi(arr[hashkey][1]) == searchnum){
            cout << "Number found, belongs to " << arr[hashkey][0] << endl;
            cout << "Number of comparisons required: " << comparisons << endl;
            return;
        }

        hashkey = (hashkey + 1) % n;
    }

    cout << "Number not found" << endl;
}

int main(){
    int n;
    cout << "Enter total number of clients: ";
    cin >> n;

    string arr[n][2];
    int choice;

    do {
        cout << "\n-------------------MENU-----------------\n";
        cout << "1. Add phone number\n";
        cout << "2. Search phone number\n";
        cout << "3. Display database\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                addToHash(arr, n);
                break;

            case 2:
                searchHash(arr, n);
                break;

            case 3:
                cout << "\n-------- Telephone Book --------\n";
                cout << left << setw(10) << "Index"
                     << setw(20) << "Name"
                     << setw(15) << "Phone" << endl;

                for (int i = 0; i < n; ++i){
                    if (arr[i][0] != ""){
                        cout << setw(10) << i
                             << setw(20) << arr[i][0]
                             << setw(15) << arr[i][1] << endl;
                    }
                }
                cout << "-------------------------------\n";
                break;

            case 4:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice, try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
