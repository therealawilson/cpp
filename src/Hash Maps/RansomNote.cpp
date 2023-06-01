#include<string>
#include <iostream>
#include <unordered_map>

using namespace std;


class Note{
public:
    bool create(string note, string document)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < document.size(); i++)
        {
            map[document[i]]++;
        }
        for (auto i : note)
        {
            if (map.find(i) == map.end() || map.at(i) == 0)
            {
                return false;
            }

            map.at(i)--;
        }   
        return true;
    }
};

int main()
{
    Note n1;

    string ransomnote = "acab";
    string document = "aabb";
    if (n1.create(ransomnote, document))
    cout << "yes a note can be made";
    else
    cout << "no, a note cannot be made";

    return 0;
}