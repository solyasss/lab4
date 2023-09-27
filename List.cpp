#include <iostream>
using namespace std;

struct Elem
{
    int data; // äàííûå
    Elem* next, * prev;
};

class List
{
    // Ãîëîâà, õâîñò
    Elem* Head, * Tail;
    // Êîëè÷åñòâî ýëåìåíòîâ
    int Count;

public:

    // Êîíñòðóêòîð
    List();
    // Êîíñòðóêòîð êîïèðîâàíèÿ
    List(const List&);
    // Äåñòðóêòîð
    ~List();

    // Ïîëó÷èòü êîëè÷åñòâî
    int GetCount();
    // Ïîëó÷èòü ýëåìåíò ñïèñêà
    Elem* GetElem(int);

    // Óäàëèòü âåñü ñïèñîê
    void DelAll();
    // Óäàëåíèå ýëåìåíòà, åñëè ïàðàìåòð íå óêàçûâàåòñÿ,
    // òî ôóíêöèÿ åãî çàïðàøèâàåò
    void Del(int pos = 0);
    // Âñòàâêà ýëåìåíòà, åñëè ïàðàìåòð íå óêàçûâàåòñÿ,
    // òî ôóíêöèÿ åãî çàïðàøèâàåò
    void Insert(int pos = 0);

    // Äîáàâëåíèå â êîíåö ñïèñêà
    void AddTail(int n);

    // Äîáàâëåíèå â íà÷àëî ñïèñêà
    void AddHead(int n);

    // Ïå÷àòü ñïèñêà
    void Print();
    // Ïå÷àòü îïðåäåëåííîãî ýëåìåíòà
    void Print(int pos);

    List& operator = (const List&);
    // ñëîæåíèå äâóõ ñïèñêîâ (äîïèñûâàíèå)
    List operator + (const List&);

    // ñðàâíåíèå ïî ýëåìåíòàì
    bool operator == (const List&);
    bool operator != (const List&);
    bool operator <= (const List&);
    bool operator >= (const List&);
    bool operator < (const List&);
    bool operator > (const List&);

    // ïåðåâîðà÷èâàíèå ñïèñêà
    List operator - ();
};

List::List()
{
    // Èçíà÷àëüíî ñïèñîê ïóñò
    Head = Tail = NULL;
    Count = 0;
}

List::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;

    // Ãîëîâà ñïèñêà, èç êîòîðîãî êîïèðóåì
    Elem* temp = L.Head;
    // Ïîêà íå êîíåö ñïèñêà
    while (temp != 0)
    {
        // Ïåðåäèðàåì äàííûå
        AddTail(temp->data);
        temp = temp->next;
    }
}

List::~List()
{
    // Óäàëÿåì âñå ýëåìåíòû
    DelAll();
}

void List::AddHead(int n)
{
    // íîâûé ýëåìåíò
    Elem* temp = new Elem;

    // Ïðåäûäóùåãî íåò
    temp->prev = 0;
    // Çàïîëíÿåì äàííûå
    temp->data = n;
    // Ñëåäóþùèé - áûâøàÿ ãîëîâà
    temp->next = Head;

    // Åñëè ýëåìåíòû åñòü?
    if (Head != 0)
        Head->prev = temp;

    // Åñëè ýëåìåíò ïåðâûé, òî îí îäíîâðåìåííî è ãîëîâà è õâîñò
    if (Count == 0)
        Head = Tail = temp;
    else
        // èíà÷å íîâûé ýëåìåíò - ãîëîâíîé
        Head = temp;

    Count++;
}

void List::AddTail(int n)
{
    // Ñîçäàåì íîâûé ýëåìåíò
    Elem* temp = new Elem;
    // Ñëåäóþùåãî íåò
    temp->next = 0;
    // Çàïîëíÿåì äàííûå
    temp->data = n;
    // Ïðåäûäóùèé - áûâøèé õâîñò
    temp->prev = Tail;

    // Åñëè ýëåìåíòû åñòü?
    if (Tail != 0)
        Tail->next = temp;

    // Åñëè ýëåìåíò ïåðâûé, òî îí îäíîâðåìåííî è ãîëîâà è õâîñò
    if (Count == 0)
        Head = Tail = temp;
    else
        // èíà÷å íîâûé ýëåìåíò - õâîñòîâîé
        Tail = temp;

    Count++;
}

void List::Insert(int pos)
{
    // åñëè ïàðàìåòð îòñóòñòâóåò èëè ðàâåí 0, òî çàïðàøèâàåì åãî
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    // Ïîçèöèÿ îò 1 äî Count?
    if (pos < 1 || pos > Count + 1)
    {
        // Íåâåðíàÿ ïîçèöèÿ
        cout << "Incorrect position !!!\n";
        return;
    }

    // Åñëè âñòàâêà â êîíåö ñïèñêà
    if (pos == Count + 1)
    {
        // Âñòàâëÿåìûå äàííûå
        int data;
        cout << "Input new number: ";
        cin >> data;
        // Äîáàâëåíèå â êîíåö ñïèñêà
        AddTail(data);
        return;
    }
    else if (pos == 1)
    {
        // Âñòàâëÿåìûå äàííûå
        int data;
        cout << "Input new number: ";
        cin >> data;
        // Äîáàâëåíèå â íà÷àëî ñïèñêà
        AddHead(data);
        return;
    }

    // Ñ÷åò÷èê
    int i = 1;

    // Îòñ÷èòûâàåì îò ãîëîâû n - 1 ýëåìåíòîâ
    Elem* Ins = Head;

    while (i < pos)
    {
        // Äîõîäèì äî ýëåìåíòà, 
        // ïåðåä êîòîðûì âñòàâëÿåìñÿ
        Ins = Ins->next;
        i++;
    }

    // Äîõîäèì äî ýëåìåíòà, 
    // êîòîðûé ïðåäøåñòâóåò
    Elem* PrevIns = Ins->prev;

    // Ñîçäàåì íîâûé ýëåìåíò
    Elem* temp = new Elem;

    // Ââîäèì äàííûå
    cout << "Input new number: ";
    cin >> temp->data;

    // íàñòðîéêà ñâÿçåé
    if (PrevIns != 0 && Count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    Count++;
}

void List::Del(int pos)
{
    // åñëè ïàðàìåòð îòñóòñòâóåò èëè ðàâåí 0, òî çàïðàøèâàåì åãî
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }
    // Ïîçèöèÿ îò 1 äî Count?
    if (pos < 1 || pos > Count)
    {
        // Íåâåðíàÿ ïîçèöèÿ
        cout << "Incorrect position !!!\n";
        return;
    }

    // Ñ÷åò÷èê
    int i = 1;

    Elem* Del = Head;

    while (i < pos)
    {
        // Äîõîäèì äî ýëåìåíòà, 
        // êîòîðûé óäàëÿåòñÿ
        Del = Del->next;
        i++;
    }

    // Äîõîäèì äî ýëåìåíòà, 
    // êîòîðûé ïðåäøåñòâóåò óäàëÿåìîìó
    Elem* PrevDel = Del->prev;
    // Äîõîäèì äî ýëåìåíòà, êîòîðûé ñëåäóåò çà óäàëÿåìûì
    Elem* AfterDel = Del->next;

    // Åñëè óäàëÿåì íå ãîëîâó
    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;
    // Åñëè óäàëÿåì íå õâîñò
    if (AfterDel != 0 && Count != 1)
        AfterDel->prev = PrevDel;

    // Óäàëÿþòñÿ êðàéíèå?
    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    // Óäàëåíèå ýëåìåíòà
    delete Del;

    Count--;
}

void List::Print(int pos)
{
    // Ïîçèöèÿ îò 1 äî Count?
    if (pos < 1 || pos > Count)
    {
        // Íåâåðíàÿ ïîçèöèÿ
        cout << "Incorrect position !!!\n";
        return;
    }

    Elem* temp;

    // Îïðåäåëÿåì ñ êàêîé ñòîðîíû 
    // áûñòðåå äâèãàòüñÿ
    if (pos <= Count / 2)
    {
        // Îòñ÷åò ñ ãîëîâû
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            // Äâèãàåìñÿ äî íóæíîãî ýëåìåíòà
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // Îòñ÷åò ñ õâîñòà
        temp = Tail;
        int i = 1;

        while (i <= Count - pos)
        {
            // Äâèãàåìñÿ äî íóæíîãî ýëåìåíòà
            temp = temp->prev;
            i++;
        }
    }
    // Âûâîä ýëåìåíòà
    cout << pos << " element: ";
    cout << temp->data << endl;
}

void List::Print()
{
    // Åñëè â ñïèñêå ïðèñóòñòâóþò ýëåìåíòû, òî ïðîáåãàåì ïî íåìó
    // è ïå÷àòàåì ýëåìåíòû, íà÷èíàÿ ñ ãîëîâíîãî
    if (Count != 0)
    {
        Elem* temp = Head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

void List::DelAll()
{
    // Ïîêà îñòàþòñÿ ýëåìåíòû, óäàëÿåì ïî îäíîìó ñ ãîëîâû
    while (Count != 0)
        Del(1);
}

int List::GetCount()
{
    return Count;
}

Elem* List::GetElem(int pos)
{
    Elem* temp = Head;

    // Ïîçèöèÿ îò 1 äî Count?
    if (pos < 1 || pos > Count)
    {
        // Íåâåðíàÿ ïîçèöèÿ
        cout << "Incorrect position !!!\n";
        return 0;
    }

    int i = 1;
    // Èùåì íóæíûé íàì ýëåìåíò
    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp;
}

List& List::operator = (const List& L)
{
    // Ïðîâåðêà ïðèñâàèâàíèÿ ýëåìåíòà "ñàìîìó ñåáå"
    if (this == &L)
        return *this;

    // óäàëåíèå ñòàðîãî ñïèñêà
    this->~List(); // DelAll();

    Elem* temp = L.Head;

    // Êîïèðóåì ýëåìåíòû
    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }

    return *this;
}
// ñëîæåíèå äâóõ ñïèñêîâ
List List::operator + (const List& L)
{
    // Çàíîñèì âî âðåìåííûé ñïèñîê ýëåìåíòû ïåðâîãî ñïèñêà
    List Result(*this);
    // List Result = *this;

    Elem* temp = L.Head;

    // Äîáàâëÿåì âî âðåìåííûé ñïèñîê ýëåìåíòû âòîðîãî ñïèñêà
    while (temp != 0)
    {
        Result.AddTail(temp->data);
        temp = temp->next;
    }

    return Result;
}

bool List::operator == (const List& L)
{
    // Ñðàâíåíèå ïî êîëè÷åñòâó
    if (Count != L.Count)
        return false;

    Elem* t1, * t2;

    t1 = Head;
    t2 = L.Head;

    // Ñðàâíåíèå ïî ñîäåðæàíèþ
    while (t1 != 0)
    {
        // Ñâåðÿåì äàííûå, êîòîðûå
        // íàõîäÿòñÿ íà îäèíàêîâûõ ïîçèöèÿõ
        if (t1->data != t2->data)
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}

bool List::operator != (const List& L)
{
    // Èñïîëüçóåì ïðåäûäóùóþ ôóíêöèþ ñðàâíåíèÿ
    return !(*this == L);
}

bool List::operator >= (const List& L)
{
    // Ñðàâíåíèå ïî êîëè÷åñòâó
    if (Count > L.Count)
        return true;
    // Ñðàâíåíèå ïî ñîäåðæàíèþ
    if (*this == L)
        return true;

    return false;
}

bool List::operator <= (const List& L)
{
    // Ñðàâíåíèå ïî êîëè÷åñòâó
    if (Count < L.Count)
        return true;
    // Ñðàâíåíèå ïî ñîäåðæàíèþ
    if (*this == L)
        return true;

    return false;
}

bool List::operator > (const List& L)
{
    if (Count > L.Count)
        return true;

    return false;
}

bool List::operator < (const List& L)
{
    if (Count < L.Count)
        return true;

    return false;
}

// ïåðåâîðîò
List List::operator - ()
{
    List Result;

    Elem* temp = Head;
    // Êîïèðóåì ýëåìåíòû ñïèñêà, íà÷èíàÿ ñ ãîëîâíîãî,
    // â ñâîé ïóòåì äîáàâëåíèÿ ýëåìåíòîâ â ãîëîâó,
    // òàêèì îáðàçîì âðåìåííûé ñïèñîê Result áóäåò ñîäåðæàòü
    // ýëåìåíòû â îáðàòíîì ïîðÿäêå
    while (temp != 0)
    {
        Result.AddHead(temp->data);
        temp = temp->next;
    }

    return Result;
}

// Òåñòîâûé ïðèìåð
void main()
{
    List L;

    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

    // Äîáàâëÿåì ýëåìåíòû, ñòîÿùèå íà ÷åòíûõ èíäåêñàõ, â ãîëîâó,
    // íà íå÷åòíûõ - â õâîñò
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            L.AddHead(a[i]);
        else
            L.AddTail(a[i]);

    // Ðàñïå÷àòêà ñïèñêà
    cout << "List L:\n";
    L.Print();

    cout << endl;

    // Âñòàâêà ýëåìåíòà â ñïèñîê
    L.Insert();
    // Ðàñïå÷àòêà ñïèñêà
    cout << "List L:\n";
    L.Print();

    // Ðàñïå÷àòêà 2-ãî è 8-ãî ýëåìåíòîâ ñïèñêà
    L.Print(2);
    L.Print(8);

    List T;

    // Êîïèðóåì ñïèñîê
    T = L;
    // Ðàñïå÷àòêà êîïèè
    cout << "List T:\n";
    T.Print();

    // Ñêëàäûâàåì äâà ñïèñêà (ïåðâûé â ïåðåâåðíóòîì ñîñòîÿíèè)
    cout << "List Sum:\n";
    List Sum = -L + T;
    // Ðàñïå÷àòêà ñïèñêà
    Sum.Print();
}