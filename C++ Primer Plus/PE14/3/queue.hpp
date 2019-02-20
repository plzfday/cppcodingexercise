#ifndef QUEUE_HPP_
#define QUEUE_HPP_

template<class Type>
class Queue
{
private:
	struct Node
	{
		Type mItem;
		Node* next;
	};
	int mQueueSize;
	int mNowCount;
	Node* mFront;
	Node* mRear;
	Queue(const Queue& qu) { }
	Queue& operator=(const Queue& qu) { return *this; }
public:
	Queue(int size = 10);
	~Queue();
	bool enqueue(const Type& item);
	bool dequeue(Type& item);
	bool isEmpty() { return mNowCount == 0; }
	bool isFull() { return mNowCount == mQueueSize; }
};

template<class Type>
inline Queue<Type>::Queue(int size)
	: mQueueSize(size), mNowCount(0)
{
	mFront = mRear = nullptr;
}

template<class Type>
Queue<Type>::~Queue()
{
	Node* temp;
	while (mFront != nullptr)
	{
		temp = mFront;
		mFront = mFront->next;
		delete temp;
	}
}

template<class Type>
bool Queue<Type>::enqueue(const Type & item)
{
	if (isFull())
	{
		return false;
	}
	Node* newNode = new Node;
	if (newNode == nullptr)
	{
		return false;
	}
	newNode->mItem = item;
	newNode->next = nullptr;
	mNowCount++;
	if (mFront == nullptr)
	{
		mFront = newNode;
	}
	else
	{
		mRear->next = newNode;
	}
	mRear = newNode;
	return true;
}

template<class Type>
bool Queue<Type>::dequeue(Type & item)
{
	if (mFront == nullptr)
	{
		return false;
	}
	item = mFront->mItem;
	Node* temp = mFront;
	mFront = mFront->next;
	delete temp;
	mNowCount--;
	if (mNowCount == 0)
	{
		mRear = nullptr;
	}
	return true;
}

#endif // !QUEUE_H_


