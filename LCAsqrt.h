#pragma once

#include "tree.h"
#include "math.h"
#include "LCAnaive.h"

void MakeJumpAndBlock(Tree tree, int node, std::vector<int> Jump, std::vector<int> Block, int s, int h)
{
	Block[node] = h / s;

	if (Block[node] == 0)
		Jump[node] = 0;
	else
	{
		if (h % s == 0)
			Jump[node] = tree.GetParent(node);
		else
			Jump[node] = Jump[tree.GetParent(node)];
	}

	std::vector<int> childNode = tree.GetChildren(node);
	for (int i = 0; i < childNode.size(); ++i)
		MakeJumpAndBlock(tree, childNode[i], Jump, Block, s, h + 1);
}

int LCA_sqrt(Tree tree, int u, int v)
{
	int numNode = tree.GetNodeCount();
	std::vector<int> Block;
	Block.resize(numNode);
	std::vector<int> Jump;
	Jump.resize(numNode);
	int s = floor(sqrt(tree.GetTreeHeight()));

	MakeJumpAndBlock(tree, tree.GetRoot(), Jump, Block, s, 0);

	while (Jump[u] != Jump[v])
	{
		if (Block[u] < Block[v])
			v = Jump[v];
		else
			u = Jump[u];
	}

	return LCA_naive(tree, u, v);
}