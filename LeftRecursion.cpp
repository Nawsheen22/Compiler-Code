
using namespace std;

int rec(string s) {
    if (s[0] == s[3]) {
        return 3;
    }
    for (int i = 3; i < s.size(); i++) {
        if(i + 1 < s.size() && s[i] == '|' && s[0] == s[i + 1]){
            return i + 1;
        }
    }

    return 0;
}

void find_left(bool &run) {
    string s, alpha = "", beta = "";
    cin >> s;

    if (s == "end") {
        run = false;
        return;
    }

    int i = rec(s);

    if (!i) {
        cout << "No left recursion \n";
        return;
    }
    i++;
    while(s[i] != '|') {
        alpha += s[i];
        i++;
    }
    i++;
    while(i < s.size()) {
        beta += s[i];
        i++;
    }

    cout << "ans: \n";
    cout << s[0] << "->" << beta << s[0] << "'";
    cout << "\n";
    cout << s[0] << "'" << "->" << alpha << "" <<s[0] << "'|e";
    cout << "\n";
}

int main() {

    bool run = true;
    while(run) {
        cout << "Enter grammer: ";
        find_left(run);
    }
}

