#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <iterator>

#include "chess.hpp"
#include "map.hpp"
#include "csv_file.hpp"
#include "pgn_parser.hpp"

using namespace std;

int main(int argc, char *argv[])

{
	/*  1. read pgn file file 
	 *  2.  output must be pgn type
	 *  3. Another object of pgn class to write to csv file
	 *  */

	if (argc < 2)

	{
		cerr << "Not enough arguments";
		return 1;
	}

	PgnReader pgnRead(argv[1]);
	FileWriter csvWrite(argv[2]);

	ColumnMap colMap;

	CsvStream cstream;

	/* key: column name,  value : csv col no 
	 *  max column value : 20 */

	while (pgnRead.hasNext())
	{
		ChessGame g;
		bool fileOpen = pgnRead.getCurrentGame(g);

		if (fileOpen)
		{

			colMap.update(g); // headers will be saved for that game

			colMap.mapping(g);

			cstream << g;
			csvWrite << cstream;
		}
		fileOpen = false;
		// depending upon the write col header, will write in csv the values
	}

	/* cstream << colMap;
			csvWrite << cstream; */
}