using namespace std;

class ColumnMap
{
	vector<string> colHead;

public:
	void update(ChessGame &g);

	ColumnMap()
	{

		for (int i = 0; i < 30; ++i)
			;
		//fill(colHead.begin(), colHead.end(), "null");
	}

	vector<string> savedHeaders()const;
};

vector<string> ColumnMap::savedHeaders()const
{
	return colHead;
}
void ColumnMap::update(ChessGame &g)
{

	bool flag = false;

	vector<string> header;

	header = g.getHeader(); // to get headers for current game

	for (size_t i = 0; i < header.size(); ++i)
	{ //cout<<header[i]<<" ";

		for (size_t j = 0; j < this->colHead.size(); ++j)
		{
			if (this->colHead[j] == header[i])
			{
				flag = true;
				break;
			}
			else
				flag = false;
		}
		if (flag == false)
		{
			this->colHead.push_back(header[i]);
		}
	}
}
