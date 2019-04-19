#include <iostream>

using namespace std;

int fakultaet(int nummer);

int fakultaet(int nummer)
{
  if (nummer == 0) {
    return 1;
  }
  else
    return nummer * fakultaet(nummer - 1);
}

int main(int argc, char const *argv[])
{
    short nummer = 1;
    while (nummer > 0) {
      std::cout << "Geben Sie eine Nummer ein: ";
      std::cin >> nummer;

      std::cout <<nummer <<"! = "<<fakultaet(nummer)<<endl;
    }

    return 0;
}
