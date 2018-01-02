//
//  main.cpp
//  535_Encode and Decode TinyURL
//
//  Created by Colin on 01/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

// longUrl <-> 6-char code

class Solution {
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = "";
        if(url2code.find(longUrl) != url2code.end())
            code = url2code[longUrl];
        else
            code = generate_new_code(longUrl);
        
        return "http://tinyurl.com/" + code;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.length() - 6);
        return code2url[code];
    }
    
private:
    string generate_new_code(string &longUrl) {
        string newCode = "";
        static const int sourceLen = source.length();
        srand(NULL);
        while(true) {
            newCode = "";
            for(int i = 0; i < 6; ++i) {
                newCode += source[random() % sourceLen];
            }
            if(code2url.find(newCode) == code2url.end()) {
                code2url[newCode] = longUrl;
                url2code[longUrl] = newCode;
                break;
            }
        }
        return newCode;
    }
    const string source = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    cout << sol.encode("http://google.com") << endl;
    cout << sol.encode("http://google.com") << endl;
    
    return 0;
}
