#include <iostream>
#include <math.h>
using namespace std;

// Driver Code
int main()
{
    int num_case, i, j, k, z;
    cout << "Input your i of D-H Parameters :";
    // Take input using cin
    cin >> num_case;
    double dhP[num_case][4];
    double trans_Matrix[num_case][4][4];
    double product[4][4];
    for (i = 0; i < num_case; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << "i :" << i + 1 << "/ postion :" << j + 1 << "/4 :";
            cin >> dhP[i][j];
        }
    }
    cout << "Your D-H array :" << endl;
    for (i = 0; i < num_case; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << dhP[i][j] << "\t";
        }
        cout << endl;
    }
    //𝛼𝑖−1 𝑎𝑖−1 𝑑𝑖 𝜃i
    for (i = 0; i < num_case; i++)
    {
        trans_Matrix[i][0][0] = cos(dhP[i][3]*3.1416/180);
        trans_Matrix[i][0][1] = -1 * sin(dhP[i][3]*3.1416/180);
        trans_Matrix[i][0][2] = 0;
        trans_Matrix[i][0][3] = dhP[i][1];

        trans_Matrix[i][1][0] = sin(dhP[i][3]*3.1416/180) * cos(dhP[i][0]*3.1416/180);
        trans_Matrix[i][1][1] = cos(dhP[i][3]*3.1416/180) * cos(dhP[i][0]*3.1416/180);
        trans_Matrix[i][1][2] = -1 * sin(dhP[i][0]*3.1416/180);
        trans_Matrix[i][1][3] = -1 * sin(dhP[i][0]*3.1416/180) * dhP[i][2];

        trans_Matrix[i][2][0] = sin(dhP[i][3]*3.1416/180) * sin(dhP[i][0]*3.1416/180);
        trans_Matrix[i][2][1] = cos(dhP[i][3]*3.1416/180) * sin(dhP[i][0]*3.1416/180);
        trans_Matrix[i][2][2] = cos(dhP[i][0]*3.1416/180);
        trans_Matrix[i][2][3] = cos(dhP[i][0]*3.1416/180) * dhP[i][2];

        trans_Matrix[i][3][0] = 0;
        trans_Matrix[i][3][1] = 0;
        trans_Matrix[i][3][2] = 0;
        trans_Matrix[i][3][3] = 1;
    }
    cout << "Your T-M :" << endl;
    for (i = 0; i < num_case; i++)
    {
        cout << "T-M :" << i + 1 << endl;
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                cout << trans_Matrix[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    double sum = 0;
    double product2[4][4];
    double product3[4][4];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                sum += trans_Matrix[0][i][k] * trans_Matrix[1][k][j];
            }
            product[i][j] = sum;
            sum = 0;
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                sum += product[i][k] * trans_Matrix[2][k][j];
            }
            product2[i][j] = sum;
            sum = 0;
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                sum += product2[i][k] * trans_Matrix[3][k][j];
            }
            product3[i][j] = sum;
            sum = 0;
        }
    }
    cout<<"Product 1:"<<endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            cout << product[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<"Product 2:"<<endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            cout << product2[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<"Product 3:"<<endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            cout << product3[i][j] << "\t";
        }
        cout << endl;
    }
    

    return 0;
}
