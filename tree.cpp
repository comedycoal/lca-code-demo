#include "tree.h"

int Tree::GetRoot()
{
	return this->c_root;
}

int Tree::GetParent(int node)
{
	return this->m_pparent[node];
}

int Tree::GetHeight(int node)
{
	return this->m_pheight[node];
}

std::vector<int> Tree::GetChildren(int node)
{
	std::vector<int> copy = this->m_pchildren[node];
	return copy;
}

std::vector<int> Tree::GetNodesOfHeight(int height)
{
	std::vector<int> res = std::vector<int>();
	for (int i = 0; i < this->m_count; ++i)
	{
		if (this->m_pheight[i] == height)
			res.push_back(i);
	}
	return res;
}

int Tree::AddChildNode(int parent)
{
	int newNodeIdx = (this->m_count)++;
	m_pchildren.push_back(std::vector<int>());
	m_pparent.push_back(parent);
	m_pheight.push_back(this->GetHeight(parent) + 1);
	m_pchildren[parent].push_back(newNodeIdx);

	if (m_pheight[newNodeIdx] > m_largestHeight)
		m_largestHeight = m_pheight[newNodeIdx];

	return newNodeIdx;
}