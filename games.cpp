#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	vector<char>colHead;
	vector<char>colVal;


	ifstream file("try.pgn");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			//cout<< line<<"\n";
			int start = 0;
			
			if(line[start] == '[')
			{	
				for(int start = 1; line[start] != '\0'; ++start)
				{

					while(line[start] != ' ')

					{
						colHead.push_back(line[start]);

						++start;

					}
					++start;	
					while(line[start] != ']')
					{

						colVal.push_back(line[start]);
					}



				}
			}
		}

		file.close();




	}
}
