#ifndef BULLS_COWS_NUMBER_H
#define BULLS_COWS_NUMBER_H
#include <string>

static constexpr char LENGTH{6};

class Number
{
private:
  std::string digits;
  uint n;
public:
  inline explicit Number(int n)
  {
    digits = std::to_string(n);
    while(digits.size() != LENGTH)
      digits = '0' + digits;
    this->n = n;
  }
  inline auto digit(size_t idx) const
  {
    return digits[idx];
  }
};


#endif
