#include <iostream>

using namespace std;

class ArrayException {};

template <class T> class List{
    T *ptr;
    int size;
    int capacity;

    void increaseCapacity(int newCapacity);

    // void merge_sort(T *arr, int low, int high){}
    // // Merge sort 
    // void merge(T *arr, int low, int high, int mid){}

public:
    List();

    ~List();

    // int &operator[](int index){}

    void insert(T elem, int index);

    // void remove(int index);
    void remove(int index){ 
        if (index < 0 || index >= size){
            throw ArrayException();
        }
        for (int j = index; j < size-1; j++){
            ptr[j] = ptr[j+1];
        }
        ptr[size-1] = 0; 
        size--; 
    }

    void push(T elem);

    void pop();

    // int length() const{}

    // int findIndex(T elem){}

    // void reverse(){}

    // void sort(){}

    // void clear(){}

    // T* begin(){}

    // T* end(){}

    // friend ostream& operator<<(ostream &out, const List& arr);
    friend ostream& operator<<(ostream &out, const List& arr){
        out << "[";
        for (int i = 0; i < arr.size; i++){
            if(i == arr.size - 1){
                out << arr.ptr[i];
            }else{
                out << arr.ptr[i] << ", ";
            }
        }
        out << "]" << endl;
        return out; 
    }
};

/*
template <class T> class List{
    T *ptr;
    int size;
    int capacity;

    void increaseCapacity(int newCapacity) { 
        capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
        T* newPtr = new T[capacity];
        for (int i = 0; i < size; i++){
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
    }

    void merge_sort(T *arr, int low, int high){
        int mid;
        if (low < high){
            //divide the array at mid and sort independently using merge sort
            mid=(low+high)/2;
            merge_sort(arr,low,mid);
            merge_sort(arr,mid+1,high);
            //merge or conquer sorted arrays
            merge(arr,low,high,mid);
        }
    }
    // Merge sort 
    void merge(T *arr, int low, int high, int mid){
        int i, j, k, c[50];
        i = low;
        k = low;
        j = mid + 1;
        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                c[k] = arr[i];
                k++;
                i++;
            }
            else  {
                c[k] = arr[j];
                k++;
                j++;
            }
        }
        while (i <= mid) {
            c[k] = arr[i];
            k++;
            i++;
        }
        while (j <= high) {
            c[k] = arr[j];
            k++;
            j++;
        }
        for (i = low; i < k; i++)  {
            arr[i] = c[i];
        }
    }

public:
    explicit List(int startCapacity = 0){
        capacity = startCapacity;
        ptr = new T[capacity];
        size = 0;
    }

    ~List(){ 
        delete[] ptr; 
    }

    int &operator[](int index){
        if (index >= size || index < 0){
            throw ArrayException(); 
        }else{
            return ptr[index];
        }  
    }

    void insert(T elem, int index){ 
        if (index < 0 || index > size) 
            throw ArrayException(); 
        if (size == capacity) 
            increaseCapacity(size + 1); 
        // Если index==size, этот цикл не выполнится ни разу 
        for (int j = size-1; j >= index; j--){
            ptr[j+1] = ptr[j];
        }

        size++; 
        ptr[index] = elem;
    }

    void remove(int index){ 
        if (index < 0 || index >= size){
            throw ArrayException();
        }
        for (int j = index; j < size-1; j++){
            ptr[j] = ptr[j+1];
        }
        ptr[size-1] = 0; 
        size--; 
    }

    void push(T elem) { 
        insert(elem, size); 
    }

    void pop(){
        remove(size-1);
    }

    int length() const{
        return size;
    }

    int findIndex(T elem){
        for (int i = 0; i < size; i++){
            if(elem == ptr[i]){
                return i;
            }
        }

        return -1;
    }

    void reverse(){
        T* newPtr = new T[capacity];
        for (int i = size-1, j = 0; i >= 0; i--, j++){
            newPtr[j] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
    }

    void sort(){
        merge_sort(ptr, 0, size-1);
    }

    void clear(){
        delete[] ptr;
        size = 0;
        capacity = 0;
    }

    T* begin(){
        return &ptr[0];
    }

    T* end(){
        return &ptr[size];
    }

    friend ostream& operator<<(ostream &out, const List& arr){
        out << "[";
        for (int i = 0; i < arr.size; i++){
            if(i == arr.size - 1){
                out << arr.ptr[i];
            }else{
                out << arr.ptr[i] << ", ";
            }
        }
        out << "]" << endl;
        return out; 
    }
};

*/
