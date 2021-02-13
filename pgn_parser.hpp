#include<string>
#include<vector>
#include<fstream>

using namespace std;

class ChessGame
{
	public:
		//vector<pair<string, string>>colVal;
		vector<pair<size_t , pair<string, string>>>colVal;


		void display(vector<pair<string, string>>&temp)
		{	cout<<"display "<<"\n";
			for(int i = 0; i< temp.size(); ++i)
				cout<<temp[i].first<<" "<<temp[i].second<<"\n";
		}

};

class PgnReader
{

	size_t counter = 0;
	size_t  count = 0;
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
	counter = 0; 

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
					++count;
					g.colVal.clear();

				}
				if(tempHead == "Result")
					update = true;



				//cout<<counter<<" ";
				g.colVal.push_back(make_pair(count,  make_pair(tempHead, tempVal)));
				//cout<<g.colVal[counter].first<<" "<<colVal[counter].second<<"\n";

				//++counter;

				if(update)
					return g;
			}
		}
	}

}
