#include <iostream>
#include <vector>
using namespace std;
class Matrix
{
private:
    vector<vector<int>> v;
public:
    Matrix(int rows, int cols, vector<vector<int>> vect) : v(rows, vector<int>(cols)) { v = vect; }
    Matrix() {}
    Matrix(int rows, int cols) : v(rows, vector<int>(cols)) {}
    static vector<vector<int>> make_matrix(vector<vector<int>> &matrix, int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i][j];
            }
        }
        return matrix;
    }
    Matrix operator+(Matrix matrix_1)
    {
        Matrix res(matrix_1.v.size(), matrix_1.v[0].size());
        if (v.size() == matrix_1.v.size() && v[0].size() == matrix_1.v[0].size())
        {
            for (int i = 0; i < matrix_1.v.size(); i++)
            {
                for (int j = 0; j < matrix_1.v[0].size(); j++)
                {
                    res.v[i][j] = v[i][j] + matrix_1.v[i][j];
                }
            }
            cout<<endl;
            return res;
        }
        else
        {
            cout << "These matrices are not compatible for addition." << endl;
            return res;
        }
    }

    Matrix operator-(Matrix matrix_1)
    {
        Matrix res(matrix_1.v.size(), matrix_1.v[0].size());
        if (v.size() == matrix_1.v.size() && v[0].size() == matrix_1.v[0].size())
        {
            for (int i = 0; i < matrix_1.v.size(); i++)
            {
                for (int j = 0; j < matrix_1.v[0].size(); j++)
                {
                    res.v[i][j] = v[i][j] - matrix_1.v[i][j];
                }
            }
            cout<<endl;
            return res;
        }
        else
        {
            cout << "These matrices are not compatible for subtraction." << endl;
            return res;
        }
    }

    Matrix operator*(Matrix matrix_1)
    {
        Matrix res(v.size(), matrix_1.v[0].size());
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < matrix_1.v[0].size(); j++)
            {
                res.v[i][j] = 0;
                for (int k = 0; k < v[0].size(); k++)
                {
                    res.v[i][j] += v[i][k] * matrix_1.v[k][j];
                }
            }
        }
        cout<<endl;
        return res;
    }

    void multiply_by_number(int num)
    {
        for (auto i : v)
        {
            for (auto j : i)
            {
              cout<<num*j<<" ";
            }
            cout<<endl;
        }
    
    }

    void transpose()
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[0].size(); j++)
            {
                cout<<v[j][i]<<" ";
            }
            cout<<endl;
        }
    }

    void show_matrix()
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[0].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter the rows and columns for 1st matrix: ";
    cin >> r1 >> c1;

    vector<vector<int>> v1(r1, vector<int>(c1, 0));
    cout << "Enter the elements for the 1st matrix: " << endl;
    Matrix::make_matrix(v1, r1, c1);

    Matrix matrix1(r1, c1, v1);
    int operation;
    cout << "How many operations would you like to perform? ";
    cin >> operation;

    for (int i = 0; i < operation; i++)
    {
        int choice = 0;
        cout << "Enter which operation you want to choose: \n";
        cout << "1) Addition \n2) Subtraction \n3) Multiplication\n4) Multiply by Number\n5) Transpose\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        {
            cout << "Enter the rows and columns for 2nd matrix: ";
            cin >> r2 >> c2;
            vector<vector<int>> v2(r2, vector<int>(c2, 0));

            cout << "Enter the elements for the 2nd matrix: " << endl;
            Matrix::make_matrix(v2, r2, c2);

            Matrix matrix2(r2, c2, v2);

            Matrix res;
            if (choice == 1)
            {
                res = matrix1 + matrix2;
            }
            else if (choice == 2)
            {
                res = matrix1 - matrix2;
            }
            else
            {
                res = matrix1 * matrix2;
            }
            res.show_matrix();
            break;
        }
        case 4:
        {
            int num;
            cout << "Enter the number to multiply with: ";
            cin >> num;
            matrix1.multiply_by_number(num);
            break;
        }
        case 5:
        {
            cout << "The transpose of the matrix is: \n";
            matrix1.transpose();
            break;
        }
        default:
            cout << "Invalid choice! Please select a valid option.\n";
            break;
        }
    }
}
