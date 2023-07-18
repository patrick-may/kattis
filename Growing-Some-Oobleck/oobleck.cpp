#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

bool debug = false;

typedef long double ld;

typedef struct Circle {
    ld x;
    ld y;
    ld r;
    ld s;

    // default, needed for some reason...?
    Circle() {
        x = -1;
        y = -1;
        r = -1;
        s = -1;
    }
    Circle(ld a, ld b, ld c, ld d) {
        x = a;
        y = b;
        r = c;
        s = d;
    }

    ld area() { return M_PI * pow(r, 2); }

    void grow() { r += s; }

    bool operator==(const Circle& c) const {
        return x == c.x && y == c.y && s == c.s && r == c.r;
    }

    bool operator<(const Circle& o) const {
        return x < o.x || (x == o.x && y < o.y) ||
               (x == o.x && y == o.y && o.s < o.s);
    }
    void print() const {
        cout << "X: " << x << " Y: " << y << " Growth: " << s
             << " Radius: " << r << "\n";
    }

} Circle;

Circle ooblection(set<Circle>& overlaps) {
    ld midx = 0;
    ld midy = 0;
    ld newr = 0;
    ld news = -1;
    ld totalArea = 0;
    for (auto c : overlaps) {
        midx += c.x;
        midy += c.y;
        totalArea += c.area();
        news = max(news, c.s);
    }
    midx /= overlaps.size();
    midy /= overlaps.size();
    newr = sqrt(totalArea / M_PI);
    Circle merged(midx, midy, newr, news);
    return merged;
}

bool overlap(Circle& c1, Circle& c2) {
    ld raddist = c1.r + c2.r;
    ld xdist = pow((c1.x - c2.x), 2);
    ld ydist = pow((c1.y - c2.y), 2);
    ld comb = sqrt(xdist + ydist);
    return comb <= raddist;
}

int main() {
    int ct;
    cin >> ct;

    vector<Circle> oobs(ct);
    for (int i = 0; i < ct; ++i) {
        ld a, b, c, d;
        cin >> a >> b >> c >> d;
        Circle temp(a, b, c, d);
        oobs[i] = temp;
    }

    if (debug) {
        for (auto c : oobs) {
            c.print();
        }
    }

    bool grow = true;
    int time = 0;
    while (oobs.size() > 1) {
        // grow all ooblecks if didn't merge prior
        if (grow) {
            ++time;
            for (int i = 0; i < oobs.size(); ++i) {
                oobs[i].grow();
            }
        }

        // debug purposes
        if (debug) {
            for (auto c : oobs) {
                c.print();
            }
        }

        // find intersections
        map<Circle, vector<Circle>> to_merge;
        for (int i = 0; i < oobs.size(); ++i) {
            Circle c1 = oobs[i];
            for (int j = i + 1; j < oobs.size(); ++j) {
                Circle c2 = oobs[j];
                if (overlap(c1, c2)) {
                    to_merge[c1].push_back(c2);
                    to_merge[c2].push_back(c1);
                }
            }
        }

        if (debug) {
            for (auto p : to_merge) {
                cout << "KEY: ";
                p.first.print();
                cout << "\n\t";
                for (auto v : p.second) {
                    cout << "\t";
                    v.print();
                    cout << "\n";
                }
            }
        }

        if (to_merge.size() > 0) {
            grow = false;
        } else {
            grow = true;
            continue;
        }

        vector<Circle> updatedOobs;

        for (Circle c : oobs) {
            if (to_merge.count(c) == 0) {
                updatedOobs.push_back(c);
            }
        }

        set<Circle> done;
        for (auto p : to_merge) {
            if (done.count(p.first)) {
                continue;
            }
            set<Circle> currmerge;
            currmerge.insert(p.first);

            vector<Circle> inserts = p.second;
            while (!inserts.empty()) {
                Circle top = inserts[0];

                if (currmerge.count(top) == 0) {
                    for (auto elem : to_merge[top]) {
                        inserts.push_back(elem);
                    }
                }

                currmerge.insert(top);
                inserts.erase(inserts.begin());
            }

            if (debug) {
                cout << "CURRENT MERGE\n";
                for (auto elem : currmerge) {
                    elem.print();
                }
            }

            for (auto elem : currmerge) {
                done.insert(elem);
            }

            Circle merged = ooblection(currmerge);
            updatedOobs.push_back(merged);
        }

        oobs = updatedOobs;
        // cout << "TIME: " << time << "\n";
    }

    cout << fixed;
    cout.precision(8);
    cout << oobs[0].x << " " << oobs[0].y << "\n";
    cout << oobs[0].r << "\n";

    return 0;
}
