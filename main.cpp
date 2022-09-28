#include <iostream>
#include <fstream>
#include <string>

#include "payload.cpp"
#include "payloadList.cpp"

using namespace std;
/*
void populateList(payloadList* list, int size){
    for (int i = 1; i < size*2; i+=2) {
        payload* p = new payload(i);
        list->push(p);
    }
}
*/
void printList(payloadList* head) {
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext()){
        cout << ptr->GetContent()->GetContent();
        if (ptr->hasNext()) cout << ", ";
    }
}


bool search(payloadList* head, int search){
    for (payloadList* ptr = head->GetHead(); ptr != NULL; ptr = ptr->GetNext()) {
        if (ptr->GetContent()->GetContent() == search) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    payloadList list;

    ifstream inFile;
    ofstream outFile;
    string command;

    inFile.open("test");
    outFile.open("out");

    inFile >> command;

    for (int count = 1; command != "Quit"; count++){
        //Commands

        //Build List
        if (command == "build") {
            int size;
            list = payloadList();
            inFile >> size;
            for (int i = 0; i < size; i++) {
                int num;
                inFile >> num;
                payload* p = new payload(num);
                list.push(p);
                outFile << "Pushing \"" << num << "\" to list" << endl;
            }
        }

        //Print list
        else if (command == "print") {
            printList(&list);
            for (payloadList* ptr = list.GetHead(); ptr != NULL; ptr = ptr->GetNext()) {
                cout << "Committing " << ptr->GetContent()->GetContent();
            }
            /*
            outFile << "Built List: [";
            for (payloadList* ptr = list.GetHead(); ptr != NULL; ptr = ptr->GetNext()) {
                cout << ptr->GetContent()->GetContent() << " ";
                outFile << ptr->GetContent()->GetContent();
                if (ptr->hasNext()) outFile << ", ";
            }
            outFile << "]";
            */
        }

        //Search for element in list
        else if (command == "search") {
            int srch;
            inFile >> srch;
            if (search(&list, srch)) outFile << "Search Successful, \"" << srch << "\" found" << endl;
            else outFile << "Search Unsuccessful, \"" << srch << "\" not found" << endl;
        }
        else outFile << "Command " << command << " does not exist" << endl;

        cout << "Test " << count << " Completed" << endl;
        inFile >> command;
    }
    
    cout << "All Tests Completed" << endl;

    inFile.close();
    outFile.close();

    return 0;
}
