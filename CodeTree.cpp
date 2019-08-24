#include "CodeTree.h"



CodeTree::CodeTree(List &sp)
{
	for (node *t1 = sp.head, *t2 = t1->next; t2; t1 = sp.head, t2 = t1->next)
	{
		node *temp = new node(t1->t + t2->t, t1->freq + t2->freq, nullptr, t1, t2);
		node *t3 = t2, *t4 = t2->next;
		if (!t4)
		{
			sp.head = temp;
		}
		else
		{
			sp.head = t4;
			if (t4->freq > temp->freq)
			{
				sp.addhead(temp);
			}
			else
			{
				while (t4->next && t4->freq < temp->freq)
				{
					t3 = t4;
					t4 = t4->next;
				}
				if (!t4->next && t4->freq < temp->freq)
				{
					sp.addtotail(temp);
				}
				else
				{
					t3->next = temp;
					temp->next = t4;
				}
			}
		}
	}
	root = sp.head;
}

void CodeTree::print(node*t)
{	
	cout << t->freq << " " << t->t;
	if (t->right)
		print(t->right);
	if (t->left)
		print(t->left);
}

void CodeTree::CodeFile(string name, string cod)
{
	ifstream file(name);
	ofstream f_code(cod);
	f_code.clear();
	char s;
	while (file >> s)
	{
		for (node *temp = root; temp->left && temp->left;)
		{
			if (temp->left->t[int(s)])
			{
				temp = temp->left;
				f_code << '0';
			}
			else
			{
				temp = temp->right;
				f_code << '1';
			}
		}
	}
	f_code.close();
	file.close();
}

void CodeTree::decode(string name,string n)
{
	ifstream file(name);
	ofstream f(n);
	char t;
	node *temp = root;
	while (!file.eof())
	{
		if (!temp->right && !temp->left)
		{
			f << temp->t.symbol();
			temp = root;
		}
		file >> t;
		if (t == '0')
			temp = temp->left;
		if(t == '1')
			temp = temp->right;
	}
	file.close();
	f.close();
}


void CodeTree::clear(node *t)
{
	if (t->left)
		clear(t->left);
	if (t->right)
		clear(t->right);
	delete t;
}

CodeTree::~CodeTree()
{
	clear(root);
}
