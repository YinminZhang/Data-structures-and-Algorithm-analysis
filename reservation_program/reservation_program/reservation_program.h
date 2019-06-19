// Yinmin Zhang 201694069
// A simple airline ticket reservation program
#ifndef RESERVATION_H_
#define RESERVATION_H_
#define defaultSize 10

#include<iostream>
#include<string>
using std::endl;
using std::cout;
using std::string;

class Passenger
{
private:
	string name;
	int age;
	string fight;
	string fights;
public:
	Passenger(const string Name, const int Age, const string Fight, const string Fights)
	{
		name = Name;
		age = Age;
		fight = Fight;
		fights = Fights;
	}
	Passenger(const Passenger& per)
	{
		this->age = per.age;
		this->fight = per.fight;
		this->name = per.name;
	}
	string getFight()
	{
		return fight;
	}
	string getFights()
	{
		return fights;
	}
	int getAge()
	{
		return age;
	}
	string getName()
	{
		return name;
	}
	void display()
	{
		cout << "Name: " << name << endl
			<< "Age: " << age << endl
			<< "Fight: " << fight << endl;
	}
};

class Node
{
private:
	Passenger* person;
	string fight;
	string fights;
	bool Reserved;
public:
	Node* next;

	Node(const Passenger& per, Node* nextval = nullptr)
	{
		person = new Passenger(per);
		fight = person->getFight();
		fights = person->getFights();
		next = nextval;
		Reserved = true;
	}
	Node(const string Fight, const string Fights, Node* nextval = nullptr)
	{
		person = nullptr;
		fight = Fight;
		fights = Fights;
		next = nextval;
		Reserved = false;
	}
	Node(const string Name, const int Age, const string Fight, const string Fights, Node* nextval = nullptr)
	{
		person = new Passenger(Name, Age, Fight, Fights);
		fights = Fights;
		fight = Fight;
		next = nextval;
		Reserved = true;
	}
	Node(Node* nextval = nullptr)
	{
		next = nextval;
		person = nullptr;
		Reserved = false;
	}
	string getPassengerName()
	{
		return person->getName();
	}
	string getFight()
	{
		return fight;
	}
	string getFights()
	{
		return fights;
	}
	bool isReserved()
	{
		return Reserved;
	}
	void display()
	{
		cout << "Fight: " << fight << endl;
		if (Reserved)
			person->display();
		else
			cout << "Unreserved" << endl;
	}
	~Node()
	{
		if (person != nullptr)
			delete person;
		if (next != nullptr)
			delete next;
	}
};

class reserve
{
private:
	Node* head;
	Node* tail;
	Node* curr;
	int cnt;

	void init()
	{
		curr = tail = head = new Node;
		cnt = 0;
	}
	void removeall()
	{
		while (head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	reserve(int size = defaultSize)
	{
		init();
	}
	~reserve()
	{
		removeall();
	}
	void display()const
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			temp->display();
			temp = temp->next;
		}
	}
	void Reserve(Passenger& per)
	{
		Node* temp = curr;
		curr = head;
		while ((curr->next->getPassengerName()<per.getName())&&
			(curr->next!=nullptr))
			curr = curr->next;
		curr->next = new Node(per, curr->next);
		curr = temp;
		cnt++;
	}
	void Cancel(Passenger& per)
	{
		Node* temp = curr;
		curr = head;
		while (curr->next != nullptr)
		{
			if (
				(curr->next->getPassengerName() == per.getName())
				&& (curr->next->getFight() == per.getFight())
				&& (curr->next->getFights() == per.getFights())
				)
			{
				Node* tempNode = curr->next;
				curr->next = curr->next->next;
				if (temp != tempNode)
					curr = temp;
				else
					curr = head;
				delete tempNode;
				cnt--;
				return;
			}
			curr = curr->next;
		}
		curr = temp;
	}
	void Check(Passenger& per)
	{
		Node* temp = curr;
		curr = head;
		while (curr->next != nullptr)
		{
			if (
				(curr->next->getPassengerName() == per.getName())
				&& (curr->next->getFight() == per.getFight())
				&& (curr->next->getFights() == per.getFights())
				)
			{
				curr->next->display();
				curr = temp;
				return;
			}
			curr = curr->next;
		}
		curr = temp;
	}
	int length()const
	{
		return cnt;
	}
};

#endif // !RESERVATION_H_