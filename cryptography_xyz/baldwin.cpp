#include <iostream>
#include <vector>
#include <string>

using namespace std;

int P(int size, vector<int> in){
  int possibilities[size];
  possibilities[0]=1;
  possibilities[1]=1;
  for(int i=2;i<in.size()+1;i++){
    if(in[i-2]*10+in[i-1]>26||in[i-2]*10+in[i-1]<10){
      possibilities[i] = possibilities[i-1];
    }
    else if((in[i-2]*10+in[1])>=10&&in[i-2]*10+in[i-1]<26){
      possibilities[i] =  possibilities[i-1]+possibilities[i-2];
    }
  }
  return possibilities[size];
}

void D(string prefix, vector<int> theString, int i){
  if(i==theString.size()){
    cout << prefix << endl;
    return;
  }
    prefix += char(theString[i]+97);
    D(prefix, theString, i+1);
    if(theString[i]*10+theString[i+1]>=10&&theString[i]*10+theString[i+1]<26&&i+1<theString.size()){
      prefix = prefix.substr(0,prefix.length()-1);
      prefix+=char((theString[i]*10+theString[i+1])+97);
    D(prefix,theString,i+2);
  }
}

int main(){
string inputLine;
while(getline(cin,inputLine)){
vector<int> intString;

cout << "The input is: ";
for(int i=0; i<inputLine.length(); i++){
  int thisValue = inputLine.at(i) - '0';
  intString.push_back(thisValue);
  cout << intString[i];
}
cout << endl;
cout << "The number of possibile decodings is: " << P(intString.size(),intString) << endl;
if(P(intString.size(),intString)<30){
cout << "The possible decodings are: " << endl;
D("",intString,0);
}
}
}

