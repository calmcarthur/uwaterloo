// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q3 q3.cpp

#include<string>
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

auto LoadMatrix() -> vector< vector< float > >
{
    int numnberOfRows;
    int numnberOfColumns;

    string currentLine;
    getline( cin, currentLine );
    numnberOfRows = stoi( currentLine );
    getline( cin, currentLine );
    numnberOfColumns = stoi( currentLine );

    vector< vector< float > > matrix;

    for ( int currentRowNumber = 0; currentRowNumber < numnberOfRows; currentRowNumber++ )
    {
        vector< float > currentRow;
        for ( int currentColumnNumber = 0; currentColumnNumber < numnberOfColumns; currentColumnNumber++ )
        {
            getline( cin, currentLine );
            float currentValue = stof( currentLine );
            currentRow.push_back( currentValue );
        }
        matrix.push_back( currentRow );
    }

    return matrix;
}

auto DisplayMatrix(vector< vector< float > > inputMatrix, bool highlight) -> void
{
float size1 = inputMatrix.size();
for (float i = 0; i <= (size1-1); ++i) {
    float size2 = inputMatrix[i].size();
        for (float j = 0; j <= (size2-1); ++j) {
            if (highlight){
                if (i <= j) {
                    cout << "\033[1;34m" << setw(6) << setprecision(2) << inputMatrix[i][j] << "\033[0m" << "\t";
                }
                else{
                   cout << setw(6) << setprecision(2) << inputMatrix[i][j]  << "\t"; 
                }
            } 
            else {
                cout << setw(6) << setprecision(2) << inputMatrix[i][j]  << "\t";
            }
        }
    cout << "\n";
    }
}

auto main() -> int
{
    cout << std::fixed;
    auto matrix = LoadMatrix();
    string currentLine;
    getline( cin, currentLine );
    auto highlightUpperTriangle = ( currentLine.length() != 0 );
    DisplayMatrix( matrix, highlightUpperTriangle);
}