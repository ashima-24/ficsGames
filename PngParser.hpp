#include<string>
#include<vector>
#include<fstream>


using namespace std;

struct parser
{
	vector<string>colHead;
	vector<pair<size_t , pair<string, string>>>colVal;

	size_t counter = 0;
	vector<size_t> count;
	string tempHead = "";
	string tempVal = "";

	bool flag = false;
void ficsGamesHeaders(ifstream &inputFile);



};

void parser :: ficsGamesHeaders(ifstream & inputFile)
{
if (inputFile.is_open()) 
	{
		string line;
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
					if(flag == true)
					{
						for(size_t i = 0; i< colHead.size(); ++i )
						{
							if(tempHead == colHead[i])
							{
								flag = true;
								break;
							}
							else{
								flag = false;	
							}
						}
					}
					if(flag == false)
					{
						colHead.push_back(tempHead);
					}

					if(tempHead == "Event")
					{	
						++counter;
						count.push_back(counter);
					}
					++start;

					while(line[start] != ']')

					{	
						tempVal += line[start];

						++start;
					}


					break;
				}
				flag = true;
			}
		}

	}
	inputFile.close();

	for(size_t i = 0; i != colHead.size(); ++i)
        {
                cout<<colHead[i]<<"\n";
                //outFile<<colHead[i]<<',';

        }


}	
