#pragma once
#include "List.h"
class CodeTree
{
	node *root;
public:
	CodeTree(List&);
	void print(node*);
	void CodeFile(string, string);
	void decode(string,string);
	node* getroot()
	{
		return root;
	}
	void clear(node *);
	~CodeTree();
};

