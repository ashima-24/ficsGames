#include <fstream>

using namespace std;

class CsvStream
{
	const string separator;
	string store;

public:
	CsvStream(const string sep = ",")
		: separator(sep)
	{
	}

	CsvStream &operator<<(ColumnMap &m);
	CsvStream &operator<<(ChessGame &g);

	//CsvStream& operator<< (const T& m);
	string str();
};

string CsvStream::str()
{
	return this->store;
}
CsvStream &CsvStream::operator<<(ColumnMap &m)
{
	this->store = "";

	for (size_t i = 0; i < m.saveHeaders().size(); i++)
	{
		this->store += m.saveHeaders()[i];
		if (i < (m.saveHeaders().size() - 1))
		{
			this->store += ",";
		}
		else
		{
			continue;
		}
	}

	return *this;
}

CsvStream &CsvStream::operator<<(ChessGame &g)
{
	this->store = "";

	for (size_t i = 0; i < g.retVal().size(); ++i)
	{

		this->store += g.retVal()[i];

		if (i < (g.retVal().size()) - 1)
		{
			this->store += ",";
		}
		else
		{
			continue;
		}
	}

	return *this;
}
class FileWriter
{
	ofstream outFile;

public:
	FileWriter(const string filename)
		: outFile()
	{

		outFile.open(filename, ofstream::app);
	}

	~FileWriter()
	{
		cout << " Output file close";

		outFile.close();
	}

	FileWriter &operator<<(CsvStream &g);
};
FileWriter &FileWriter::operator<<(CsvStream &g)
{

	this->outFile << g.str();
	this->outFile << "\n"; // new row for next game entries
	return *this;
}
