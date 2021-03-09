using namespace std;

class PgnReader
{

	ifstream inputFile;

public:
	PgnReader(const string filename)
		: inputFile()
	{
		inputFile.open(filename);
	}

	~PgnReader()
	{
		inputFile.close();
		cout << " pgn Input file close \n";
	}

	bool next(ChessGame &g);

	bool hasNext() const;
};

bool PgnReader::hasNext() const
{

	return (!(inputFile.eof()));
}

bool PgnReader::next(ChessGame &g)

{
	string line;

	string tempHead = "";
	string tempVal = "";

	bool update = false;

	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			size_t start = 0;

			if (line[start] == '[')
			{
				tempHead = "";
				tempVal = "";

				for (size_t start = 1; start < line.length(); ++start)
				{

					while (line[start] != ' ')
					{
						tempHead += line[start];
						++start;
					}
					++start;

					while (line[start] != ']')

					{
						tempVal += line[start];

						++start;
					}
					if (tempHead == "Event")
					{
						//g.mapValues().clear();
					}
					if (tempHead == "Result")
						update = true;

					g.addColumn(tempHead, tempVal);

					if (update)
						return true;

					break;
				}
			}
		}
	}

	else
	{
		return false;
	}
}
