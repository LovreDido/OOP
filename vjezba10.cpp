#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

void zadatak1() {
    vector<int> v = { 1,2,3,4,5,8,10,16,7,9 };

    auto firstOdd = find_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
    if (firstOdd != v.end())
        cout << "Prvi neparni: " << *firstOdd << endl;

    int countOdd = count_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
    cout << "Broj neparnih: " << countOdd << endl;

    int sumOdd = accumulate(v.begin(), v.end(), 0,
        [](int s, int x) { return x % 2 ? s + x : s; });

    if (countOdd)
        cout << "Prosjek neparnih: "
        << static_cast<double>(sumOdd) / countOdd << endl;

    auto isPowerOfTwo = [](int x) { return x > 0 && (x & (x - 1)) == 0; };
    replace_if(v.begin(), v.end(), isPowerOfTwo, 2);

    vector<int> even, odd;
    copy_if(v.begin(), v.end(), back_inserter(even), [](int x) { return x % 2 == 0; });
    copy_if(v.begin(), v.end(), back_inserter(odd), [](int x) { return x % 2 != 0; });

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    copy(even.begin(), even.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(odd.begin(), odd.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}

namespace math_utils {

    struct Point {
        double x, y;
    };

    double distance(const Point& a, const Point& b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    Point centroid(const vector<Point>& v) {
        double sx = accumulate(v.begin(), v.end(), 0.0,
            [](double s, const Point& p) { return s + p.x; });
        double sy = accumulate(v.begin(), v.end(), 0.0,
            [](double s, const Point& p) { return s + p.y; });
        return { sx / static_cast<double>(v.size()),
                 sy / static_cast<double>(v.size()) };
    }

    istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }

    ostream& operator<<(ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }

}

namespace student_records {

    struct Student {
        string ime, prezime;
        int bodovi;
    };

    istream& operator>>(istream& is, Student& s) {
        return is >> s.ime >> s.prezime >> s.bodovi;
    }

    ostream& operator<<(ostream& os, const Student& s) {
        return os << s.ime << " " << s.prezime << " " << s.bodovi;
    }

}

int main() {
    zadatak1();

    using namespace math_utils;

    ifstream fin("points.txt");
    vector<Point> points((istream_iterator<Point>(fin)), istream_iterator<Point>());

    sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return distance(a, { 0,0 }) < distance(b, { 0,0 });
        });

    cout << count_if(points.begin(), points.end(),
        [](const Point& p) { return p.x > 0 && p.y > 0; }) << endl;

    Point c = centroid(points);
    cout << c << endl;

    transform(points.begin(), points.end(), points.begin(),
        [](Point p) { return Point{ p.x + 5, p.y + 3 }; });

    points.erase(remove_if(points.begin(), points.end(),
        [](const Point& p) { return p.x < 0 && p.y < 0; }), points.end());

    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));

    using namespace student_records;

    ifstream fs("studenti.txt");
    vector<Student> studenti((istream_iterator<Student>(fs)), istream_iterator<Student>());

    auto bodovi_u_ocjenu = [](int b) {
        if (b < 40) return 1;
        if (b < 55) return 2;
        if (b < 70) return 3;
        if (b < 85) return 4;
        return 5;
        };

    studenti.erase(remove_if(studenti.begin(), studenti.end(),
        [](const Student& s) { return s.bodovi < 40; }), studenti.end());

    transform(studenti.begin(), studenti.end(), studenti.begin(),
        [&](Student s) { s.bodovi = bodovi_u_ocjenu(s.bodovi); return s; });

    double avg = accumulate(studenti.begin(), studenti.end(), 0.0,
        [](double s, const Student& st) { return s + st.bodovi; })
        / static_cast<double>(studenti.size());

    sort(studenti.begin(), studenti.end(),
        [](const Student& a, const Student& b) { return a.prezime < b.prezime; });

    copy(studenti.begin(), studenti.end(),
        ostream_iterator<Student>(cout, "\n"));

    cout << avg << endl;
}
