#pragma once
#include "node.h"
#include <fstream>
class List
{
public:
	node *head;
	int size;
	List(string);
	void push(char, int);
	void addhead(node*);
	void addtotail(node*);
	void addafter(node*, node*);
	void addfront(node *,node*);
	node* find(char);
	void print();
	void sort();
	node* find_pr(node*);
	~List();
};

