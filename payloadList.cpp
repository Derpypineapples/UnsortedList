#include "payloadList.h"

payloadList::payloadList() {
    head = this;
    ptr = nullptr;
    next = nullptr;
    newElement = nullptr;
}

payloadList::~payloadList() {
    delete ptr;
    delete newElement;
}

payload* payloadList::GetContent() { return ptr; }
void payloadList::SetContents(payload* p) { ptr = p; }

payloadList* payloadList::GetNext() { return next; }
void payloadList::SetNext(payloadList* n) { next = n; }

payloadList* payloadList::GetHead() { return head; }

void payloadList::push(payload* p) {
    if (ptr == NULL && next == NULL) { ptr = p; return; }
    newElement = new payloadList();
    newElement->SetContents(p);
    newElement->SetNext(head);
    head = newElement;
}

/*New Delete*/
void payloadList::del(int id){
    payloadList* prevPtr = head;
    payloadList* Pptr = head;

    for (; Pptr != NULL; Pptr = Pptr->GetNext()) {
        if (Pptr->GetContent()->GetID() == id){
            
            cout << prevPtr->GetContent()->GetName() << ":" << Pptr->GetContent()->GetName()
                 << ":" << Pptr->GetNext()->GetContent()->GetName() << endl;

            if (Pptr == prevPtr) head = Pptr->GetNext();
            else if (Pptr->GetNext() == NULL) {
                cout << "Next pointer is null" << endl;
                prevPtr->SetNext(nullptr);
                cout << "Next set to null" << endl;
            } 
            else prevPtr->SetNext(Pptr->GetNext());

            cout << "Deleting pointer" << endl;
            delete Pptr;
            cout << "Pointer Deleted" << endl;
            return;
        }

        //Move previous pointer object after current pointer has moved
        if (Pptr != prevPtr) prevPtr = prevPtr->GetNext();
    }
}

/*Old Delete
void payloadList::del(int id) {
    if (head->GetContent()->GetID() == id) {
        payloadList* nxt = head->GetNext();
        delete head;
        head = nxt;
    }
    else {
        payloadList* prevPtr = head;
        for (payloadList* Pptr = head; Pptr != NULL; Pptr = Pptr->GetNext()) {
            if (Pptr->GetContent()->GetID() == id){
                cout << "Object found: " << Pptr->GetContent()->GetName() << endl;
                cout << prevPtr->GetContent()->GetName() << ":" 
                     << Pptr->GetNext()->GetContent()->GetName() << endl;

                if (Pptr->GetNext() == NULL) prevPtr->SetNext(nullptr);
                else prevPtr->SetNext(Pptr->GetNext());
                delete Pptr;

                cout << "Deleting pointer" << endl;
                return;
            }

            //Move previous pointer object after current pointer has moved
            if (Pptr != prevPtr) prevPtr = prevPtr->GetNext();
        }
    }
}
*/

bool payloadList::hasNext() { return (next != NULL); }

bool payloadList::search(int id) {
    for (payloadList* ptr = head; ptr != NULL; ptr = ptr->GetNext()) {
        if (ptr->GetContent()->GetID() == id) return true;
    }
    return false;
}