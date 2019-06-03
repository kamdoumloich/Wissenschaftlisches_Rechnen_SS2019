#include <iostream>
#include <string>
#include <exception>
#include <utility>

class my_exception
{
private:
  std::string msg = "";

public:
  void my_exception(std::string);
  virtual const char* what() const noexcept;
};
