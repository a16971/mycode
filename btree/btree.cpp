#include <stdio.h>
#include <iostream>
#include <stack> 

using namespace std;


class BTreeNode
{
private: 
	int m_data;
	BTreeNode * m_left;
	BTreeNode * m_right;

public:
	BTreeNode()
	{
	
	}
	

	BTreeNode(int data, BTreeNode* left, BTreeNode* right):m_data(data),m_left(left),m_right(right)
	{

	}
 
	int getData()const
	{
		return m_data;
	}
	
	BTreeNode* getLeft() const
	{
		return m_left;
	}

	BTreeNode* getRight() const
	{
		return m_right;
	}
	
	void  setData(int data)
	{
		m_data = data;
	}

	void setLeft(BTreeNode* node)
	{
		m_left = node;
	}

	void setRight(BTreeNode* node)
	{
		m_right = node;

	}	
};  
	
void LMR(BTreeNode* root)
{

	if(NULL == root) return;

	LMR(root->getLeft());
	std::cout << root->getData() << std::endl;
	LMR(root->getRight());
}

void MLR_none_recursive(BTreeNode* root)
{
	std::stack<BTreeNode*> my_stack;

	if(!root) return;
	
	cout << "MRL tranverse none recursive" << endl;

	my_stack.push(root);

	while(!my_stack.empty())
	{
		BTreeNode* topNode = my_stack.top();
		
		my_stack.pop();
	
		std::cout << topNode->getData() << std::endl;
	
		if(topNode->getRight() != NULL)
			my_stack.push(topNode->getRight());

		if(topNode->getLeft() != NULL)
			my_stack.push(topNode->getLeft());
	}
				

}

void LMR_none_recursive(BTreeNode* root)
{

	std::stack<BTreeNode*> my_stack;

	if(!root) return;
	
	cout << "LMR tranvers none recuresive" << endl;

	while(root != NULL || !my_stack.empty())
	{
		if(root != NULL)
		{
			my_stack.push(root);
			root = root->getLeft();
		}
		else 
		{
			root = my_stack.top();
			cout << root->getData() << endl;
			my_stack.pop();
			root = root->getRight();
		}
	}	
}			

void destroyTree(BTreeNode* root)
{
	if(NULL == root) return;
	cout << "destroy the btree" << endl;
	destroyTree(root->getLeft());
	destroyTree(root->getRight());
		std::cout << "node:" << root->getData() << std::endl;
		 delete root;
}

int max(int a, int b)
{
	return a > b? a:b;
}

int BTreeDepth(BTreeNode* root)
{
	if(root == NULL) return 0;
	
	if(root->getLeft() == NULL && root->getRight() == NULL)
		return 1;
	else
		return 1 + max(BTreeDepth(root->getLeft()), BTreeDepth(root->getRight()));
}	
	
void revertBTree(BTreeNode* root)
{
	if(!root) return;

	int temp;
	if(root->getLeft() && root->getRight())
	{
		temp = root->getLeft()->getData();
		root->getLeft()->setData(root->getRight()->getData());
		root->getRight()->setData(temp);
	}

	revertBTree(root->getLeft());
	revertBTree(root->getRight());

}
		

int main(void)
{
	BTreeNode* node_9 = new BTreeNode(9, NULL, NULL);
	BTreeNode* node_8 = new BTreeNode(8, node_9, NULL);
	BTreeNode* node_3 = new BTreeNode(3, NULL, node_8);
	BTreeNode* node_4 = new BTreeNode(4, NULL, NULL);
	BTreeNode* node_5 = new BTreeNode(5, NULL, NULL);
	BTreeNode* node_6 = new BTreeNode(6, NULL, NULL);
	BTreeNode* node_2 = new BTreeNode(2, node_5, node_6);
	BTreeNode* node_1 = new BTreeNode(1, node_3, node_4);
	
	BTreeNode* root = new BTreeNode(0, node_1, node_2 );
	
	revertBTree(root);
	LMR(root);
	
//	MLR_none_recursive(root);	
	LMR_none_recursive(root);
	destroyTree(root);
	
	cout << "Depth of the BTree: " << BTreeDepth(root) << endl;
	cout << "bigger? 100 or 20: " << max (100, 20) << endl;
	
}	
