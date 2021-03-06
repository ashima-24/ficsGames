using namespace std;

class CsvChessGame
{
private:
    vector<string> columnValues;

public:
    CsvChessGame(ChessGame &g, ColumnMap &m);
    vector<string> retVal() const;
    //vector<string> retVal();
};

vector<string> CsvChessGame::retVal() const
{
    return (columnValues);
}
CsvChessGame::CsvChessGame(ChessGame &g, ColumnMap &m)
{
    bool flag = false;
    size_t pos = 0;

    for (size_t i = 0; i < m.savedHeaders().size(); ++i)
    {

        for (size_t j = 0; j < g.getHeader().size(); ++j)
        {

            if ((m.savedHeaders()[i].compare(g.getHeader()[j]) == 0))
            {

                this->columnValues.push_back(g.getValues(g.getHeader()[j]));

                flag = false;

                break;
            }
            else
            {
                flag = true;
            }
        }
    }
}
