#ifndef payloadList_h
#define payloadList_h

#include "payload.h"

class payloadList{
    public:
    payloadList();

    payload* GetContent();
    void SetContents(payload* p);

    payloadList* GetNext();
    void SetNext(payloadList* n);

    payloadList* GetHead();

    void push(payload* p);

    bool hasNext();

    private:
    payload* ptr;
    payloadList* newElement;
    payloadList* next;
    payloadList* head;
};

#endif