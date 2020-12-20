#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

class RF {
private :
    string secret_key = "ejffimc9u3x9ru893u8w";
    long long INPUT_NUMBERR = 0;
    int correct_query = 0;
    int count_query = 0;

public :
    long long RanDInt(long long L, long long R) {
        return L + rand() % (R - L + 1);
    }

    void GaN(long long NUMBER, string secret) {
        if(secret == secret_key)
            INPUT_NUMBERR = NUMBER;
        else {
            cerr << "Dung hack code!\n";
            exit(-1);
        }
    }

    long long GeT(string secret) {
        if(secret == secret_key)
            return INPUT_NUMBERR;
        else {
            cerr << "Dung hack code!\n";
            exit(-1);
        }
    }

    void Inc_R(string secret) {
        if(secret == secret_key)
            count_query++;
        else {
            cerr << "Dung hack code!\n";
            exit(-1);
        }
    }

    void Inc_F(string secret) {
        if(secret == secret_key)
            correct_query++;
        else {
            cerr << "Dung hack code!\n";
            exit(-1);
        }
    }

    double GeTCr(string secret) {
        if(secret == secret_key)
            return (double) correct_query;
        else {
            cerr << "Dung hack code!\n";
            exit(-1);
        }
    }

    int GeTCf(string secret) {
        if(secret == secret_key)
            return count_query;
        else {
            cerr << "Dung hack code!\n";
            exit(-1);
        }
    }
} RevFact;

int NUMquery, ALLquery;

void Point() {
    double F = RevFact.GeTCr("ejffimc9u3x9ru893u8w");
    if(F == ALLquery)
        cerr << "Correct Answer\n";
    cerr << (F + 1) / (ALLquery + 1) * 1;
    exit(0);
}

void GetQuery(int _query) {
    NUMquery = _query;
    ALLquery = _query;
}

void GenInput(int _subtask) {
    NUMquery--;
    int subtask = _subtask;
    long long INPUT_NUMBER = 0;
    if(subtask == 1)
        INPUT_NUMBER = RevFact.RanDInt(1, 1000);
    else if(subtask == 2)
        INPUT_NUMBER = RevFact.RanDInt(100000, 1000000000);
    else if(subtask == 3)
        INPUT_NUMBER = RevFact.RanDInt(3000000000, 1000000000000000000);
    RevFact.GaN(INPUT_NUMBER, "ejffimc9u3x9ru893u8w");
//    cerr << INPUT_NUMBER << "\n";
    return ;
}

string Query(char T, int AP) {
    RevFact.Inc_R("ejffimc9u3x9ru893u8w");
    if(RevFact.GeTCf("ejffimc9u3x9ru893u8w") > 100000000) {
        Point();
        exit(0);
    }

    if(T == '?') {
        if(AP <= RevFact.GeT("ejffimc9u3x9ru893u8w"))
            return "TRUE";
        else return "FALSE";
    }
    else if(T == '!') {
        if(AP == RevFact.GeT("ejffimc9u3x9ru893u8w"))
            RevFact.Inc_F("ejffimc9u3x9ru893u8w");
        else
            cerr << "Incorrect Answer\n";

        if(NUMquery == 0)
            Point();
    }
    return "";
}
