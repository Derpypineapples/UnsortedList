#include <iostream>
#include <fstream>

#include "payload.cpp"
#include "payloadList.cpp"

using namespace std;

void populateList(payloadList* list, int size){
    for (int i = 1; i < size*2; i+=2) {
        payload* p = new payload(i);
        list->push(p);
    }
}

void readList(payloadList* head) {
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext()){
        cout << ptr->GetContent()->GetContent() << ": " << ptr->GetNext() << ": " << ptr->GetHead() << endl;
    }
}

bool search(payloadList* head, int search){
    cout << "Searching: " << search << endl;
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext()) {
        if (ptr->GetContent()->GetContent() == search){
            cout << "Search Successful" << endl;
            return true;
        }
    }
    cout << "Search Unsuccessful" << endl;
    return false;
}

int main(int argc, char const *argv[])
{
    const int size = 10;
    payloadList list;

    populateList(&list, size);
    readList(&list);
    cout << search(&list, 3) << endl;

    /*
    ifstream inFile;
    ofstream outFile;
    string command;

    inFile.open("test");
    outFile.open("out");

    inFile.close();
    outFile.close();
    */

    return 0;
}
