#include <iostream>
using namespace std;
const int Max = 100;

struct List{
    int size;
    int arr[Max];

    List(){
        size = 0;
    }

    // O(1)
    int get(int i){
        return arr[i];
    }

    // O(1)
    void addFirst(int data){
        for(int i = size; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = data;
        size++;
    }

    // O(1)
    void addLast(int data){
        arr[size] = data;
        size++;
    }

    // O(n)
    void addindex(int pos, int data){
        for(int j = size; j > pos; j--){
            arr[j] = arr[j - 1];
        }
        arr[pos] = data;
        size++;
    }

    // O(n)
    void removeFirst(){
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // O(1)
    void removeLast(){
        size--;
    }

    // O(n)
    void removeindex(int pos){
        for(int i = pos; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // O(n)
    void tranverseForward(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // O(n)
    void tranverseBackward(){
        for(int i = size - 1; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    List myList;
    
    cout << "---Chen phan tu dau, cuoi, vtri i---" << endl;
    myList.addFirst(14);
    myList.addFirst(7);
    myList.addLast(35);
    myList.addLast(44);
    myList.addindex(2, 16);
    myList.tranverseForward();

    cout << "---Xoa phan tu dau, cuoi, vtri i---" << endl;
    myList.removeindex(3);
    myList.removeFirst();
    myList.removeLast();
    myList.tranverseForward();

    cout << "---Duyet danh sach---" << endl;
    myList.tranverseForward();
    myList.tranverseBackward();

    return 0;
}
