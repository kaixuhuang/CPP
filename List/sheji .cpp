#include<iostream>
using namespace std;


class MyLinkedList {

public:

    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode() :val(0), next(nullptr) {}
        LinkedNode(int val) :val(val), next(nullptr) {}
    };

    MyLinkedList() {
        vhead= new LinkedNode();
        size = 0;
    }

    int get(int index) {
        LinkedNode* cur =new LinkedNode();
        if (index<0 || index>size-1 || size<1)
            return -1;
        else
        {
            cur = vhead;
            while (index>-1)
            {
                cur = cur->next;
                index--;
            }
        }
        return cur->val;
        delete(cur);
    }

    void addAtHead(int val) {
        LinkedNode* head = new LinkedNode(val);
        head->next = vhead->next;
        vhead->next = head;
        size++;
    }

    void addAtTail(int val) {
        LinkedNode* tail = new LinkedNode(val);
        LinkedNode* cur = new LinkedNode();
        cur = vhead;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = tail;
        size++;

    }

    void addAtIndex(int index, int val) {
        if (index < 0)
        {
            LinkedNode* head = new LinkedNode(val);
            head->next = vhead->next;
            vhead->next = head;
            size++;
        }
        else if (index == size)
        {
            LinkedNode* tail = new LinkedNode(val);
            LinkedNode* cur = new LinkedNode();
            cur = vhead;
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = tail;    
            size++;
        }
        else if (index < size)
        {
            LinkedNode* insert = new LinkedNode(val);
            LinkedNode* cur = new LinkedNode();
            cur = vhead;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            insert->next = cur->next;
            cur->next = insert;
            size++;
        }


    }

    void deleteAtIndex(int index) {
        
        if (index < size)
        {
            LinkedNode* del = new LinkedNode();
            LinkedNode* cur = new LinkedNode();
            cur = vhead;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            del = cur->next;
            cur->next = del->next;
            delete(del);
            size--;
        }
     
    }

    void printl() {
        if (size < 1)
            cout << "NULL" ;
        else {
            LinkedNode* p = vhead->next;
            while (p)
            {
                cout << p->val<< " ";
                p = p->next;
            }
        }




    }
private:
    int size;
    LinkedNode* vhead;
};
//int main() {
//    MyLinkedList A ;
//    A.addAtHead(1);
//    A.printl();
//    cout << endl;
//    A.addAtTail(3);
//    A.printl();
//    cout << endl;
//    A.addAtIndex(1, 2);
//    A.printl();
//    cout << endl;
//    A.get(1);
//    A.printl();
//    cout << endl;
//    A.deleteAtIndex(1);
//    A.printl();
//    cout << endl;
//    A.get(1);
//    A.printl();
//    cout << endl;
//
//   
//
//
//
//
//
//}