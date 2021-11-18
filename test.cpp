#include <iostream>
#include <cmath>
#include "tree.h"

void Print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
}

int LCA_naive(Tree tree, int u, int v)
{
	if(tree.GetHeight(u) < tree.GetHeight(v))
	{
		int tmp = u;
		u = v;
		v = tmp;
	}

	while(tree.GetHeight(u) >tree.GetHeight(v))
		v = tree.GetParent(v);

	while(u != v)
	{
		u = tree.GetParent(u);
		v = tree.GetParent(v);
	}

	return u;
}

void MakeJumpAndBlock(Tree tree, int node, std::vector<int> Jump, std::vector<int> Block, int s, int h)
{
	Block[node] = h/s;

	if (Block[node] == 0)
		Jump[node] = 0;
	else {
		if (h % s == 0)
			Jump[node] = tree.GetParent(node);
		else
			Jump[node] = Jump[tree.GetParent(node)];
	}

	std::vector<int>childNode = tree.GetChildren(node);
	for (int i = 0; i < childNode.size(); ++i)
		MakeJumpAndBlock(tree, childNode[i], Jump, Block, s, h + 1);
}

int LCA_sqrt(Tree tree, int u, int v)
{
	int numNode = tree.GetNodeCount();
	std:: vector<int> Block;
	Block.resize(numNode);
	std:: vector<int> Jump;
	Jump.resize(numNode);
	int s = floor(sqrt(tree.GetTreeHeight()));

	MakeJumpAndBlock(tree, tree.GetRoot(), Jump, Block, s, 0);

	while (Jump[u] != Jump[v]){
		if (Block[u] < Block[v])
			v = Jump[v];
		else
			u = Jump[u];
	}

	return LCA_naive(tree, u, v);
}


int main()
{
	Tree tree = Tree();
	tree.AddChildNode(0);
	tree.AddChildNode(0);
	tree.AddChildNode(1);
	tree.AddChildNode(2);
	tree.AddChildNode(2);
	tree.AddChildNode(2);
	tree.AddChildNode(3);
	tree.AddChildNode(4);
	tree.AddChildNode(4);
	tree.AddChildNode(5);
	tree.AddChildNode(6);
	tree.AddChildNode(7);
	tree.AddChildNode(7);
	tree.AddChildNode(11);
	tree.AddChildNode(11);

	std::cout << "Nodes: " << tree.GetNodeCount()
			  << "\nHeight: " << tree.GetTreeHeight();

	for (int i = 0; i < tree.GetTreeHeight(); ++i)
	{
		std::cout << "\nHeight " << i << ": ";
		Print(tree.GetNodesOfHeight(i));
	}

	for (int i = 0; i < tree.GetNodeCount(); ++i)
	{
		std::cout << "\nChildren of " << i << ": ";
		std::vector<int> c = tree.GetChildren(i);
		if (c.size() == 0)
			std::cout << "None";
		else
			Print(c);
	}

	std::cout << "\nRan successfully";
	return 0;
}