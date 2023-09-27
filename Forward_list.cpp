#include <iostream>
using namespace std;

struct Element
{
	// Äàííûå
	char data;
	// Àäðåñ ñëåäóþùåãî ýëåìåíòà ñïèñêà
	Element *Next;
};

// Îäíîñâÿçíûé ñïèñîê
class List
{
	// Àäðåñ ãîëîâíîãî ýëåìåíòà ñïèñêà
	Element *Head;
	// Àäðåñ ãîëîâíîãî ýëåìåíòà ñïèñêà
	Element *Tail;
	// Êîëè÷åñòâî ýëåìåíòîâ ñïèñêà
	int Count;

public:
	// Êîíñòðóêòîð
	List();
	// Äåñòðóêòîð
	~List();

	// Äîáàâëåíèå ýëåìåíòà â ñïèñîê
	// (Íîâûé ýëåìåíò ñòàíîâèòñÿ ïîñëåäíèì)
	void Add(char data);

	// Óäàëåíèå ýëåìåíòà ñïèñêà
	// (Óäàëÿåòñÿ ãîëîâíîé ýëåìåíò)
	void Del();
	// Óäàëåíèå âñåãî ñïèñêà
	void DelAll();

	// Ðàñïå÷àòêà ñîäåðæèìîãî ñïèñêà
	// (Ðàñïå÷àòêà íà÷èíàåòñÿ ñ ãîëîâíîãî ýëåìåíòà)
	void Print();

	void DelPos(int i)
	{
		Element *temp = Head;
		while (i < 2)
		{
			temp = temp->Next;
			i--;
		}
		Element *del = temp->Next;
		temp->Next = del->Next;
		delete del;
	}

	// Ïîëó÷åíèå êîëè÷åñòâà ýëåìåíòîâ, íàõîäÿùèõñÿ â ñïèñêå
	int GetCount();

	void Paste(char s, int p);

	int Find(char data);
};

List::List()
{
	// Èçíà÷àëüíî ñïèñîê ïóñò
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Âûçîâ ôóíêöèè óäàëåíèÿ
	DelAll();
}

int List::GetCount()
{
	// Âîçâðàùàåì êîëè÷åñòâî ýëåìåíòîâ
	return Count;
}

void List::Add(char data)
{
	// ñîçäàíèå íîâîãî ýëåìåíòà
	Element *temp = new Element;

	// çàïîëíåíèå äàííûìè
	temp->data = data;
	// ñëåäóþùèé ýëåìåíò îòñóòñòâóåò
	temp->Next = NULL;
	// íîâûé ýëåìåíò ñòàíîâèòñÿ ïîñëåäíèì ýëåìåíòîì ñïèñêà
	// åñëè îí íå ïåðâûé äîáàâëåííûé
	if (Head != NULL)
	{
		Tail->Next = temp;
		Tail = temp;
	}
	// íîâûé ýëåìåíò ñòàíîâèòñÿ åäèíñòâåííûì
	// åñëè îí ïåðâûé äîáàâëåííûé
	else
	{
		Head = Tail = temp;
	}
}

void List::Del()
{
	// çàïîìèíàåì àäðåñ ãîëîâíîãî ýëåìåíòà
	Element *temp = Head;
	// ïåðåáðàñûâàåì ãîëîâó íà ñëåäóþùèé ýëåìåíò
	Head = Head->Next;
	// óäàëÿåì áûâøèé ãîëîâíîé ýëåìåíò
	delete temp;
}

void List::Paste(char a, int b)
{
	if (a < 0)
	{
		cout << "Error" << endl;
		return;
	}

	Element *new_node = new Element;
	new_node->data = b;

	if (a == 0)
	{
		new_node->Next = Head;
		Head = new_node;
		if (Tail == nullptr)
			Tail = new_node;
	}
	else
	{
		Element *node_pr = Head;
		for (int i = 0; i < a - 1 && node_pr != nullptr; i++)
		{
			node_pr = node_pr->Next;
		}

		if (node_pr != nullptr)
		{
			new_node->Next = node_pr->Next;
			node_pr->Next = new_node;
			if (node_pr == Tail)
				Tail = new_node;
		}
		else
		{

			if (Tail != nullptr)
			{
				Tail->Next = new_node;
				Tail = new_node;
			}
			else
			{
				Head = Tail = new_node;
			}
		}
	}
}

int List::Find(char d)
{
	int i = 0;
	Element *node_now = Head;

	while (node_now != nullptr)
	{
		if (node_now->data == d)
			return i;
		node_now = node_now->Next;
		i++;
	}

	return -1;
}

void List::DelAll()
{
	// Ïîêà åùå åñòü ýëåìåíòû
	while (Head != 0)
		// Óäàëÿåì ýëåìåíòû ïî îäíîìó
		Del();
}

void List::Print()
{
	// çàïîìèíàåì àäðåñ ãîëîâíîãî ýëåìåíòà
	Element *temp = Head;
	// Ïîêà åùå åñòü ýëåìåíòû
	while (temp != 0)
	{
		// Âûâîäèì äàííûå
		cout << temp->data << " ";
		// Ïåðåõîäèì íà ñëåäóþùèé ýëåìåíò
		temp = temp->Next;
	}

	cout << "\n\n";
}

int main()
{

	List lst;

	char s[] = "Hello, World !!!\n";

	for (int i = 0; s[i] != '\0'; i++)
		lst.Add(s[i]);

	lst.Print();

	lst.Paste('Y', 0);

	lst.Print();

	char symbol = 'W';
	int position = lst.Find(symbol);
	if (position != -1)
	{
		cout << "Element " << symbol << " finded: index " << position << endl;
	}
	else
	{
		cout << "Element " << symbol << " not found" << endl;
	}

	return 0;
}