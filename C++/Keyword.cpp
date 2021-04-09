#include<bits/stdc++.h>
using namespace std;
using namespace std:: chrono;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
unordered_map<char,char> map_1;
unordered_map<char,char> map_2;

/*unordered_map<char,char> inverse_map(unordered_map<char,char> &map)
{
    unordered_map<char,char> inv;
    for_each(map.begin(), map.end(),
                [&inv] (const std::pair<char,char> &p)
                {
                    inv.insert(make_pair(p.second, p.first));
                });
    return inv;
}*/

string decryption(string input){

    //unordered_map<char, char> inverted = inverse_map(map);

    string decrypt;
    for(int i=0;i<input.size();i++){
        decrypt+=map_2[input[i]];
    }

    return decrypt;

}

string ecryption(string input){

    string encrypt;

    for(int i=0;i<input.size();i++){
        encrypt+=map_1[input[i]];
    }

    return encrypt;

}

void removeSpecialCharacter(string &s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z')
        {
            s.erase(i, 1);
            i--;
        }
    }
}
string removeDuplicates(string s){
  unordered_map<char,bool> exists;
  string output;
  for(int i=0;i<s.size();i++){
    exists[s[i]]=true;
  }

  for(int i=0;i<s.size();i++){
    if(exists[s[i]]==true){
        output+=s[i];
        exists[s[i]]=false;
    }
  }

  return output;
}

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


int main(){

	init_code();

    string input;
    string key;
    cout<<"Enter the message : "<<endl;
    getline(cin,input);
    cout<<"Enter the Key : "<<endl;
    getline(cin,key);
    clock_t time_req;
    time_req=clock();
    auto start = high_resolution_clock::now();

    removeSpecialCharacter(input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    cout<<input<<endl;


    key = removeDuplicates(key);
    removeSpecialCharacter(key);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    cout<<key<<endl;

    
    string string_difference;

    string all_char ="abcdefghijklmnopqrstuvwxyz";

    string temp = key;
    sort(temp.begin(),temp.end());

    set_difference(all_char.begin(), all_char.end(), temp.begin(), temp.end(), back_inserter(string_difference));
    //cout << "In string1 but not string2: " << string_difference << std::endl;

    string final_key_used = key+string_difference;
    //cout<<final_key_used<<endl;
    //cout<<all_char<<endl;
    for(int i=0;i<all_char.size();i++){
        map_1[all_char[i]]=final_key_used[i];
    }

    for(int i=0;i<all_char.size();i++){
    	map_2[final_key_used[i]]=all_char[i];
    }




    string encrypted = ecryption(input);

    cout<<"Encypted Text : "<<encrypted<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<"\nTime taken: "<<duration.count()<<" us"<<endl;
    string decrypted = decryption(encrypted);

    cout<<"Decrypted Text : "<<decrypted<<endl;



    time_req = clock() - time_req;
    cout << "Linear " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
    /*time_req = clock() - time_req;
    cout << "Linear " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;*/


}
