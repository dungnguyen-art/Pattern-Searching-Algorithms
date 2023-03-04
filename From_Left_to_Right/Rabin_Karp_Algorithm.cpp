#include<iostream>
#include<cmath>

using namespace std;
int main(){
    char define[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    int hashcode[1000];
    // Gán giá trị cho các kí từ [A...Z] tương ứng là [1..26]
    for (int i = 0; i<26; i++){
        hashcode[define[i]] = i+1;
    }

    int len_pat = sizeof(pat)/sizeof(pat[0])-1;
    int len_txt = sizeof(txt)/sizeof(pat[0])-1;
    int valuePAT = 0;
    int tmpValue = 0;
    for (int i=0; i<len_pat; i++){
        valuePAT += hashcode[pat[i]]*pow(10,len_pat-1 - i);
    }
    
    for (int i=0; i<= len_txt-len_pat; i++){
        if(i==0){
            for(int j=0; j<len_pat; j++){
                tmpValue += hashcode[txt[j]]*pow(10, len_pat-1-j);
            }
        }
        else{
            tmpValue = (tmpValue - hashcode[txt[i-1]]*pow(10,len_pat-1))*10 +  hashcode[txt[i+len_pat-1]];
        }
        if(tmpValue == valuePAT){
            cout << "Pattern found at index: "<< i << endl;
        }
    }
    return 0;
}