#include "iostream"
#include "string.h"
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
string decryption(string & cipher_text, int & key){
    string plain_text ="";
    char ch;
    for (int i = 0; i < cipher_text.size(); i++) {
        if(isupper(cipher_text[i])){
            if((cipher_text[i] - 'A') - key<0)
            ch = (char)(((cipher_text[i] - 'A') - key + 26)% 26 + 'A'); 
            else 
            ch = (char)(((cipher_text[i] - 'A') - key)% 26 + 'A'); 
        }else{
            if((cipher_text[i] - 'a') - key<0)
            ch = (char)(((cipher_text[i] - 'a') - key + 26)% 26 + 'a'); 
            else 
            ch = (char)(((cipher_text[i] - 'a') - key)% 26 + 'a'); 
        }
    plain_text += ch;                 
    }
    return plain_text;
}
int main(){
    string plaintext, ciphertext;
    int key;
    cout<<"Encryption and Decryption (Additive Cipher)\n";
    cout<<"Enter plain-text : ";    cin>>plaintext;
    cout<<"Enter Key : "; cin>>key;
    string cipher = encryption_call(plaintext, key);
    cout<<"Cipher-text : "<<cipher;
    cout<<"\nDecrypting, "<<cipher<<" gives : "<<decryption(cipher,key);
    return 0;
}