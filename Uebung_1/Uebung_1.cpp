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

int main()
{
    short nummer;

    cout << "Geben Sie eine Nummer ein: ";
    cin >> nummer;

    if (nummer > 0) {
      std::cout << "Ergebnis "<<nummer <<"! = "<<fakultaet(nummer)<<endl;
    }

    return 0;
}
