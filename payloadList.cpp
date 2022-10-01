#include "payloadList.h"

payloadList::payloadList() {
    head = this;
    ptr = nullptr;
    next = nullptr;
}
payloadList::~payloadList() {
    ptr = nullptr;
    newElement = nullptr;
    next = nullptr;
    head = nullptr;
    /*
    delete ptr;
    delete newElement;
    delete next;
    delete head;
    */
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

void payloadList::del(int id) {
    if (head->GetContent()->GetID() == id) {
        payloadList* nxt = head->GetNext();
        head = nullptr;
        head = nxt;
    }
    else {
        payloadList* prevPtr = head;
        for (payloadList* Pptr = head; Pptr != NULL; Pptr = Pptr->GetNext()) {
            if (Pptr->GetContent()->GetID() == id){
                if (Pptr->GetNext() == NULL) prevPtr->SetNext(nullptr);
                else prevPtr->SetNext(Pptr->GetNext());
                delete Pptr;
                break;
            }

            //Move previous pointer object after current pointer has moved
            if (Pptr != prevPtr) prevPtr = prevPtr->GetNext();
        }
    }
}

bool payloadList::hasNext() { return (next != NULL); }

bool payloadList::search(int id) {
    for (payloadList* ptr = head; ptr != NULL; ptr = ptr->GetNext()) {
        if (ptr->GetContent()->GetID() == id) return true;
    }
    return false;
}