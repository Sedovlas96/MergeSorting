#include "function.h"
#include <iostream>

using namespace std;

int main()
{   const int length = 5, VALUE = 90;
    int Array[ length ];
    generateArray( Array, length, VALUE );
    showArray( Array, length );
    mergeSorting( Array, 0, length - 1 );
    //mergeParts(Array, 0, 2, 3, 4);
    cout << endl;
    showArray( Array, length );
    return 0;
}
