
#include "selection_sort.h"
#include "min_element.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <random>

template<class FwdIt, class Compare = std::less<>>
void
cxx(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
  for (auto it = first; it != last; ++it) {
    auto const selection = std::min_element(it, last, cmp);
    std::iter_swap(selection, it);
    //assert(std::is_sorted(first, std::next(it), cmp));
  }
}

void
selection_sort(std::vector<int>& a)
{
  for (size_t i = 0; i < a.size(); ++i) {
    auto it = a.begin() + i;
    auto ptr = a.data() + i;
    auto sz  = a.size() - i;
    const auto min_it = std::min_element(it, a.end());
    const auto min_pos = min_element(ptr, sz);
    assert(min_it ==  a.begin() + min_pos + i);
    std::swap(a[i + min_pos], a[i]);
    assert(std::is_sorted(a.begin(), std::next(it)));
  }
}

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
  //std::cout << a << std::endl;
  selection_sort(a.data(), a.size());
  //std::cout << a << std::endl;
  //std::cout << c << std::endl;
  selection_sort(c);
  //std::cout << c << std::endl;
  assert(c == save);
  assert(a == save);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

