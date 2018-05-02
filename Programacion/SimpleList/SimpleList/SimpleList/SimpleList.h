#ifndef __SIMPLE_LIST__
#define __SIMPLE_LIST__


template<class T>
class SimpleList
{
public:

	class Node
	{
	public:
		Node(const T& data) : data(data) {}
		~Node() {}

	public:
		T data;
		Node* next = nullptr;
	};

public:

	SimpleList() {}
	~SimpleList() {}

	Node* PushBack(const T& data)
	{
		Node* to_add = new Node(data);

		if (first == nullptr)
		{
			first = to_add;
		}
		else
		{
			//Find the last node
			Node* curr_node = first;
			while (curr_node->next != nullptr)
			{
				curr_node = curr_node->next;
			}

			//Add the new one to the last node
			curr_node->next = to_add;
		}

		//increase the number of elements
		num_elements++;

		//return current node
		return to_add;
	}

	Node* PushFront(const T& data)
	{
		Node* to_add = new Node(data);

		to_add->next = first;
		first = to_add;

		num_elements++;

		return to_add;
	}

	Node* InsertAt(const T& data, int position)
	{
		Node* to_add = new Node(data);

		if (position < num_elements)
		{
			Node* curr_node = first;
			for (int i = 0; i < position; ++i)
			{
				curr_node = curr_node->next;
			}

			to_add->next = curr_node->next;
			curr_node->next = to_add;
		}
		else
		{
			delete to_add;
			return nullptr;
		}

		num_elements++;
		return to_add;
	}
	T Erase(int position) 
	{	
		Node* erase = first;
		if(position < num_elements /*&& "Number out of range: Can not erase"*/ ) {
			Node* curr = first;
			for (int i = 0; i < position-1; ++i) {
				curr = curr->next;
			}
			for (int i = 0; i <= position-1; ++i) {
				erase = erase->next;
			}
			curr->next = erase->next;
			T ret = curr->data;
			num_elements--;
			delete erase;
			return ret;
		}
		else {
			delete erase;
		}
	}

	T PopFront()
	{
		Node* curr = first;

		first = first->next;

		T ret = curr->data;
		num_elements--;
		delete curr;
		return ret;
	}

	T PopBack() {
		Node* curr = first;
		for(int i=0; i<num_elements;i++){
			if (curr->next == nullptr) {
				T ret = curr->data;
				delete curr;
				num_elements--;
				return ret;
			}
			curr=curr->next;
		}
	}

	T& operator[] (int pos)
	{
		if (pos < num_elements)
		{
			Node* curr = first;
			for (int i = 0; i < pos; ++i)
			{
				curr = curr->next;
			}
			return curr->data;
		}
	}

private:
	Node* first = nullptr;
	int num_elements = 0;
};


#endif // !__SIMPLE_LIST__