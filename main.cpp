#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include <vector>

#include <iterator>

#include "chess.hpp"
#include "map.hpp"
#include "csv_chess_game.hpp"
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
	FileWriter csvWrite2("out2.csv");
	FileRead csvRead(argv[2]);

	ColumnMap colMap;

	CsvStream cstream, cstream2;

	/* key: column name,  value : csv col no 
	 *  max column value : 20 */

	while (pgnRead.hasNext())
	{
		ChessGame g;
		bool fileOpen = pgnRead.next(g);

		if (fileOpen)
		{

			colMap.update(g); // headers will be saved for that game

			CsvChessGame chess(g, colMap);

			cstream << chess;
			csvWrite << cstream;
		}

		// depending upon the write col header, will write in csv the values
	}
	cstream2 << colMap;
	csvWrite2 << cstream2;

	/* 		while (csvRead.hasNext())
	{
		
		CsvChessGame g;
		bool fileOpen = csvRead.getCsvRows(g);
		if (fileOpen)
		{
			cstream2 << g;
			csvWrite2 << cstream2;
			 cout<<"in"<<fileOpen<<"\n"; 
		}
	
	}    */
}
