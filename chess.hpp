using namespace std;

class ChessGame
{
	map<string, string> colVal;
	vector<string> columnValues;

public:
	void addColumn(string header, string values);
	vector<string> getHeader();
	vector<string> getValues();
	vector<string> &retVal();
};

vector<string> &ChessGame::retVal()
{
	return columnValues;
}
vector<string> ChessGame::getValues()
{

	vector<string> values;
	map<string, string>::iterator itr;

	for (itr = this->colVal.begin(); itr != this->colVal.end(); ++itr)
	{
		values.push_back(itr->second);
	}
	return values;
}
void ChessGame::addColumn(string header, string values)
{
	this->colVal.insert(make_pair(header, values));
}
vector<string> ChessGame::getHeader()
{
	vector<string> headers;
	map<string, string>::iterator itr;

	for (itr = this->colVal.begin(); itr != this->colVal.end(); ++itr)
	{
		headers.push_back(itr->first);
	}
	return headers;
}