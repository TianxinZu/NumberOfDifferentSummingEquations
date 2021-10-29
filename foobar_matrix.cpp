#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    string input;
    cin >> input;
    int number = stoi(input);
    int c[number+1][number+1];
    
    for (int i = 0; i < number+1; i++)
    {
        for (int j = 0; j < number+1; j++)
        {
            c[i][j] = 0;
        }
    }

    for (int i = 1; i < number+1; i++)
    {
        c[i][i] = 1;
        for (int j = i-1; j > 0; j--)
        {
            if (i%2 == 1)
            {
                if (j > i/2)
                {
                    for (int k = i-j; k > 0; k--)
                    {
                        c[i][j] += c[i-j][k];
                    }
                }
                else
                {
                    for (int k = j-1; k > 0; k--)
                    {
                        c[i][j] += c[i-j][k];
                    }
                }
            }
            else
            {
                if (j > i/2+1)
                {
                    for (int k = i-j; k > 0; k--)
                    {
                        c[i][j] += c[i-j][k];
                    }
                }
                else
                {
                    for (int k = j-1; k > 0; k--)
                    {
                        c[i][j] += c[i-j][k];
                    }
                }
            }
        }
    }

/*   
for (int i = 0; i < number+1; i++)
{
    for (int j = 0; j < number+1; j++)
    {
        cout << c[j][i] << " ";
    }
    cout << endl;
}
*/

int sum = 0;
for (int i = 0; i < number; i++)
{
    sum += c[number][i]; 
}
cout << sum << endl;

}