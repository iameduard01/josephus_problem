#include <iostream>
using namespace std;

struct Node { 
    int val;
    Node* next; 
    Node (int v) : val(v), next(nullptr) {} 
};

class Lista {
    int n, k;
    Node* head; 
public:
    Lista (int n_, int k_){
        n=n_;
        k=k_;
        head = new Node(1);
    }
    void Josephus(){
        Node* prev = head; 
        for (int i = 2; i <= n; i++) { 
            Node* curr = new Node(i);
            prev->next = curr;
            prev = curr;
    }
    prev->next = head;

    Node* curr = head;
    while (curr->next != curr) {
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        cout << "Elementul sters este: " << curr->val << " " << '\n';
        Node* nextNode = curr->next;
        curr->val = nextNode->val;
        curr->next = nextNode->next;
        delete nextNode;
    }

    cout << "Elementul ramas la final este: " << curr->val << endl;

    }
};

int main() {
    Lista L(5,2);
    L.Josephus();
}
