#include <iostream>
#include"chess.hpp"
#include "map.hpp"
#include "csv_file.hpp"
#include "pgn_parser.hpp"


using namespace std;


int main(int argc, char* argv[])

{
	/*  1. read pgn file file 
	 *  2.  output must be pgn type
	 *  3. Another object of pgn class to write to csv file
	 *  */


	if (argc < 2)
	
	{
		cerr<<"Not enough arguments";
		return 1;
	}
	
	PgnReader p(argv[1]);
	PgnReader p2(argv[1]);
	FileWriter c(argv[2]);
	


	ColumnMap m;
	ChessGame g;
	CsvStream cs;

	/* key: column name,  value : csv col no 
	 *  max column value : 20 */

	while (p.hasNext())
	{
		bool fileOpen = p.getCurrentGame( g);
		if(fileOpen)
		{
			
			m.update(g); // headers will be saved in m
		}
		fileOpen = false;
		//c.write(g, m);  depending upon the write col header, will write in csv the values
	} 
	
	cs<<m; // headers stored in string
	// c<<cs;
	

	//c.headerWrite(m); 

	while (p2.hasNext())
	{
		bool fileOpen = p2.getCurrentGame( g);	
		if(fileOpen)
		{
			m.update(g);
			  
		}
		
			//c.write(g, m);

	}
	
}
