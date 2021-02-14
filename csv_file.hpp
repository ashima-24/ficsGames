#include<fstream>

using namespace std;

class CsvStream
{
	string store;
	const string separator;

	public: 

	CsvStream(const string sep = ",")
		: separator(sep)
		{

			
		}	

	CsvStream operator<< (const ChessGame& g);
	
	CsvStream operator<< (const ColumnMap& m);
	//CsvStream operator<< (const T& m);


};

CsvStream CsvStream::operator<<( const ColumnMap& m)
{
	CsvStream cs;

for (size_t i = 0; i < m.colHead.size() ; i++)
	{
		cs.store += m.colHead[i] ;
		cs.store += ",";
	}
	cs.store += "\n";
	cout<<cs.store;
	return cs;


}


class FileWriter
{
	ofstream outFile;
	

	public: 

	FileWriter(const string filename)
		: outFile()
		{

			outFile.open(filename, ofstream::app);
		}	

		~ FileWriter()
		{
			cout<<" Output file close";

			outFile.close();
		}

	FileWriter operator<<(const CsvStream &g);
	
		

};
/*  FileWriter FileWriter:: operator<<(const CsvStream &g)
{
	FileWriter fw;
	fw.outFile<<g;
	return fw;


}    */
/*  void CsvFileWriter:: headerWrite(ColumnMap &m)
{

	for (size_t i = 0; i < m.colHead.size() ; i++)
	{
		outFile<<m.colHead[i]<<",";
	}
	outFile<<"\n";

}
void CsvFileWriter:: write(ChessGame &g, ColumnMap &m)
{
	bool flag2 = false;
	size_t notNull = 0;

	 
	for(size_t j = 0; j <m.colHead.size(); ++j)
	{		
		for(size_t i = 0; i< g.colVal.size(); ++i)
		{
			if((m.colHead[j].compare(g.colVal[i].first) == 0))
			{
				outFile<<g.colVal[i].second<<",";
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

 */