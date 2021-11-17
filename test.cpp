#include <iostream>
#include "tree.h"

void Print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
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