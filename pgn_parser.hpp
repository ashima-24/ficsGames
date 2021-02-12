#include<string>
#include<vector>
#include<fstream>


using namespace std;

class PgnReader
{
	vector<string>colHead;
	vector<pair<size_t , pair<string, string>>>colVal;

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
	
PgnReader& getCurrentGame();



};
