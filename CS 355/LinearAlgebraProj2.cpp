#include <iostream>
using namespace std;

int main()
{
    int ar[3][3] = {1,2,3,4,5,6,7,8,9};
    int br[3][3] = {1,1,1,1,1,1,1,1,1};
    int cr[3][3] = {0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; i < 3; j++)
        {
            br[i][j] = ar[i][j] * br[i][j];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "\t" << br[i][j];
        }
        cout << endl;
    }

    return 0;
}
