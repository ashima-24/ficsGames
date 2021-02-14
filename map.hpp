#include <vector>

using namespace std;

class ColumnMap
{   
	bool flag = false;

	public:
	vector<string>colHead;

	
	void update(ChessGame &g);
	;
	/*ColumnMap()
	  {
	  colHead.assign(20, "null");

	  }*/


};
void ColumnMap::update(ChessGame &g)
{
	for (size_t i = 0; i < g.colVal.size(); ++i)
	{
		/* code */
		for(size_t j = 0; j< colHead.size(); ++j)
		{
			if (colHead[j] == g.colVal[i].first)
			{       flag = true;
				break;
			}
			else
				flag = false;

		}
		if (flag == false)
		{
			colHead.push_back(g.colVal[i].first);
		}
	}








}
