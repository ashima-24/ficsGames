#include<iostream>
#include "PngParser.hpp"
#include "CsvStream.hpp"

using namespace std;

int main ()

{
	parser p;
	csvfile ss("out.csv");
	ifstream inputFile("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	p.ficsGamesHeaders(inputFile);


}
