#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>
#include <iomanip>
#define DEBUG2

using namespace std;


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


string queries[5] =
{
    "brass fastner",
    "cable glands",
    "brass anchor",
    "electrical component",
    "brass furniture"
};


int main()
{


    int N;
    cin>>N;
    string l;
    getline(cin,l);
    for(int c=0;c<N;c++)
    {
        getline(cin,l);
        for(int c=0;c<l.size();c++) if(l[c]>='A'&&l[c]<='Z') l[c]=l[c]-'A'+'a'; 
        for(int c=0;c<l.size();c++)
        {
            if((l[c]<'a'||l[c]>'z')&&l[c]!=' ')
            {
                l = l.substr(0,c)+l.substr(c+1);
                c--;
            }
        }
        cerr<<l<<endl;
        int best = 0;
        int i = 19;
        vector<string> v=split(l,'\t');
        
        for(int c2=0;c2<5;c2++)
        {
            vector<string> querWords = split(queries[c2],' ');
            vector<string> Words = split(v[0],' ');
            int act = 0;
            for(int c3=0;c3<querWords.size();c3++)
            {
                  size_t found = -1;
                  while(1)
                  {
                      found = v[0].find((querWords[c3].size()>5?querWords[c3].substr(0,5):querWords[c3]),found+1);
                      if(found == string::npos) break;
                      if(querWords[c3] == "c" && (((found+1<l.size() && l[found+1] != ' ') || (found-1>=0&&l[found-1] != ' ')))) continue;
                      act++;
                  }
            }
            if(act>best)
            {
                best = act;
                i = c2;
            }
        }
        cout<<queries[i]<<endl;
    }

}

