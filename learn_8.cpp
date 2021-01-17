#include <iostream> // Include for I/O streams
#include <fstream>
using namespace std; // Streams are in the std namespace (standard library)
#include <string>
#include <vector>
#include <sstream>

//8.1
istream& read(istream& in) {
    string s;
    while (in >> s) {
        cout << s << " ";
    }
    cout << endl;
    in.clear();
    return in;
}

//8.9
istringstream& read_string(istringstream& in) {
    string s;
    while (in >> s) {
        cout << s << " ";
    }
    cout << endl;
    in.clear();
    return in;
}

//8.4
vector<string>& read_to_svec(vector<string>& svec, string file) {
    ifstream fstrm(file);
    if (!fstrm) {
        cerr << "no input" << endl;
    }
    else {
        string line;
        while (getline(fstrm,line)) {
            // cout << line << endl;
            svec.push_back(line);
        }
    }
    for (auto elem : svec) {
        cout << elem << endl;
    }
    return svec;

}

//8.5
vector<string>& read_to_wvec(vector<string>& wvec, string file) {
    ifstream fstrm(file);
    if (!fstrm) {
        cerr << "no input" << endl;
    }
    else {
        string word;
        while (fstrm >> word) {
            // cout << line << endl;
            wvec.push_back(word);
        }
    }
    for (auto elem : wvec) {
        cout << elem << endl;
    }
    return wvec;

}

//8.10
vector<string>& copy_line_and_repeat(vector<string>& svec, string file) {
    string line;
    ifstream f(file); 
    if (!f) {cerr << "input error";}
    while (getline(f,line)) {
        svec.push_back(line);
    }
    cout << "svec.size = " << svec.size() << endl;
    f.close();
    
    for (auto elem: svec) {
        istringstream in(elem);
        string word;
        while(in >> word) {
            cout << word << " ";
        }
    }
    return svec;
}

//8.11
vector<string>& copy_line_and_repeat2(vector<string>& svec, string file) {
    string line;
    ifstream f(file); 
    istringstream in;
    if (!f) {cerr << "input error";}
    while (getline(f,line)) {
        svec.push_back(line);
    }
    cout << "svec.size = " << svec.size() << endl;
    f.close();
    
    for (auto elem: svec) {
        in.clear();
        in.str(elem);
        string word;
        while(in >> word) {
            cout << word << " ";
        }
    }
    return svec;
}

int main()
{
    //8.1
    // read(cin);

    //8.9
    // read(cin);

    //p282
    // cout << "hi!" << endl;
    // cout << "hi!" << ends;

    //8.4
    // vector<string> svec;
    // svec = read_to_svec(svec,"data.txt");

    //8.5
    // vector<string> wvec;
    // wvec = read_to_wvec(wvec,"data.txt");

    //8.8
    // ifstream fstrm("data.txt");
    // string s;
    // while (getline(fstrm,s)) {
    //     cout << s << endl;
    // }

    // ofstream o("data.txt", fstream::app);
    // o.close();

    // cout << "data.txt after append mode and close: " << endl;

    // ifstream fstrm("data.txt");
    // string s1;
    // while (getline(fstrm,s1)) {
    //     cout << s1 << endl;
    // }

    // ofstream o2("data.txt");
    // o2.close();

    // cout << "data.txt after default mode and close: " << endl;

    // ifstream fstrm2("data.txt");
    // string s2;
    // while (getline(fstrm2,s2)) {
    //     cout << s2 << endl;
    // }
    // cout << endl;

    //8.10
    // vector<string> svec;
    // copy_line_and_repeat(svec,"data.txt");

    //8.11
    // vector<string> svec;
    // copy_line_and_repeat2(svec,"data.txt");

    return 0;
}