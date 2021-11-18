#include <iostream>
#include <cmath>
#include "tree.h"
#include "LCAnaive.h"
#include "LCAsqrt.h"
#include "LCAbyRMQ.h"

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

	std::cout << "Using Naive: " << LCA_naive(tree, 6, 8);
	std::cout << "\nUsing SQRT decomposition: " << LCA_sqrt(tree, 6, 8);
	std::cout << "\nUsing RMQ with Segment Tree: " << LCA_by_RMQ(tree, 6, 8);

	return 0;
}
