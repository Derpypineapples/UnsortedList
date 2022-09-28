#ifndef payload_h
#define payload_h

class payload{
    public:
    payload(int c);

    int GetContent();
    void SetContent(int c);

    private:
    int content;
};

#endif