//Cryptoanalysis of Additive Cipher (Caesar's cipher)
#include "iostream"
#include "string.h"
#include "vector"
using namespace std;
string encryption_call(string& plain_text, int& key)
{
    string cipher_text = "";
    char ch;
    for (int i = 0; i < plain_text.size(); i++) {
        if(isupper(plain_text[i])){
            ch = (char)(((plain_text[i] - 'A') + key)% 26 + 'A'); 
        }else{
            ch = (char)(((plain_text[i] - 'a') + key)% 26 + 'a'); 
        }
    cipher_text += ch;                 
    }
    return cipher_text;
}


vector<string> BruteForce(string& cipherText, int keyRange){
    vector<string> res{};
    for(int shift=0;shift<keyRange;shift++){
        string possiblePlaintext = "";
        char ch;
        for(int i=0;i<cipherText.size();i++){
            int cVal = 0,pVal = 0;
            if(isupper(cipherText[i])){
                cVal = cipherText[i] - 'A';
                pVal = (cVal + shift)%26;
                ch = (char)(pVal+'A');
            }else{
                cVal = cipherText[i] - 'a';
                pVal = (cVal + shift)%26;
                ch = (char)(pVal+'a');
            }
            possiblePlaintext += ch;
        }
        res.push_back(possiblePlaintext);
    }
    return res;
}
int main(){
    int rangeOfPossibleKeys = 26;
    string plaintext, ciphertext;
    int key;
    cout<<"Additive Cipher (Cryptanalysis) \n";
    cout<<"Enter plain-text : ";    cin>>plaintext;
    cout<<"\nEnter Key : "; cin>>key;
    string cipher = encryption_call(plaintext, key);
    cout<<"\nCipher-text : "<<cipher;
    vector<string> possible_plaintexts{};
    possible_plaintexts = BruteForce(cipher,26);
    cout<<"\nAll possible plain-texts can be : ";
    for(const auto & it : possible_plaintexts){
        cout<<"\n"<<it;
    }
    return 0;
}
