## LOICH KAMDOUM DEAMENI. MAT-Nr: 506520

## Uebung 1

```c++

#include <iostream>

using namespace std;

int fakultaet(int nummer);

int fakultaet(int nummer)
{
  if (nummer == 0)
    return 1;
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
```

## Uebung 2

```c++

#include <iostream>

using namespace std;

bool schaltjahr short jahr);

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

```
