
#include "insertion_sort.h"
#include "upper_bound.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <random>

std::ostream&
operator<<(std::ostream& stream, const std::vector<value_type>& a)
{
  stream << '(';

  for (auto i = a.begin(); i != a.end(); ++i) {
    stream << *i;

    if (std::next(i) != a.end()) {
      stream << ',';
    }
    else {
      stream << ')';
    }
  }

  return stream;
}

template<class FwdIt, class Compare = std::less<>>
void
insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
  for (auto it = first; it != last; ++it) {
    auto const insertion = std::upper_bound(first, it, *it, cmp);
    std::rotate(insertion, it, std::next(it));
    assert(std::is_sorted(first, std::next(it), cmp));
  }
}

// overloaded version for std::vector
void
insertion_sort(std::vector<value_type>& a)
{
  for (size_t i = 0; i  < a.size(); ++i) {
    auto it = a.begin() + i;
    auto const insertion = std::upper_bound(a.begin(), it, a[i]);
    const size_type ins = upper_bound(a.data(), i, a[i]);
    assert(insertion == a.begin() + ins);
    std::rotate(insertion, it, it + 1);
    assert(std::is_sorted(a.begin(), it + 1));
  }
}


int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 1, 2, 4, 5, 6, 6, 7, 8};
  assert(std::is_sorted(a.begin(), a.end()));
  auto save = a;
  {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(a.begin(), a.end(), g);
  }
  auto c = a;
  //std::cout << c << std::endl;
  insertion_sort(c);
  //std::cout << c << std::endl;
  assert(c == save);
  //std::cout << a << std::endl;
  insertion_sort(a.data(), a.size());
  //std::cout << a << std::endl;
  assert(a == save);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

