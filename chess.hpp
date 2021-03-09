using namespace std;

class ChessGame
{
	map<string, string> colVal;

public:
	void addColumn(string header, string values);

	vector<string> getHeader();
	string getValues(string matchheader);
};

string ChessGame::getValues(string matchHeader)
{

	auto searchedVal = colVal.find(matchHeader);

	auto matchedValue = searchedVal->second;

	return matchedValue;
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