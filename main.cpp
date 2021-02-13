#include <iostream>
#include "pgn_parser.hpp"
#include "csv_file.hpp"
#include "map.hpp"

using namespace std;

int main()

{
	/*  1. read pgn file file 
	 *  2.  output must be png type
	 *  3. Another object of png class to write to csv file
	 *  */

	//PgnReader p("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	PgnReader p("dataset.pgn");

	CsvFileWriter c("out.csv");

	ColumnMap m;

	/* key: column name,  value : csv col no 
	 *  max column value : 20 */

 	while (p.hasNext())
	{
		ChessGame g = p.getCurrentGame();
		m.update(g);   // headers will be saved in m
		c.write(g, m); // depending upon the write col header, will write in csv the values
			//break;		   //ChessGame g2 = p.getCurrentGame();
	} 


}
