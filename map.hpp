using namespace std;

class ColumnMap
{
	vector<string> colHead;

public:
	vector<string> &saveHeaders();

	void update(ChessGame &g);

	void mapping(ChessGame &g);
};

void ColumnMap::mapping(ChessGame &g)
{
	bool flag = false;

	for (size_t i = 0; i < this->saveHeaders().size(); ++i)
	{

		for (size_t j = 0; j < g.getHeader().size(); j++)
		{

			if ((this->saveHeaders()[i].compare(g.getHeader()[j]) == 0))
			{
				g.retVal().push_back(g.getValues()[j]);
				flag = false;

				break;
			}
			else
			{
				flag = true;
			}
		}
		if (flag)
		{
			g.retVal().push_back("null");
		}
	}
}
vector<string> &ColumnMap::saveHeaders()
{
	return this->colHead;
}

void ColumnMap::update(ChessGame &g)
{
	bool flag = false;

	vector<string> header;

	header = g.getHeader(); // to get headers for current game

	for (size_t i = 0; i < header.size(); ++i)
	{ //cout<<header[i]<<" ";

		for (size_t j = 0; j < this->saveHeaders().size(); ++j)
		{
			if (this->saveHeaders()[j] == header[i])
			{
				flag = true;
				break;
			}
			else
				flag = false;
		}
		if (flag == false)
		{
			this->saveHeaders().push_back(header[i]);
		}
	}
}
