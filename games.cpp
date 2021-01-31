#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>
#include<utility>


using namespace std;

int main()
{
	vector<string>colHead;
	
	vector<pair<size_t , pair<string, string>>>colVal;
	//vector<pair<string, string>>colVal;
	//map<string, string>colVal;

	size_t counter = 0;
	vector<size_t> count;

	string tempHead = "";
	string tempVal = "";

	bool flag = false;

//	ifstream inputFile("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
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

					//colVal.insert(pair<string, string> (tempHead, tempVal));
					colVal.push_back(make_pair(counter,  make_pair(tempHead, tempVal)));
					//colVal.push_back(make_pair(tempHead, tempVal));

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

for(size_t k = 1; k<= count.size(); ++k)
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
			//cout<<"here";
		outFile<<"null"<<",";
		}
	}
	if(true)
	outFile<<"\n";

}


}

