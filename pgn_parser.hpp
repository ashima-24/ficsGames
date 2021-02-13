#include<string>
#include<vector>
#include<fstream>

using namespace std;

class ChessGame
{
public:
	vector<pair<string, string>>colVal;

 	void display(vector<pair<string, string>>&temp)
	 {	cout<<"display "<<"\n";
		 for(int i = 0; i< temp.size(); ++i)
	 		cout<<temp[i].first<<" "<<temp[i].second<<"\n";


 	}

};

class PgnReader
{
	  
	
	vector<string>colHead;
	vector<pair<string, string>>colVal;

	size_t counter = 0;
	vector<size_t> count;
	string tempHead = "";
	string tempVal = "";

	bool flag = false;

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
	return (!inputFile.eof());
}

ChessGame PgnReader::  getCurrentGame()
{
		ChessGame g;
		string line;
		counter = 0; 

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
					
					//cout<<counter<<" ";
					g.colVal.push_back(make_pair(tempHead, tempVal));
					//cout<<g.colVal[counter].first<<" "<<colVal[counter].second<<"\n";
					
					++counter;

					if(counter == 7)
						return g;
				}
			}
		}



}