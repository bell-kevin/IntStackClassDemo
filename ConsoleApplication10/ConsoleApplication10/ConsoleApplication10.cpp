// ConsoleApplication10.cpp

#include <iostream>
#include <memory>

using namespace std;
class IntStack
{
	unique_ptr<int[]> stackArray;
	int capacity;
	int top;
public:
	//constructor
	IntStack(int capacity);

	//member functions
	void push(int value);
	void pop(int& value);
	bool isEmpty() const;
	
	//stack exception class
	class Overflow {};
	class Underflow {};
};

//constructor
IntStack::IntStack(int capacity)
{
	stackArray = make_unique<int[]>(capacity);
	this->capacity = capacity;
	top = 0;
}

//push function
void IntStack::push(int value)
{
	if (top == capacity)
		throw Overflow();
	stackArray[top++] = value;
}

//pop function
void IntStack::pop(int& value)
{
	if (isEmpty())
		throw Underflow();
	value = stackArray[--top];
}

//isEmpty function
bool IntStack::isEmpty() const
{
	return top == 0;
}


int main()
{
	IntStack stack(5);
	int values[] = { 5, 10, 15, 20, 25 };
	int value = 0;
	
	cout << "Pushing...\n";
	for (int i = 0; i < 5; i++)
	{
		cout << values[i] << " ";
		stack.push(values[i]);
	}
	
	cout << "\nPopping...\n";
	while (!stack.isEmpty())
	{
		stack.pop(value);
		cout << value << " ";
	}
	cout << endl;
	return 0;
}
