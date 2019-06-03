#include "my_exception.cpp"

class Foo
{
public:
  ~Foo()
  {
    throw my_exception("Foo exception");
  }
};

class Bar
{
public:
  Bar()
  {
    throw my_exception("Bar exception");
  }
};

int main(int argc, char const *argv[]) {
  try {
    Foo f;
    Bar b;
  }
  catch (const std::exception & e){
    std::cout << "ERROR:" << e.what() << std::endl;
  }
  return 0;
}
