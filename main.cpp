#include<iostream>
#include "PngParser.hpp"
using namespace std;

int main ()

{
	parser p;
	ifstream inputFile("ficsgamesdb_2020_chess_nomovetimes_184120.pgn");
	p.ficsGamesHeaders(inputFile);

}
