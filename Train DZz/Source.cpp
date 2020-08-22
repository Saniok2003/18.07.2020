#include <iostream>
#include <string>
using namespace std;

struct train
{
	int number = 0;
	string name = "";
	float time = 0;
	train* next = nullptr;
};
class TrainHub
{
public:
	bool Find(train* Head, int NumberItem) {
		train* ptr;
		ptr = Head;
		while (ptr != nullptr) {
			if (NumberItem == ptr->number)
			{
				return true;
			}
			else ptr = ptr->next;
		}
		return false;
	}
	bool Time(train* Head, float TimeItem)
	{
		float fractpart, intpart;
		fractpart = modf(TimeItem, &intpart);
		if ((intpart > 24) || (fractpart > 0.60) || (TimeItem < 0))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	train* AddTrain(train* Head, int Number) {
		Number--;
		train* NewItem = new(train);
		cout << "Number of the train: ";
		while (!(cin >> NewItem->number) || Find(Head, NewItem->number) == true)
		{
			cout << "This number is already listed!" << endl;
			cout << "Enter number again: ";
		}
		cout << "Destination: ";
		cin >> NewItem->name;
		cout << "Arrival time: ";
		while (!(cin >> NewItem->time) || Time(Head, NewItem->time) == true)
		{
			cout << "Time is entered incorrectly!" << endl;
			cout << "Enter time again: ";
		}
		NewItem->next = nullptr;
		if (Head == nullptr) 
		{
			Head = NewItem;
		}
		else {
			train* Current = Head;
			for (int i = 1; i < Number && Current->next != nullptr; i++)
			{
				Current = Current->next;
			}
			if (Number == 0) {
				
				NewItem->next = Head;
				Head = NewItem;
			}
			else {
				if (Current->next != nullptr)
				{
					NewItem->next = Current->next;
				}
					
				Current->next = NewItem;
			}
		}
		return Head;
	}
	void Print(train* Head)
	{
		if (Head == nullptr)
		{
			cout << "List is empty!";
		}
		else
		{
			while (Head != nullptr)
			{
				cout << "Number" << "\t" << "Destination" << "\t" << "Arrival time" << "\t" << endl;
				cout << Head->number << "\t" << Head->name << "\t" << "\t" << Head->time << endl;
				Head = Head->next;
			}
		}
	}
	void Show(train* Head)
	{
		cout << "Number" << "\t" << "Destination" << "\t" << "Arrival time" << "\t" << endl;
		cout << Head->number << "\t" << Head->name << "\t" << Head->time << endl;
	}
	void Delete(train* Head)
	{
		if (Head != NULL)
		{
			Delete(Head->next);
			delete Head;
		}
	}
	void FindNameStation(train* Head)
	{
		train* ptr = Head;
		string name = "";
		cout << "Input station name: ";
		cin >> name;
		while (ptr != nullptr)
		{
			if (name == ptr->name)
			{
				Show(ptr);
				return;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		cout << "No such station was found" << endl;
	}
	void FindNumber(train* Head) {
		train* ptr;
		ptr = Head;
		int NumberItem = 0;
		cout << "Input train's number: ";
		cin >> NumberItem;
		while (ptr != NULL)
		{
			if (NumberItem == ptr->number)
			{
				Show(ptr);
				return;
			}
			else ptr = ptr->next;
		}
		cout << "No such train was found" << endl;
	}
	void FindTime(train* Head)
	{
		train* ptr;
		ptr = Head;
		string Name = "";
		cout << "Input station's name: ";
		cin >> Name;
		while (ptr != nullptr)
		{
			if (Name == ptr->name)
			{
				Show(ptr);
				return;
			}
			else ptr = ptr->next;
		}
		cout << "No such station was found" << endl;
	}
};


int main()
{
	TrainHub tr;
	train* Head = nullptr;
	int n = 1;
	int d;
	do {

		cout << "1 - Add train info to DB" << endl;
		cout << "2 - Show DB" << endl;
		cout << "3 - Show info about train for number" << endl;
		cout << "4 - Show info about train for name station" << endl;
		cout << "5 - Show info about train for time" << endl;
		cout << "6 - Exit!" << endl;
		cout << "Please select: ";
		cin >> d;
		switch (d)
		{
		case 1:
		{
			Head = tr.AddTrain(Head, n);
			n++;
		}break;
		case 2:
		{
			tr.Print(Head);
		}break;
		case 3:
		{
			tr.FindNumber(Head);
		}break;
		case 4:
		{
			tr.FindNameStation(Head);
		}break;
		case 5:
		{
			tr.FindTime(Head);
		}break;
		case 6:
		{
			cout << "Goodbye" << endl;
			tr.Delete(Head);
			exit(0);
		}break;

		default:
			cout << "Error" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (d != 5);

	return 0;
}