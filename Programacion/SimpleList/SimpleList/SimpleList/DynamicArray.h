#ifndef _DYNAMIC_ARRAY__
#define _DYNAMIC_ARRAY__
#include <iostream>
#define CAPACITY 10



template <class T>
class DynamicArray {
private:

	unsigned int capacity = CAPACITY;
	unsigned int size=0;
	T* Array = nullptr;

public:
	
	DynamicArray(){
		Array = new T[capacity]();
	};
	~DynamicArray() {
		delete[] Array;
	}

	void setSize(int _size) {
		size = _size; 
	}
	
	bool empty() {
		if (size == 0) {
			return true;}
		else{
			return false;}
	}

	void PushBack(const T& Data) {
		Array[size] = Data;
		CapacityTruster();
	}

	void PushFront(const T& Data) {
		for (int i = size; size >= 0; --i) {
			Array[i + 1] = Array[i];
		}
		Array[0] = Data;
		CapacityTruster();
	}

	void InsertAt(const T& Data, int Position) {
		for (int i = size; size >= Position; --i) {
			Array[i + 1] = Array[i];
		}
		Array[Position] = Data;
		CapacityTruster();
	}

	void EraseAt(int Position) {
		for (int i = size; size >= Position; --i) {
			Array[i + 1] = Array[i];
		}
		size--;
	}

	void IncreaseCapacity() {
		capacity += CAPACITY;
		T*newArray = new T[capacity]();
		for (int i = 0; i < size; ++i) {
			newArray[i] = Array[i];
		}
		delete Array;
		Array = newArray;
		delete newArray;
	}

	void CapacityTruster() {
		if (size < capacity) {
			size++;
		}
		else {
			IncreaseCapacity();
			size++;
		}
	}

};









#endif // !_DYNAMIC_ARRAY__
