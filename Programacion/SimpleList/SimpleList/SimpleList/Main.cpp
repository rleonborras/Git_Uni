#include "SimpleList.h"
#include "DynamicArray.h"



int main()
{
	DynamicArray<int> Array;
	SimpleList<int> list;

	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	//for (int i = 0; i < 11; i++) {
	//	Array.PushBack(i);
	//}
	Array.PushBack(2);
	Array.PushBack(3);


	//list.PushFront(0);
	//list.InsertAt(3, 2);
	//list.PopBack();
	//list.PopFront();
	list.Erase(3);
	int a = list[1];
	int b = 0;

}