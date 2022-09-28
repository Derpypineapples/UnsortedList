#include "payloadList.h"

payloadList::payloadList() {
    head = this;
    ptr = nullptr;
    next = nullptr;
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

bool payloadList::hasNext() { return (next != NULL); }

payload* ptr;
payloadList* newElement;
payloadList* next;
payloadList* head;