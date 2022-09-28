#include <iostream>
#include <fstream>

#include "payload.cpp"
#include "payloadList.cpp"

using namespace std;

void readList(payloadList* head) {
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext())
        cout << ptr->GetContent()->GetContent() << ": " << ptr->GetNext() << ": " << ptr->GetHead() << endl;
};

void populateList(payloadList* list, int size){
    for (int i = 0; i < size; i++) {
        payload* p = new payload(i);
        if (i == 0) list->SetContents(p);
        else list->push(p);
    }
};

int main(int argc, char const *argv[])
{
    const int size = 10;
    payloadList list;

    populateList(&list, size);
    readList(&list);

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
