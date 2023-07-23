#include <iostream>

void exclusive(bool x, bool y, bool& ans);
void implies(bool x, bool y, bool& ans);
void equivalence(bool x, bool y, bool& ans);

using namespace std;

void checkAns(bool val, bool expected) {
    if (val != expected) {
        cout << "FAIL - expected " << expected << endl;
        exit(1);
    }
}

int main() {
    bool ans;
    // T T
    exclusive(true, true, ans);
    cout << "T xor T: " << ans << endl;
    checkAns(ans, false);
    // T F
    exclusive(true, false, ans);
    cout << "T xor F: " << ans << endl;
    checkAns(ans, true);
    // F T
    exclusive(false, true, ans);
    cout << "F xor T: " << ans << endl;
    checkAns(ans, true);
    // F F
    exclusive(false, false, ans);
    cout << "F xor F: " << ans << endl;
    checkAns(ans, false);

    // implications
    implies(true, true, ans);
    cout << "T => T: " << ans << endl;
    checkAns(ans, true);
    // T F
    implies(true, false, ans);
    cout << "T => F: " << ans << endl;
    checkAns(ans, false);
    // F T
    implies(false, true, ans);
    cout << "F => T: " << ans << endl;
    checkAns(ans, true);
    // F F
    implies(false, false, ans);
    cout << "F => F: " << ans << endl;
    checkAns(ans, true);

    // bidirectional
    equivalence(true, true, ans);
    cout << "T <=> T: " << ans << endl;
    checkAns(ans, true);
    // T F
    equivalence(true, false, ans);
    cout << "T <=> F: " << ans << endl;
    checkAns(ans, false);
    // F T
    equivalence(false, true, ans);
    cout << "F <=> T: " << ans << endl;
    checkAns(ans, false);
    // F T
    equivalence(false, false, ans);
    cout << "F <=> F: " << ans << endl;
    checkAns(ans, true);

    cout << "OK!" << endl;
}
