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

	CsvStream &operator<<(const ColumnMap &m);

	CsvStream &operator<<( const CsvChessGame &g);

	//CsvStream& operator<< (const T& m);
	string str();
};

string CsvStream::str()
{
	return this->store;
}
CsvStream &CsvStream::operator<<(const ColumnMap &m)
{
	this->store = "";

	for (size_t i = 0; i < m.savedHeaders().size(); i++)
	{
		this->store += m.savedHeaders()[i];
		if (i < (m.savedHeaders().size() - 1))
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

 CsvStream &CsvStream::operator<<(const CsvChessGame &g)
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
class FileRead
{

	ifstream inputFile;

public:
	FileRead(const string filename)
		: inputFile()
	{
		inputFile.open(filename, ifstream::in);
	}
	~FileRead()
	{
		inputFile.close();
		cout << " file read Input file close \n";
	}
	bool hasNext();

	bool getCsvRows(CsvChessGame &g);
};
bool FileRead::hasNext()
{

	return (!(inputFile.eof()));
}

bool FileRead::getCsvRows(CsvChessGame &g)
{

	string line, word;

	if (inputFile.is_open())
	{

		while (getline(inputFile, line))
		{
			stringstream s(line);
			while (getline(s, word, ','))
			{
				g.retVal().push_back(word);
			}
			return true;
		}
	}
	else
	{
		return false;
	}
}