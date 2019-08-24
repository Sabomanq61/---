#include "node.h"



node::node(char a,int fr,node *_n,node *l,node *r)
{
	t = setsim(a);
	freq = fr;
	next = _n;
	left = l;
	right = r;
}

node::node(setsim t1, int fr, node *n, node *l, node *r)
{
	t = t1;
	freq = fr;
	next = n;
	left = l;
	right = r;
}


node::~node()
{
}
