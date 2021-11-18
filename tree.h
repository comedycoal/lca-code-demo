#pragma once

#include <stdexcept>
#include <vector>

// Class Tree implements 
class Tree
{
private:
	const int c_root;
	int m_capacity;
	int m_count;
	int m_largestHeight;

	std::vector<std::vector<int>> m_pchildren;
	std::vector<int> m_pparent;
	std::vector<int> m_pheight;

public:
	Tree() : c_root(0)
	{
		m_pchildren = std::vector<std::vector<int>>();
		m_pparent = std::vector<int>();
		m_pheight = std::vector<int>();

		m_count = 1;
		m_pchildren.push_back(std::vector<int>());
		m_pparent.push_back(-1);
		m_pheight.push_back(0);
		m_largestHeight = 0;
	}

	~Tree() {}

public:
	int GetRoot();
	int GetParent(int node);
	int GetHeight(int node);
	int GetTreeHeight() { return m_largestHeight + 1; }
	int GetNodeCount() { return m_count; }
	std::vector<int> GetChildren(int node);
	std::vector<int> GetNodesOfHeight(int height);
	void PrintInfo();

	int AddChildNode(int parent);
};