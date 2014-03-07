#include "function.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void mergeParts( int *Array, int firstIndexOfArrayOne, int lastIndexOfArrayOne, int firstIndexOfArrayTwo, int lastIndexOfArrayTwo )
{
    int indexOfSortingArray = 0;
    int *sortingArray;
    sortingArray = new int [ lastIndexOfArrayTwo - firstIndexOfArrayOne + 1 ] ;
    while( ( firstIndexOfArrayOne <= lastIndexOfArrayOne) && ( firstIndexOfArrayTwo <= lastIndexOfArrayTwo ) )
    {
        if( Array[ firstIndexOfArrayOne ] <= Array[ firstIndexOfArrayTwo ] )
        {
            sortingArray[ indexOfSortingArray ] = Array[ firstIndexOfArrayOne ];
            ++ firstIndexOfArrayOne;
        }
        else
        {
            sortingArray[ indexOfSortingArray ] = Array[ firstIndexOfArrayTwo ];
            ++ firstIndexOfArrayTwo;
        }
        ++ indexOfSortingArray;
    }
    if( firstIndexOfArrayOne <= lastIndexOfArrayOne )
    {
        for( int i = firstIndexOfArrayOne; i <= lastIndexOfArrayOne; ++i )
        {
            sortingArray[ indexOfSortingArray ] = Array[ i ];
            ++ indexOfSortingArray;
        }
    }
    else
    {
        for( int i = firstIndexOfArrayTwo; i <= lastIndexOfArrayTwo; ++i )
        {
            sortingArray[ indexOfSortingArray ] = Array[ i ];
            ++ indexOfSortingArray;
        }
    }
    for( int i = 0; i < indexOfSortingArray; ++i )
    {
        Array [ i ] = sortingArray[ i ];
    }
    delete [] sortingArray;
    sortingArray = 0;

}


void mergeSorting( int *Array, int firstIndex, int lastIndex )
{
    if( firstIndex < lastIndex )
    {
        cout << firstIndex <<" " << (firstIndex + lastIndex ) / 2<<" " << (firstIndex + lastIndex ) / 2 + 1<<" " << lastIndex<<endl;
        mergeSorting( Array, firstIndex, ( firstIndex + lastIndex ) / 2 );
        mergeSorting( Array, ( firstIndex + lastIndex ) / 2 + 1, lastIndex );
        mergeParts( Array, firstIndex, ( firstIndex + lastIndex ) / 2, ( firstIndex + lastIndex ) / 2 + 1, lastIndex );
    }

}


void generateArray( int *Array, int length, int value )
{
    srand(time(NULL));
    for( int i = 0; i < length; ++i )
    {
        Array[ i ] = rand() % value + 10;
    }
}


void showArray( int *Array, int length )
{
    for(int i = 0; i < length; ++i)
    {
        cout << Array[ i ] << " ";
    }
    cout << endl;
}
