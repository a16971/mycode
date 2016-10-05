#include <tr1/unordered_map>
#include <iostream> 
#include <vector> 
using namespace std;

struct UndirectedGraphNode{
	int label; 
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x): label(x){};
};

class Solution{
private:
	std::tr1::unordered_map<UndirectedGraphNode*,  UndirectedGraphNode*> NodeHash;

public: 
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
	{
		if(!node) return NULL;

		if(NodeHash.find(node) == NodeHash.end())
		{	
			NodeHash[node] = new UndirectedGraphNode(node->label);

			for(vector<UndirectedGraphNode*>::iterator it = (node->neighbors).begin(); it != (node->neighbors).end(); ++it)
				(NodeHash[node]->neighbors).push_back(cloneGraph(*it));
		}
		
		return NodeHash[node];
	}	
};
