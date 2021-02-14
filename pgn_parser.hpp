#include<string>
#include<vector>
#include<fstream>

using namespace std;

class ChessGame
{
	public:
		vector<pair<string, string>>colVal;
};

class PgnReader
{

	string tempHead = "";
	string tempVal = "";

	bool update  = false;

	ifstream inputFile;

public:
	PgnReader(const string filename)
		:	 inputFile() 
	{

		inputFile.open(filename);
	}

	ChessGame getCurrentGame();

	bool hasNext();

	ChessGame operator= (const PgnReader& p);
};

bool PgnReader:: hasNext()
{

	return (!(inputFile.eof()));
}

ChessGame PgnReader::  getCurrentGame()
{
	ChessGame g;
	string line;
	
	update = false;

	while (getline(inputFile, line)) 
	{
		size_t start = 0;
		
	if(line[start] == '[')
		{
			tempHead = "" ;	
			tempVal = "" ;

			for(size_t start = 1; start< line.length(); ++start)
			{ 
					
				while(line[start] != ' ')
				{	
					tempHead += line[start];
					++start;
				}
				++start;
				
				while(line[start] != ']')

				{
					tempVal += line[start];

					++start;
				}
				if(tempHead == "Event")
				{	 
					g.colVal.clear();

				}
				if(tempHead == "Result")
					update = true;
				
				g.colVal.push_back(make_pair(tempHead, tempVal));

				if(update)
					return g;

					break;
			}
		}
	}

}
