#include <iostream>
#include "pgn_parser.hpp"
#include "map.hpp"
#include "csv_file.hpp"


using namespace std;

int main()

{
	/*  1. read pgn file file 
	 *  2.  output must be pgn type
	 *  3. Another object of pgn class to write to csv file
	 *  */

	//PgnReader p("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	//PgnReader p("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	PgnReader p("try.pgn");
	CsvFileWriter c("out.csv");
	

	ColumnMap m;

	ChessGame cg;

	/* key: column name,  value : csv col no 
	 *  max column value : 20 */
	int count =  0;

 	while (p.hasNext())
	{
		ChessGame g = p.getCurrentGame();
		m.update(g);   // headers will be saved in m
		c.write(g, m); // depending upon the write col header, will write in csv the values
					   //ChessGame g2 = p.getCurrentGame();
	} 
	


}
