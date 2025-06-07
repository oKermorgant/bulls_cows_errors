#include <number.h>
#include <vector>
#include <array>


std::pair<int,int> bullsCows(const Number &n1, const Number &n2)
{
  int bulls{0};
  std::array<ushort, 10> existing_digits{};

  for(int i = 0; i < LENGTH; ++i)
  {
    if(n1.digit(i) == n2.digit(i))
    {
      bulls++;
    }
    else
    {
      existing_digits[n1.digit(i)-'0']++;
      existing_digits[n2.digit(i)-'0']++;
    }
  }
  const auto cows = std::count(existing_digits.begin(), existing_digits.end(), 2);
  return {bulls, cows};
}

inline auto plural(int value, const std::string &name)
{
  auto display{std::to_string(value) + " " + name};
  if(value > 1)
    return display + 's';
  return display;
}


int main ()
{
  for(auto &[n1,n2]: std::vector<std::pair<int,int>>{
                         {123456, 213456},
                         {43649, 365190},
                         {639276, 5824793}})
  {
    const auto &[bulls,cows] = bullsCows(Number(n1), Number(n2));

	std::cout << n1 << " vs " << n2 << ": "
			  << plural(bulls, "bull")
			  << " and " << plural(cows, "cow") << '\n';
  }
}
