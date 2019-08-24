#include "List.h"

List::List(string name)
{
	ifstream f(name);
	char a;
	setsim temp;
	int TAB[256]{};
	while (f >> a)
	{
		if (!temp[int(a)])
		{
			temp.set1(int(a));
			TAB[int(a)] = 1;
		}
		else
		{
			TAB[int(a)]++;
		}
	}
	f.close();
	for (int i = 0; i < 256; i++)
	{
		if (TAB[i])
		{
			if (!head)
			{
				head = new node(char(i), TAB[i]);
				size = 1;
			}
			else if (head->freq > TAB[i])
			{
				node *temp = new node(char(i), TAB[i]);
				addhead(temp);
			}
			else
			{
				node *t = head->next;
				node *pr = head;
				while (t)
				{
					if (t->freq < TAB[i])
					{
						pr = t;
						t = t->next;
					}
					else break;
				}
				addafter(pr, new node(char(i), TAB[i]));
			}
		}
	}
}

void List::addtotail(node*s)
{
	if (!head)
		head = s;
	else
	{
		node *temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = s;
	}
}

void List::addafter(node*pr, node *t)
{
	t->next = pr->next;
	pr->next = t;
	size++;
}

void List::addfront(node *pr,node*t)
{
	if (pr == head)
		head = t;
	t->next = pr;
	size++;
}

node * List::find(char s)
{
	node *p = head;
	while (!p->t[int(s)])
	{
		p = p->next;
	}
	return p;
}

void List::print()
{
	node *temp = head;
	while (temp)
	{
		cout << temp->freq << " " << temp->t;
		temp = temp->next;
	}
}

void List::sort()
{
	node *temp = head;
	while (temp->freq > temp->next->freq)
	{
		head = temp->next;

	}
}

node * List::find_pr(node *t)
{
	node *pr = nullptr, *temp = head;
	while (temp != t)
	{
		pr = temp;
		temp = temp->next;
	}
	return pr;
}

void List::push(char a,int t)
{
	node *temp = new node(a,t);
	addfront(head, temp);
	size++;
}

void List::addhead(node *t)
{
	t->next = head;
	head = t;
	size++;
}


List::~List()
{
}
