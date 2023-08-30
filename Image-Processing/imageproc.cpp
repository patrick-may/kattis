#include <vector>
#include <iostream>

using namespace std;

int apply(const vector<vector<int>>& im, const vector<vector<int>>& kern, pair<int, int> start) {
    int x = start.first, y = start.second;
    int soln = 0;
    for (int i = 0; i < kern.size(); ++i) {
        for (int j = 0; j < kern[0].size(); ++j) {
            soln += im[x + i][y + j] * kern[i][j];
        }
    }

    return soln;
}

int main() {
    int imheight, imwidth, kernheight, kernwidth;
    cin >> imheight >> imwidth >> kernheight >> kernwidth;
    vector<vector<int>> image(imheight, vector<int>(imwidth));
    vector<vector<int>> kernel(kernheight, vector<int>(kernwidth));

    for(int i = 0; i < imheight; ++i) {
        for (int j = 0; j < imwidth; ++j) {
            cin >> image[i][j];
        }
    }

    for (int i = kernheight - 1; i >= 0; --i) {
        for (int j = kernwidth - 1; j >= 0; --j) {
            cin >> kernel[i][j];
        }
    }

    vector<vector<int>> transformed;
    for (int i = 0; i <= imheight - kernheight; ++i) {
        vector<int> subsoln; 
        for (int j = 0; j <= imwidth - kernwidth; ++j) {
            subsoln.push_back(apply(image, kernel, {i, j}));
        }
        transformed.push_back(subsoln);
    }

    for (auto r : transformed) {
        for (auto c : r) {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}
