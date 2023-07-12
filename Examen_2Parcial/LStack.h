#pragma once
class LStack{
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* topNode;

public:
    LStack();
    ~LStack();

    void Push(int value);
    void Pop();
    int Top();
    bool IsEmpty();
};
