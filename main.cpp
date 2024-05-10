#include <cstdlib>
#include <functional>
#include <ostream>
#include <vector>
#include <cerrno>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using std::string;
using std::cout;
using std::cin;
// Десятичная в двоичную
string *podchet(int size, int myprimer, string  *arr)
{

  for (int i = 0; i<size; i++)
    {
      int sus = myprimer%2;
      string sus2 = std::to_string(sus);
      arr[i] = sus2;
      myprimer /= 2;
    }
  return arr;
}
// Разделитель строки
std::vector<std::string> split(std::string str, char delimiter) {
    std::string tmp{""};
    std::vector<std::string> vec;
    for(int i{0}; i < str.length(); ++i) {
        if(str[i] == delimiter) { vec.push_back(tmp); tmp = ""; continue; }
        tmp += str[i];
    }
    vec.push_back(tmp);
    return vec;
}
// Двоичная в десятичную
string podchet_2(int myprimer)
{
  int num = myprimer;
  int Value = 0;
  int base = 1;
  int temp = num;
  while(temp)
    {
      int last = temp%10;
      temp = temp/10;
      Value += last*base;
      base = base*2;
    }
  string myValue = std::to_string(Value);
  return myValue;
}

// Основа
int main()
{

  const int size = 10;
  cout << "Vvedite cho-to: ";
  string text;
  cin >> text; 
  cout << "1) 10 -> 2\n2) 2->10\nVash otvet: ";
  string otvet; 
  cin >> otvet;
  //2->10

  int myprimer;
  std::vector<std::string> res = split(text, '.');
  string mytext;
  string newarr[size];
  if (otvet == "1") {
  for (int i = 0; i<res.size(); i++)
    {  
      myprimer = std::stoi(res[i]);
      string arr[size];
      podchet(size, myprimer, arr);
        std::reverse (std::begin(arr), std::end(arr));
	for (string i : arr)
	  {
	    mytext += i;
	  }
	newarr[i] = mytext;
	for (int i=0; i<size; i++) arr[i] = "";
	mytext = "";
    }
  for (string i : newarr)
    {
      cout << i << ".";
    }
cout << "\n";
//system("pause");
return 0;
  }
  //10->2
  if (otvet == "2")
  {
  std::vector<std::string> res = split(text, '.');
  for (int i = 0; i<res.size(); i++) {
      myprimer = std::stoi(res[i]);
      for (int j = 0; j<size; j++)
      {
        string mytext = podchet_2(myprimer);
        newarr[i] = mytext;
      }
  }
  for (string i : newarr)
    {
      cout << i << ".";
    }
  }
cout << "\n";
//system("pause");
  return 0;
}
