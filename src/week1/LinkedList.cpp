#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    //Truy cap O(n)
    int get(int index) {
        Node* current = head;
        for(int i = 0; i < index; i++) {
            if (current == nullptr) {
            return -1;
            }
            current = current->next;
        }
        return current->data;
    }

    //Chen vao dau O(1)
    void addHead(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    //Chen vao cuoi O(n)
    void addLast(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

    //Chen vao vi tri i 0(n)
    void addIndex(int index, int value){
        if(index <= 0){
            cout << "ERROR" << endl;
            return;
        }
        if(index == 1){
            addHead(value);
            return;
        }
        if(head == nullptr){
            addHead(value);
            return;
        } else {
            Node *h = head;
            for(int i = 2; h != nullptr && i < index; i++){
                h = h -> next;
            }
            if(h == nullptr){
                cout << "ERROR" << endl;
                return;
            } else {
                Node *newNode = new Node{value, h -> next};
                h -> next = newNode;
            }
        }
    }

    //Xoa dau O(1)
    void deleteHead() {
        if (head == nullptr) {
            cout << "ERROR" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //Xoa cuoi O(n)
     void deleteLast() {
        if (head == nullptr) {
            cout << "ERROR" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    //Xoa vi tri i O(n)
    void removePos(int index) {
		if (index == 0) {
			deleteHead();
			return;
		}
		Node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

    //Duyet xuoi O(n)
    void traverseForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    //Duyet nguoc O(n)
    void traverseBackward() {}

};

int main() {
    LinkedList list;

    cout << "---Chen phan tu dau, cuoi, vi tri i---" << endl;
    list.addHead(5);
    list.addHead(11);
    list.addLast(24);
    list.traverseForward(); // Output: 11 5 24
    list.addIndex(2, 17); // List: 11 -> 17 -> 5 -> 24
    list.traverseForward(); // Output: 11 17 5 24

    cout << "---Truy cap phan tu---" << endl;
    cout << list.get(1) << endl; // Output: 17
    cout << list.get(3) << endl; // Output: 24

    cout << "---Xoa phan tu dau, cuoi, vi tri i---" << endl;
    list.deleteHead(); // List: 17 -> 5 -> 24
    list.traverseForward(); // Output: 17 5 24
    list.deleteLast(); // List: 17 -> 5
    list.traverseForward(); // Output: 17 5
    list.removePos(0); // List: 5
    list.traverseForward(); // Output: 5

    return 0;
}