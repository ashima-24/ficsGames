#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<utility>


using namespace std;

vector<string>colHead;
vector<pair<size_t , pair<string, string>>>colVal;

size_t counter = 0;
vector<size_t> count;
string tempHead = "";
string tempVal = "";

bool flag = false;

ifstream inputFile("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
ifstream inputFile2("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
//ifstream inputFile("test.pgn");
//ifstream inputFile2("test.pgn");
//	ifstream inputFile("tail.pgn");
ofstream outFile("out.csv" ,ios::app);

void ficsGamesHeaders()
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
		outFile<<colHead[i]<<',';

	}
	outFile<<"\n";
}

void ficsGamesValues()
{
	bool flag2 = false;
	bool update = false;

	size_t counter = 0;

	vector<pair<size_t, string>>indivHead;
	if (inputFile2.is_open()) 
	{
		string line;
		while (getline(inputFile2, line)) 
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
						++counter;
						colVal.clear();
		
					}	

					colVal.push_back(make_pair(counter,  make_pair(tempHead, tempVal)));

					if(tempHead == "Result")
						update = true;
					if(update)
					{
						for(size_t k = counter; k<= counter; ++k)
						{
							for(size_t j = 0; j != colHead.size(); ++j)
							{
								for(size_t i = 0; i != colVal.size()  ; ++i)
								{
									if((colVal[i].first == k) && (colHead[j].compare(colVal[i].second.first) == 0))
									{
										outFile<<colVal[i].second.second<<',';
										flag2 = false;

										break;
									}
									else
									{
										flag2 = true;
									}

								}
								if(flag2)
								{
								
									outFile<<"null"<<",";
								}
							}
							if(true)
								outFile<<"\n";

						}
						update = false;
						//count.push_back(counter);
					}
					//colVal.insert(pair<string, string> (tempHead, tempVal));
					//colVal.push_back(make_pair(counter, tempHead ));

					break;

				}
				
			}
		}

	}
	inputFile2.close();

}
int main()
{
	ficsGamesHeaders();
	ficsGamesValues();

}

