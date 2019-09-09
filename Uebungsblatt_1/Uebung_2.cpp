#include <iostream>

using namespace std;

bool schaltjahr (short jahr) {
  if ((jahr % 4 == 0 && jahr % 100 != 0) || jahr % 400 == 0)
    return true;
  else
    return false;
}

int main(int argc, char const *argv[]) {

  short jahr = 0;

  if (jahr >= 0) {
    cout << "Geben Sie ein Jahr ein: ";
    cin >> jahr;

    if (schaltjahr(jahr))
      std::cout <<jahr <<" ist ein schaltjahr" << '\n';
    else
      std::cout <<jahr <<" ist kein schaltjahr" << '\n';
  }

  return 0;
}
