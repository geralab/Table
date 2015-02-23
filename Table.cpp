/* Gerald Blake
 * prints formatted multiplication table
 * to terminal and file
 * for larger table use the file feature
 * also for larger tables it may become necessary to shrink the font and "zoom in"
 * to view make view the table as intended
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstdio>

using namespace std;
void print(vector< vector<string> > &table);
FILE * pFile = fopen ("Table.txt","w");
int maxCol = 0;

int main()
{
	
    vector< vector<string> > table;
  
    ostringstream st;

	unsigned int length = 0;
	string hold;
	unsigned int number = 0;
    
	cout << "What is the maximum multible: ";
	cin >> length;
	length++;
    
  
    
	for(unsigned int row = 0; row < length; row++ )
	{
		number = 0;
        vector<string> temp;
        table.push_back(temp);
        
		for(unsigned int col = 0; col < length; col++)
		{
			//print current row number
            ostringstream stm;
            string temp;
            stm << number;
            
            if((row == 1 && col != 0) || (col == 1 && row != 0))
                temp = "|" +  stm.str()  + "|";
            else
                temp =  stm.str();
            
			table[row].push_back(temp);
            if(table[row][col].length() > maxCol)
                maxCol = table[row][col].length()  * 3;
			// increment so next number may be printed
			number += row;
			
		}
		
	}
    
    print(table);
	return 0;
}

void print(vector< vector<string> > &table)
{
    ostringstream stm;
    stm << maxCol;
    string field = "%" + stm.str() + "s";
    stm.str("");
    stm.clear();
    stm << maxCol + 2;
    string field2 = "%" + stm.str() + "s";
    
    for(unsigned int row = 1; row < table.size(); row++ )
    {
        for(unsigned int col = 1; col < table[row].size(); col++)
        {
       
            printf(field.c_str(), (table[row][col]).c_str());
            fprintf(pFile,field.c_str(), (table[row][col]).c_str());

        }
        printf("\n");
        fprintf(pFile,"\n");
      
    }
}
