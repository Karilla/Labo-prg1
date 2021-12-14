#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getAllWord(string text);

int main()
{
    vector<string> v1;
    vector<string> v2;
    string text;
    size_t begin = 0;
    size_t end;
    string sub;
    getline(cin,text,'\0');
    bool x = true;

    for(int i = 0; i < text.size();i++)
    {
        if(!isalnum(text[i]) or ispunct(text[i]))
        {
            if(!sub.empty())
            {
                v1.push_back(sub);
            }
            sub = "";
        }
        else
        {
            sub.push_back(text[i]);
        }
    }
    cout << v1.size() << endl;

    sort(v1.begin(),v1.end());

    int compteur = 0;
    for(int i = 0; i < v1.size();i++)
    {
       if(find(v2.begin(), v2.end(), v1[i]) != v2.end()) 
        {
            
        } 
        else
        {
            cout << v1[i] << endl;
        }
    }

    for(int i = 0; i < v2.size();i++)
    {
        cout << v2[i] << endl;
    }
}

/**
 * @brief Get the All Word object
 * 
 * @param text 
 * @return vector<string> 
 */
vector<string> getAllWord(string text)
{

}