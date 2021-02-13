#include<fstream>
//#include "map.hpp"
using namespace std;

class CsvFileWriter
{
	ofstream outFile;
	const string separator;

	public: CsvFileWriter(const string filename, const string sep = ",")
			: outFile(), separator(sep)
			{
			
				outFile.open(filename, ofstream::app);
			}	
	void write(ChessGame g, ColumnMap m);
};


