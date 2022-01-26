#include <iostream>
#include <math.h>
using namespace std;
#define R1 4            // number of rows in Matrix-1
#define C1 4            // number of columns in Matrix-1
#define R2 4            // number of rows in Matrix-2
#define C2 4            // number of columns in Matrix-2
double mem_mat[4][4]; 
void mulMat(double mat1[][C1], double mat2[][C2]) {
    double rslt[R1][C2];
 
    cout << "Multiplication of given two matrices is:\n" << endl;
 
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
 
            cout << rslt[i][j] << "\t";
            mem_mat[i][j] = rslt[i][j];
        }
 
        cout << endl;
    }
    
}
// Driver Code
int main()
{
    int num_case, i, j,k;  
    cout << "Input your i of D-H Parameters :";
    // Take input using cin
    cin >> num_case;
    double dhP[num_case][4];
    double trans_Matrix[num_case][4][4];
    for (i = 0; i < num_case; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << "i :" << i + 1 << "/ postion :" << j + 1 << "/4 :";
            cin >> dhP[i][j];
        }
    }
    cout << "Your D-H array :"<< endl;
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
        trans_Matrix[i][0][0] = cos(dhP[i][3]);
        trans_Matrix[i][0][1] = -1*sin(dhP[i][3]);
        trans_Matrix[i][0][2] = 0;
        trans_Matrix[i][0][3] = dhP[i][1];

        trans_Matrix[i][1][0] = sin(dhP[i][3])*cos(dhP[i][0]);
        trans_Matrix[i][1][1] = cos(dhP[i][3])*cos(dhP[i][0]);
        trans_Matrix[i][1][2] = -1*sin(dhP[i][0]);
        trans_Matrix[i][1][3] = -1*sin(dhP[i][0])*dhP[i][2];

        trans_Matrix[i][2][0] = sin(dhP[i][3])*sin(dhP[i][0]);
        trans_Matrix[i][2][1] = cos(dhP[i][3])*sin(dhP[i][0]);
        trans_Matrix[i][2][2] = cos(dhP[i][0]);
        trans_Matrix[i][2][3] = cos(dhP[i][0])*dhP[i][2];

        trans_Matrix[i][3][0] = 0;
        trans_Matrix[i][3][1] = 0;
        trans_Matrix[i][3][2] = 0;
        trans_Matrix[i][3][3] = 1;
    }
    cout << "Your T-M :"<< endl;
    for (i = 0; i < num_case; i++)
    {
        cout << "T-M :"<< i+1 << endl;
        for (j = 0; j < 4; j++)
        {
            for(k =0;k<4; k++){
                cout<< trans_Matrix[i][j][k]<< "\t";
            }
            cout << endl;
        }
        cout<<endl;
    }
    
    mulMat(trans_Matrix[0],trans_Matrix[1]);
    for(i=2;i<num_case;i++){
        mulMat(mem_mat,trans_Matrix[i]);
    }
    
    

    return 0;
}
