#include <bits/stdc++.h>
using namespace std;

int compareNumbers(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    
    if (len1 < len2) {
        return -1; 
    } else if (len1 > len2) {
        return 1;
    }
    
    for (int i = 0, j = 0; i < len1 && j < len2; i++, j++) {
        if (a[i] < b[j]) {
            return -1;
        } else if (a[i] > b[j]) {
            return 1;
        }
    }
    
    return 0;
}

class PhotoFile {
    public:
    vector<string> name; 
    PhotoFile(vector<string> name) {
        this->name = vector<string>(name);
    }
    
    void printName() {
        for (int i = 0; i < name.size(); i++) {
            cout << name[i]; 
        }
        cout << "\n";
    }
    
    bool operator < (const PhotoFile &other) const {
        int n = (int)this->name.size();
        int m = (int)other.name.size();
        
        int len = min(n, m);
        for (int i = 0; i < len; i++) {
            if (isdigit(this->name[i][0])) {
                if (isalpha(other.name[i][0])) {
                    return true;
                } else {
                    int numcmp = compareNumbers(this->name[i], other.name[i]);
                    if (numcmp == 0) {
                        continue;
                    }
                    
                    return numcmp < 0;
                }
            } else {
                if (isalpha(other.name[i][0])) {
                    if (this->name[i] == other.name[i]) {
                        continue;
                    }
                    
                    return this->name[i] < other.name[i];
                } else {
                    return false;
                }
            }
        }
        
        if (n < m) {
            return true;
        }
        
        return false;
    }
};

vector<string> parseName(string);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<PhotoFile> photoFiles;
    string fileName;
    while (cin >> fileName) {
        photoFiles.push_back(PhotoFile(parseName(fileName)));     
    }
    
    sort(photoFiles.begin(), photoFiles.end());
    
    for (int i = 0; i < photoFiles.size(); i++) {
        photoFiles[i].printName();
    }
    
	return 0;
}

vector<string> parseName(string name) {
    vector<string> result;
    string curString;
    
    curString = name[0];
    for (int i = 1; i < name.length(); i++) {
        if ((isdigit(name[i]) && isalpha(name[i - 1])) || 
            (isalpha(name[i]) && isdigit(name[i - 1]))) {
            result.push_back(curString);
            curString = name[i];
        } else {
            curString += name[i];
        }
    }
    
    result.push_back(curString);
    return result;
}
