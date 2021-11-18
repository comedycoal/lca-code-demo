#pragma once

#include "tree.h"
#include <iostream>

int LCA_naive(Tree tree, int u, int v)
{
	if (tree.GetHeight(u) > tree.GetHeight(v))
	{
		int tmp = u;
		u = v;
		v = tmp;
	}

	while (tree.GetHeight(u) < tree.GetHeight(v))
	{
		v = tree.GetParent(v);
	}

	while (u != v)
	{
		u = tree.GetParent(u);
		v = tree.GetParent(v);
	}

	return u;
}