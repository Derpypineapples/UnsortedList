#include <iostream>
#include <fstream>

#include "payload.cpp"
#include "payloadList.cpp"

using namespace std;

void readList(payloadList* head) {
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext()){
        cout << ptr->GetContent()->GetContent() << ": " << ptr->GetNext() << ": " << ptr->GetHead() << endl;
    }
}

void populateList(payloadList* list, int size){
    for (int i = 1; i < size*2; i+=2) {
        payload* p = new payload(i);
        list->push(p);
    }
}

bool search(int search){
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext())
        if (ptr->GetContent()->GetContent() == search) return true;
    return false;
}

int main(int argc, char const *argv[])
{
    const int size = 10;
    payloadList list;

    populateList(&list, size);
    readList(&list);

    cout << "bruh2" << endl;
    cout << search(2) << " : " << search(3) << endl;

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
