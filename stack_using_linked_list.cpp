 #include<iostream>
using namespace std;

template <typename T>

class Node{
	public:
		T data;
		Node<T>*next;
		
		Node(T data){
			this->data = data;
			this->next = NULL;
		}
	
};
 
template <typename T>


class Stack{

	Node<T>*head;
	
	int size;
	public:
		
		Stack(){
			head =NULL;
			size=0;
		}
		
		
		void push(T element){
		
			Node <T>*newNode = new Node<T>(element); 
		
			newNode->next=head;
			head = newNode;	
		
			size++;
		}
		
		
		bool isEmpty(){	
			return size==0;
		}
		
		
		T top(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			else
				return head->data;
		}
		
		
		T pop(){
			if(isEmpty()){
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			else{
				T temp = head->data;
				Node<T> *temp1 = head;
				head = head->next;
				delete temp1;
				size--;
				return temp;
				
			}
			
		}
		
		
		int getSize(){
			return size;
		}
		
		
};


int main()
{

	Stack<int> s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	
	cout<<s.top()<<endl;
	
	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
	
	cout<<s.getSize()<<endl;
	
	
	cout<<s.isEmpty()<<endl;
	
	return 0;
}
