#include <iostream>
#include <typeinfo>

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
    short nummer = 0;

    while (typeid(nummer).name() == "short") {
      if (nummer > 0) {
        cout << "Geben Sie eine Nummer ein: ";
        cin >> nummer;

        std::cout << "Ergebnis "<<nummer <<"! = "<<fakultaet(nummer)<<endl;
      }
      else {
        break;
      }
    }

    return 0;
}
