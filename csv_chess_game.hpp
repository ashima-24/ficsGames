using namespace std;

class CsvChessGame
{
private:
        vector<string> columnValues;
public:
    void mappingGame(ChessGame &g, ColumnMap &m);
    vector<string>& retVal();
};

 vector<string>& CsvChessGame::retVal()
{
	return columnValues;
} 
void CsvChessGame::mappingGame(ChessGame &g, ColumnMap &m)
{
    bool flag = false;

	for (size_t i = 0; i < m.savedHeaders().size(); ++i)
	{

		for (size_t j = 0; j < g.getHeader().size(); ++j)
		{

			if (( m.savedHeaders()[i].compare(g.getHeader()[j]) == 0))
			{
				this->columnValues.push_back(g.getValues()[j]);
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
			this->columnValues.push_back("null");
		}
	}

}

