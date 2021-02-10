#include<fstream>

using namespace std;

class csvfile
{
	ofstream outFile;
	const string separator;

	public: csvfile(const string filename, const string sep = ",")
			: outFile(), separator(sep)
			{
			
				outFile.open(filename, ofstream::app);
			}	

};
