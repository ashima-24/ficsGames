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
		cout << " Input file close";
	}

	bool getCurrentGame(ChessGame &g);

	bool hasNext();
};

bool PgnReader::hasNext()
{

	return (!(inputFile.eof()));
}

bool PgnReader::getCurrentGame(ChessGame &g)

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
