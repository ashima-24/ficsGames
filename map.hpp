#include <vector>
#include <iterator>

using namespace std;

class ColumnMap
{   
	
	public:
	vector<string>colHead;

	
	void update(ChessGame &g);
	
};
void ColumnMap::update(ChessGame &g)
{
	bool flag = false;
	map<string, string>::iterator it;

	for ( it = g.colVal.begin(); it != g.colVal.end(); ++it)
	{
		/* code */
		for(size_t j = 0; j< colHead.size(); ++j)
		{
			if (colHead[j] == it->first)
			{       flag = true;
				break;
			}
			else
				flag = false;

		}
		if (flag == false)
		{
			colHead.push_back(it->first);
		}
	}








}
