#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef char Info;

struct Elem
{
	Elem *link;
	Info info;
};

void Push(Elem *&top, const Info value);

void ReadFromFile(Elem *&top, const string &filename)
throw (invalid_argument);

void Initialize(Elem *&top);

Info Pop(Elem *&top);

void Sort(Elem *&top, Elem *&sorted);

Info FindMin(Elem *&top);

size_t Count(Elem *top);

void Print(Elem *top);

int main()
{
	Elem *top = NULL, *sorted = NULL;

	string filename;
	char choice;

	do
	{
		cout << "What do you wish to do?\n[1] - Initialize a stack\n[2] - Read stack from a file\n[3] - Print the stack\n[4] - Sort the stack\n[5] - Show the result\n\n[0] - Exit the program\n";
		cin >> choice;
		
		switch (choice)
		{
		case '1':
			while (top)
			{
				Pop(top);
			}

			Initialize(top);

			break;
		case '2':
			while (top)
			{
				Pop(top);
			}

			cout << "File's name : ";
			cin >> filename;

			ReadFromFile(top, filename);

			break;
		case '3':
			Print(top);

			break;
		case '4':
			while (sorted)
			{
				Pop(sorted);
			}

			Sort(top, sorted);

			break;
		case '5':
			Print(sorted);

			break;
		case '0':
			break;
		default:
			cerr << "Invalid option selected.\n\n";

			break;
		}
	} while (choice != '0');


	return 0;
}

void Initialize(Elem *&top)
{
	size_t count;
	Info info;

	cout << "Count = ";
	cin >> count;

	for (size_t elem = 0; elem < count; elem++)
	{
		cout << "Info = ";
		cin >> info;
		
		Push(top, info);
	}
}

void Push(Elem *&top, const Info value)
{
	Elem *tmp = new Elem;

	tmp->info = value;
	tmp->link = top;

	top = tmp;
}

Info Pop(Elem *&top)
{
	Elem *tmp = top->link;
	Info value = top->info;

	delete top;

	top = tmp;

	return value;
}

void ReadFromFile(Elem *&top, const string &filename)
throw (invalid_argument)
{
	ifstream read(filename);

	if (!read)
	{
		throw invalid_argument("Could not open \"" + filename + "\"");
	}

	Info value;

	while (read >> value)
	{
		Push(top, value);
	}
}

void Sort(Elem *&top, Elem *&sorted)
{
	size_t size = Count(top);

	for (size_t elem = 0; elem < size; elem++)
	{
		Push(sorted, FindMin(top));
	}
}

Info FindMin(Elem *&top)
{
	if (top == NULL)
		throw invalid_argument("top pointer is NULL");
	
	for (; top && top->info == ' ';)
	{
		Pop(top);
	}

	if (!top)
		return ' ';

	Elem *tmp = top;
	Elem *min = top;

	for (; tmp; tmp = tmp->link)
	{
		if (min->info > tmp->info && tmp->info != ' ')
		{
			min = tmp;
		}
	}

	Info min_info = min->info;
	min->info = ' ';

	return min_info;
}

size_t Count(Elem *top)
{
	size_t count = 0;

	for (; top; top = top->link, count++);

	return count;
}

void Print(Elem *top)
{
	for (; top; top = top->link)
	{
		cout << top->info << ' ';
	}

	cout << endl;
}