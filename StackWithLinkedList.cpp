#include <iostream>
using namespace std;

struct n
{
	int data;
	struct n* next;
};

typedef struct n Node;


class Stack
{
	Node* root;
public:
	Stack()
	{
		root = NULL;
	}
	void push(int x)
	{
		if(root == NULL)
		{
			root = new Node();
			root -> data = x;
			root -> next = NULL;
			return;
		}

		Node* iter;
		iter = root;
		while(iter -> next != NULL)
		{
			iter = iter -> next;
		}
		iter -> next = new Node();
		iter -> next -> data = x;
		iter -> next -> next = NULL;
	}

	int pop()
	{
		Node* iter;
		iter = root;
		int donus;
		if(root == NULL)
		{
			cout<<"stack bos"<<endl;
			return -1;
		}
		if(iter->next == NULL)
		{
			Node* temp = new Node();
			donus = temp->data;
			temp = iter;
			iter = root = NULL;
			delete temp;
			return donus;
		}
		while(iter -> next -> next != NULL)
		{
			iter = iter -> next;
		}
		Node* yeni = new Node();
		donus = iter -> data;
		yeni = iter -> next;//Sadi bu satırı kullanmadı, bence de gerek yok.
		iter -> next = NULL;
		delete yeni;
		return donus;
	}

	void display()
	{
		Node* iter;
		iter = root;
		if(root ==NULL)
		{
			cout<<"gosterilecek bir sey yok"<<endl;
			cout<<"-----------"<<endl;
			return;
		}
		if(root->next == NULL)
		{
			cout<< iter->data<<endl;
			cout<<"----------"<<endl;
			return;
		}
		while(iter->next != NULL)
		{
			cout<< iter->data <<endl;
			iter = iter->next;
		}
		cout<<iter->data<<endl;

		cout<<"----------"<<endl;
	}
};

// stacktaki ilk elemanı, yani root'un gosterdiğği elemanı nasıl sileceğiz? (büyük ihtimalle root kullanarak)

int main()
{
	Stack a;
	a.push(23);
	a.display();
	a.pop();
	a.display();
	a.pop();
	a.push(34);
	a.push(309);
	a.push(439);
	a.push(930);
	a.display();
}