// lab 0, gold.cpp
// This lab reads in a "map" and returns the amount 
//		of gold on the map
// COSC 140
// Swasti Mishra
// 01/24/20 
// Professor Emrich
// Students: 

# include <iostream>
# include <limits>
# include <fstream>
# include <vector>
# include <string>

using namespace std ;

int main () {
	
	unsigned int total = 0 ;
	int remove = 0 ;
	string filename, data ;
	ifstream maps ;
	// declaration of variables
	
	while ( !( maps.is_open() ) ) {
		cout << "Enter the name of a map: " ;
		cin >> filename ;
		maps.open( filename ) ;
	}
	// runs until they open a file that exists
	// Prints first command to the console
	
	while ( getline ( maps , data ) ) {
		for ( unsigned int i = 0 ; i < data.size() ; i++ ) {
			if ( data.at(i) == '.' ) {
				remove = 1 ;
			}
			else if ( data.at(i) == '-' ) {
				remove = 1 ;			
			}
			if ( remove == 0 ) { 
				total = ( int( data.at( i ) ) - 64 ) + total ;
			}
			if ( remove == 1 ) {
				remove = 0 ;
			}
		}
	}
	
	cout << total << "\n" ;

	maps.close() ;
}
