#include<fstream>
//#include "map.hpp"
using namespace std;

class CsvFileWriter
{
	ofstream outFile;
	const string separator;
	


	public: 
	
	CsvFileWriter(const string filename, const string sep = ",")
			: outFile(), separator(sep)
			{
			
				outFile.open(filename, ofstream::app);
			}	
			
	ChessGame operator<< (const ChessGame& g);
	
	void write(ChessGame &g, ColumnMap &m);

};

void CsvFileWriter:: write(ChessGame &g, ColumnMap &m)
{
		bool flag2 = false;
		size_t notNull = 0;

	 	for(size_t k  = 0; k != m.colHead.size(); ++k)
		{
			//	outFile<<m.colHead[k]<<",";
			if(m.colHead[k].compare("null") != 0)
				++notNull;


		}
		//outFile<<"\n";
	for(size_t j = 0; j <m.colHead.size(); ++j)
 {		
		for(size_t i = 0; i< g.colVal.size(); ++i)
		{
			if((m.colHead[j].compare(g.colVal[i].second.first) == 0))
			{
			outFile<<g.colVal[i].second.second<<",";
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
 	{
	 outFile<<"\n";

	}
}

