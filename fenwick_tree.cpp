#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int size;

    FenwickTree(const vector<int>& input) {
        size = input.size();
        bit.resize(size + 1, 0);

        for (int i = 0; i < size; i++) {
            update(i, input[i]);
        }
    }
    void update(int idx, int value) {
        idx++; //for 1-based system
        while (idx <= size) {
            bit[idx] += value;
            idx += (idx & -idx);
        }
    }

    int prefixSum(int idx) {
        idx++; //for 1-based system
        int result = 0;

        while (idx > 0) {
            result += bit[idx];
            idx -= (idx & -idx);
        }
        return result;
    }

    int queryRange(int l, int r) {
        if (l == 0) {
            return prefixSum(r);
        }
        return prefixSum(r) - prefixSum(l - 1);
    }
};

void printArray(const vector<int>& data) {
    cout << "[ ";
    for(int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << "]\n";
}

void applyUpdate(FenwickTree& tree, vector<int>& data, int index, int val) {
    tree.update(index, val);
    data[index] += val;
}

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(data);

    cout << "Initial array:\n";
    printArray(data);

    cout << "\nRange sum [1, 4]: "
         << ft.queryRange(1, 4) << endl;

    cout << "\nUpdating index 2 by +4...\n";
    applyUpdate(ft, data, 2, 4);

    cout << "\nUpdated array:\n";
    printArray(data);

    cout << "Range sum [1, 4]: "
         << ft.queryRange(1, 4) << endl;

    return 0;
}
