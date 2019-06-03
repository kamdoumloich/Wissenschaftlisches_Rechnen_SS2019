#include "my_exception.h"

void my_exception::my_exception(std::string msg_)
{
  msg = msg_;
}

virtual const char* my_exception::what() const noexcept
{
  return this->msg.c_str();
}
