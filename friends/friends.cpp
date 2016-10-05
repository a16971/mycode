#include <tr1\unsorted_map>
#include <list>
using namespace std;

class Person
{
	list<int> friendIDs;
	int personID;
public:
	Person(int id):personID(id) {};
	int getID() { return personID; };
	void addFriend(int id) { frindIDs.push_back(id); };
};




	
