#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	vector<string>colHead;
	vector<string>colVal;

	int countColHead  = 0;
	int counter = 0;

	string temp = "";
	//ifstream inputFile("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	ifstream inputFile("try.pgn");
	ofstream outFile("out.csv");

	if (inputFile.is_open()) 
	{
		string line;
		while (getline(inputFile, line)) 
		{
			
			int start = 0;

			if(line[start] == '[')
			{
				temp = "" ;	
				//countColHead = 0;

				for(int start = 1; line[start] != '\0'; ++start)
				{

					while(line[start] != ' ')

					{	
						temp += line[start];

						++start;

					}
					if(countColHead <=16)
					{
						colHead.push_back(temp);
					}
					++countColHead ;
					++start;
					temp = "" ;

					while(line[start] != ']')

					{	//cout<<line[start]<<" ";
						temp += line[start];

						++start;
					}
					colVal.push_back(temp);



				}
			}
		}

	}
	inputFile.close();

	for(int i = 0; i != colHead.size(); ++i)
	{
		//cout<<colHead[i]<<"\n";
		outFile<<colHead[i]<<',';
	}
	outFile<<"\n";
	for(int i = 0; i != colVal.size(); ++i)
	{
		//cout<<colVal[i]<<"\n";
		outFile<<colVal[i]<<',';
		++counter;
		if(counter == 17)
		{
			outFile<<"\n";
			counter = 0;
		}
	}


}

