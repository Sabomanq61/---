#pragma once
#include "setsim.h"
class node
{
public:
	int freq;
	setsim t;
	node *next;
	node *right, *left;
	friend class List;
	node(char,int,node *_n = nullptr,node *l = nullptr,node *r = nullptr);
	node(setsim, int, node *, node *,node *);
	~node();
};

