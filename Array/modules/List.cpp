#include "List.h"

template<class T>
void List<T>::increaseCapacity(int newCapacity){
    this->capacity = newCapacity < this->capacity * 2 ? this->capacity * 2 : newCapacity;
    T* newPtr = new T[this->capacity];
    for (int i = 0; i < this->size; i++){
        newPtr[i] = this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr = newPtr;
}

template<class T>
List<T>::List(){
    this->capacity = 0;
    this->ptr = new T[capacity];
    this->size = 0;
}

template<class T>
List<T>::~List(){
    delete[] this->ptr; 
}

template<class T>
void List<T>::insert(T elem, int index){
    if (index < 0 || index > this->size) 
        throw ArrayException(); 
    if (this->size == this->capacity) 
        this->increaseCapacity(this->size + 1); 
    // Если index==size, этот цикл не выполнится ни разу 
    for (int j = this->size-1; j >= index; j--){
        this->ptr[j+1] = this->ptr[j];
    }

    this->size++; 
    this->ptr[index] = elem;
}

template<class T>
void List<T>::push(T elem) { 
    insert(elem, this->size); 
}

template<class T>
void List<T>::pop(){
    this->remove(this->size-1);
}

// template<class T>
// void List<T>::remove(int index){
//     if (index < 0 || index >= this->size){
//         throw ArrayException();
//     }
//     for (int j = index; j < (this->size)-1; j++){
//         (this->ptr)[j] = (this->ptr)[j+1];
//     }
//     (this->ptr)[size-1] = 0; 
//     this->size--; 
// }

// template<class T>
// ostream &List<T>::operator<<(ostream &out, const List<T> &arr){
//     out << "[";
//     for (int i = 0; i < arr.size; i++){
//         if(i == arr.size - 1){
//             out << arr.ptr[i];
//         }else{
//             out << arr.ptr[i] << ", ";
//         }
//     }
//     out << "]" << endl;
//     return out; 
// }

template class List<int>;
template class List<std::string>;