#include <iostream>
#include <vector>
using namespace std;
class VectorOperations {
    private:
    vector<int> v;
    public:
    VectorOperations(vector<int> vec) {
        this->v = vec;
    }
    VectorOperations() {}
    // Performing scalar multiplication
    vector<int> scalar_mult(int num) {
        vector<int> res(v.size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = num * v[i];
        }
        return res;
    }
    // Performing the first task: scalar multiplication and addition
    vector<int> mult_and_add(VectorOperations vector_op, int X, int Y) {
        vector<int> vector1 = scalar_mult(X);
        vector<int> vector2 = vector_op.scalar_mult(Y);
        vector<int> res(vector1.size(), 0);
        if (vector1.size() != vector2.size()) {
            cout << "These vectors are not compatible for the operation." << endl;
        } else {
            for (int i = 0; i < res.size(); i++) {
                res[i] = vector1[i] + vector2[i];
            }
        }
        return res;
    }
    // Applying dot product
    int dot_product(VectorOperations vector_op) {
        int result = 0;
        for (int i = 0; i < vector_op.v.size(); i++) {
            result += v[i] * vector_op.v[i];
        }
        return result;
    }
};
int main() {
    int n;
    cout << "Enter the number of elements for the vectors: ";
    cin >> n;
    vector<int> vec1(n), vec2(n);
    cout << "Enter elements of the first vector: ";
    for (int i = 0; i < n; i++) {
        cin >> vec1[i];
    }
    cout << "Enter elements of the second vector: ";
    for (int i = 0; i < n; i++) {
        cin >> vec2[i];
    }
    int X, Y;
    cout << "Enter the scalar for the first vector (X): ";
    cin >> X;
    cout << "Enter the scalar for the second vector (Y): ";
    cin >> Y;
    VectorOperations v1(vec1);
    VectorOperations v2(vec2);
    vector<int> result = v1.mult_and_add(v2, X, Y);
    cout << "Result of scalar multiplication and addition: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    int dotProdResult = v1.dot_product(v2);
    cout << "Dot product result: " << dotProdResult << endl;
}
