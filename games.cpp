#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>


using namespace std;

int main()
{
	vector<string>colHead;
	//vector<string>colVal;
	map<string, string>colVal;

	size_t countColHead  = 0;
	size_t counter = 0;

	string tempHead = "";
	string tempVal = "";

	bool flag = false;

	//ifstream inputFile("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	ifstream inputFile("test.pgn");
	//	ifstream inputFile("tail.pgn");
	ofstream outFile("out.csv" ,ios::app);

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


					++start;



					while(line[start] != ']')

					{	
						tempVal += line[start];

						++start;
					}
					colVal.insert(pair<string, string> (tempHead, tempVal));


					break;


				}
				flag = true;
			}
		}

	}
	inputFile.close();

	bool flag2 = false;

	for(size_t i = 0; i != colHead.size(); ++i)
	{
		cout<<colHead[i]<<"\n";
		outFile<<colHead[i]<<',';

	}
	outFile<<"\n";
	map<string, string>::iterator itr;

	for(itr = colVal.begin(); itr != colVal.end(); ++itr)
	{
		cout<<itr->first<<" "<<itr->second<<"\n";
	/*	for(size_t i = 0; i != colHead.size(); ++i)
		{
			if(colHead[i].compare(itr->first) == 0)
			{
				outFile<<itr->second<<',';
				break;
			}
			else
				flag2 = true;
		}*/
	}




}

