#ifndef LIST_342_H_
#define LIST_342_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<class T>
struct Node
{
	T* data;
	Node* next;
};

template<class T>
class List342
{
public:

	
	List342();
	List342(List342<T>& other_list);
	~List342();

	
	bool Insert(T* object); //check if const works
	bool Pop(T& value);
	
	bool Remove(T target, T& result);
	bool Peek(T target, T& result) const;
	bool isEmpty() const;
	void DeleteList();
	bool Merge(List342<T>& list1);
	bool BuildList(string file_name);

	template<class T>
	friend ostream& operator<<(ostream& stream, const List342<T>& the_list);

	List342<T>& operator=(const List342<T>& other_list);
	List342<T>& operator+=(const List342<T>& other_list);
	List342<T> operator+(const List342<T>& right_list);
	bool operator==(const List342<T>& other_list);
	bool operator!=(const List342<T>& other_list);


	
private:
	Node<T>* head_;

};


#endif

template<class T>
inline List342<T>::List342()
{
	head_ = nullptr;
	
}

template<class T>
inline List342<T>::List342(List342<T>& other_list)
{
	if (other_list.head_ == nullptr)
	{
		head_ = nullptr;
	}
	Node<T>* other_temp = other_list.head_;

	T* insert_object = new T(*other_temp->data);
	Node<T>* insert_node = new Node<T>;
	insert_node->data = insert_object;

	head_ = insert_node;
	Node<T>* temp = head_;
	while (other_temp != nullptr)
	{
		other_temp = other_temp->next;
		if (other_temp == nullptr)
		{
			temp->next = nullptr;
		}
		else
		{
			T* insert_object = new T(*other_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->data = insert_object;
			temp->next = insert_node;
			temp = temp->next;
		}
		
	}
	
}

template<class T>
inline List342<T>::~List342()
{
	
	DeleteList();
}

template<class T>
inline bool List342<T>::Insert(T* object)
{
	if (head_ == nullptr)
	{
		T* insert_object = new T(*object);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = head_;
		insert_node->data = insert_object;
		head_ = insert_node;
		
		return true;
		
	}
	if (*object == *head_->data)
	{
		return false;

	}
	if (*object < *head_->data)
	{
		T* insert_object = new T(*object);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = head_;
		insert_node->data = insert_object;
		head_ = insert_node;
		
		return true;

	}

	Node<T>* temp = head_;
	while (temp->next != nullptr)
	{
		if (*object == *temp->next->data)
		{
			return false;
		}
		if (*object < *temp->next->data)
		{
			T* insert_object = new T(*object);
			Node<T>* insert_node = new Node<T>;
			insert_node->data = insert_object;
			insert_node->next = temp->next;
			temp->next = insert_node;
			
			return true;
		}
		temp = temp->next;
	}
	if (temp->next == nullptr)
	{
		T* insert_object = new T(*object);
		Node<T>* insert_node = new Node<T>;
		insert_node->data = insert_object;
		insert_node->next = temp->next;
		temp->next = insert_node;
		
		return true;
	}
	cout << "error" << endl;
	return false;
}

template<class T>
inline bool List342<T>::Pop(T& value)
{
	if (head_ != nullptr)
	{
		Node<T>* temp = head_;
		value = *head_->data;
		head_ = head_->next;
		delete temp->data;
		delete temp;
		return true;
	}
	else
	{
		return false;
	}
}


template<class T>
inline bool List342<T>::Remove(T target, T& result)
{
	
	if (head_ == nullptr)
	{
		
		return false;
	}
	Node<T>* temp = head_;
	if (*temp->data == target)
	{
		head_ = head_->next;
		result = *temp->data;
		delete temp->data;
		delete temp;
		
		return true;
	}
	if (temp->next == nullptr)
	{
		return false;
	}
	while (temp->next != nullptr  && target > *temp->next->data)
	{
		
		temp = temp->next;
		if (temp->next == nullptr)
		{
			return false;
		}
		
	}
	if (*temp->next->data == target)
	{
		Node<T>* temp2 = temp->next->next;
		result = *temp->next->data;
		delete temp->next->data;
		delete temp->next;
		temp->next = temp2;
		return true;
	}
	else
	{
		return false;
	}

}

template<class T>
inline bool List342<T>::Peek(T target, T& result) const
{
	if (head_ == nullptr)
	{

		return false;
	}
	Node<T>* temp = head_;
	if (*temp->data == target)
	{
		result = *temp->data;
		return true;
	}
	if (temp->next == nullptr)
	{
		return false;
	}
	while (temp->next != nullptr && target > *temp->next->data)
	{

		temp = temp->next;
		if (temp->next == nullptr)
		{
			return false;
		}

	}
	if (*temp->next->data == target)
	{
		
		result = *temp->next->data;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline bool List342<T>::isEmpty() const
{
	if (head_ == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline void List342<T>::DeleteList()
{
	while (head_ != nullptr)
	{
		Node<T>* temp = head_;
		head_ = head_->next;
		delete temp->data;
		delete temp;
		
	}
	
}

template<class T>
inline bool List342<T>::Merge(List342<T>& list1)
{
	T a;
	if (this == &list1)
	{
		return false;
	}
	if (list1.head_ == nullptr)
	{
		return false;
	}
	if (head_ == nullptr)
	{
		head_ = list1.head_;
		list1.head_ = nullptr;
		return true;
	}
	
	
	while (*head_->data == *list1.head_->data)
	{
		Node<T>* list1_temp2 = list1.head_;
		list1.head_ = list1.head_->next;
		delete list1_temp2->data;
		delete list1_temp2;
	}
	Node<T>* list1_temp = list1.head_;
	Node<T>* temp = head_;
	if (*head_->data > *list1.head_->data)
	{

		while (list1_temp->next != nullptr && *head_->data > *list1_temp->next->data)
		{
			list1_temp = list1_temp->next;
		}
		head_ = list1.head_;
		Node<T>* list1_temp2 = list1_temp;
		list1_temp = list1_temp->next;
		list1_temp2->next = temp;
		list1.head_ = list1_temp;
		//cout << list1 << " " << *this << endl;
		
	}
	while (list1_temp != nullptr)
	{
		//cout << list1 << " " << *this << endl << endl;
		if (temp->next == nullptr)
		{
			temp->next = list1_temp;
			list1.head_ = nullptr;
			return true;
		}
		if (*temp->next->data == *list1_temp->data)
		{
			Node<T>* list1_temp2 = list1_temp;
			list1_temp = list1_temp->next;
			list1.head_ = list1_temp;
			delete list1_temp2->data;
			delete list1_temp2;
			//list1.Remove(*list1_temp2->data, a);
			
		}
		else if(*temp->next->data < *list1_temp->data)
		{
			temp = temp->next;
			//cout << *temp->data << endl;
		}
		else if (*temp->next->data > *list1_temp->data)
		{
			//cout << "list1 " << *list1_temp->data << endl;
			while (list1_temp->next != nullptr && *temp->next->data > *list1_temp->next->data)
			{
				list1_temp = list1_temp->next;
				//cout << "aaaa" << *list1_temp->data << endl;
			}
			
			Node<T>* list1_temp2 = list1_temp;
			Node<T>* temp2 = temp->next;
			//cout << "eee " << *temp2->data << endl;
			list1_temp = list1_temp->next;
			//cout << *list1_temp2->data << endl;
			temp->next = list1.head_;
			temp = temp2;
			list1_temp2->next = temp;
			list1.head_ = list1_temp;
			
			
		}
	}
	list1.head_ = nullptr;
	return true;
	
}

template<class T>
inline bool List342<T>::BuildList(string file_name)
{
	ifstream in_file;
	in_file.open(file_name);
	while (!in_file.eof())
	{
		
		T* insert_object = new T;
		in_file >> *insert_object;
		if (!Insert(insert_object))
		{
			delete insert_object;
		}
			
	}
	in_file.close();
	return true;
}

template<class T>
inline List342<T>& List342<T>::operator=(const List342<T>& other_list)
{
	if (this == &other_list)
	{
		return *this;
	}
	DeleteList();
	if (other_list.head_ == nullptr)
	{
		head_ = nullptr;
	}
	Node<T>* other_temp = other_list.head_;

	T* insert_object = new T(*other_temp->data);
	Node<T>* insert_node = new Node<T>;
	insert_node->data = insert_object;

	head_ = insert_node;
	Node<T>* temp = head_;
	while (other_temp != nullptr)
	{
		other_temp = other_temp->next;
		if (other_temp == nullptr)
		{
			temp->next = nullptr;
		}
		else
		{
			T* insert_object = new T(*other_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->data = insert_object;
			temp->next = insert_node;
			temp = temp->next;
		}

	}
	return *this;
}

template<class T>
inline List342<T>& List342<T>::operator+=(const List342<T>& other_list)
{
	if (this == &other_list)
	{
		return *this;
	}
	if (other_list.head_ == nullptr)
	{
		return *this;
	}
	Node<T>* temp = head_;
	Node<T>* other_temp = other_list.head_;
	if (temp == nullptr)
	{
		T* insert_object = new T(*other_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		head_ = insert_node;
		temp = head_;
		other_temp = other_temp->next;

		while (other_temp != nullptr)
		{
			T* insert_object = new T(*other_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->next = nullptr;
			insert_node->data = insert_object;
			temp->next = insert_node;
			temp = temp->next;
			other_temp = other_temp->next;
		}
		return *this;
	}
	if (*temp->data > *other_temp->data)
	{
		Node<T>* temp2 = temp;
		T* insert_object = new T(*other_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		head_ = insert_node;
		temp = head_;
		other_temp = other_temp->next;
		
		while (other_temp != nullptr && *temp2->data > *other_temp->data)
		{
			T* insert_object = new T(*other_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->next = nullptr;
			insert_node->data = insert_object;
			temp->next = insert_node;
			temp = temp->next;
			other_temp = other_temp->next;
		}
		temp->next = temp2;
		temp = temp->next;
	}
	
	while (temp->next != nullptr)
	{
		Node<T>* temp2 = temp;
		if (other_temp != nullptr && *temp->next->data == *other_temp->data)
		{
			other_temp = other_temp->next;
		}
		while (other_temp != nullptr && *temp->next->data > *other_temp->data)
		{
			
			T* insert_object = new T(*other_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->data = insert_object;
			insert_node->next = temp->next;
			temp2->next = insert_node;
			temp2 = temp2->next;
			other_temp = other_temp->next;
		}
		temp = temp->next;
	}
	while(other_temp != nullptr)
	{
		T* insert_object = new T(*other_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		temp->next = insert_node;
		temp = temp->next;
		other_temp = other_temp->next;
	}
	return *this;
}

template<class T>
inline List342<T> List342<T>::operator+(const List342<T>& right_list)
{
	List342<T> ReturnList;
	Node<T>* left_temp = head_;
	Node<T>* right_temp = right_list.head_;
	Node<T>* temp = ReturnList.head_;

	if (left_temp == nullptr && right_temp == nullptr)
	{
		return ReturnList;
	}
	if (left_temp == nullptr)
	{
		ReturnList += right_list;
		return ReturnList;
	}
	if (right_temp == nullptr)
	{
		ReturnList += *this;
		return ReturnList;
	}
	if (*left_temp->data < *right_temp->data)
	{
		T* insert_object = new T(*left_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		ReturnList.head_ = insert_node;
		left_temp = left_temp->next;
	}
	else if (*left_temp->data == *right_temp->data)
	{
		T* insert_object = new T(*left_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		ReturnList.head_ = insert_node;
		left_temp = left_temp->next;
		right_temp = right_temp->next;
	}
	else if (*left_temp->data > *right_temp->data)
	{
		T* insert_object = new T(*right_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		ReturnList.head_ = insert_node;
		right_temp = right_temp->next;
	}

	temp = ReturnList.head_;
	while (left_temp != nullptr && right_temp != nullptr)
	{
		if (*left_temp->data < *right_temp->data)
		{
			T* insert_object = new T(*left_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->next = nullptr;
			insert_node->data = insert_object;
			temp->next = insert_node;
			left_temp = left_temp->next;
			temp = temp->next;
		}
		else if (*left_temp->data == *right_temp->data)
		{
			T* insert_object = new T(*left_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->next = nullptr;
			insert_node->data = insert_object;
			temp->next = insert_node;
			left_temp = left_temp->next;
			right_temp = right_temp->next;
			temp = temp->next;
		}
		else if (*left_temp->data > *right_temp->data)
		{
			T* insert_object = new T(*right_temp->data);
			Node<T>* insert_node = new Node<T>;
			insert_node->next = nullptr;
			insert_node->data = insert_object;
			temp->next = insert_node;
			right_temp = right_temp->next;
			temp = temp->next;
		}
	}
	while (left_temp != nullptr)
	{
		T* insert_object = new T(*left_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		temp->next = insert_node;
		left_temp = left_temp->next;
		temp = temp->next;
	}
	while (right_temp != nullptr)
	{
		T* insert_object = new T(*right_temp->data);
		Node<T>* insert_node = new Node<T>;
		insert_node->next = nullptr;
		insert_node->data = insert_object;
		temp->next = insert_node;
		right_temp = right_temp->next;
		temp = temp->next;
	}
	return ReturnList;
}

template<class T>
inline bool List342<T>::operator==(const List342<T>& other_list)
{
	Node<T>* temp = head_;
	Node<T>* other_temp = other_list.head_;

	if (temp == nullptr && other_temp == nullptr)
	{
		return true;
	}
	else if (temp == nullptr || other_temp == nullptr)
	{
		return false;
	}
	while(*temp->data == *other_temp->data)
	{
		if (temp->next == nullptr && other_temp->next == nullptr)
		{
			return true;
		}
		else if (temp->next == nullptr || other_temp->next == nullptr)
		{
			return false;
		}
		temp = temp->next;
		other_temp = other_temp->next;
	}
	return false;
}

template<class T>
inline bool List342<T>::operator!=(const List342<T>& other_list)
{
	if (!(*this == other_list))
	{
		return true;
	}
	return false;
}





template<class T>
inline ostream& operator<<(ostream& stream, const List342<T>& the_list)
{
	Node<T>* temp = the_list.head_;
	while (temp != nullptr)
	{
		stream << *temp->data;
		temp = temp->next;
	}
	
	return stream;
}


