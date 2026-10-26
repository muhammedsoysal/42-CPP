#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <sys/time.h>
#include <vector>

class PmergeMe {

private:
  std::vector<int> _vec;
  std::deque<int> _deq;

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  static int jacobsthal(int n);
  void sort(int ac, char **av);
};

template <typename T> T build_jacobsthal_sequence(size_t limit) {
  T jacobOrder;
  if (limit <= 1)
    return (jacobOrder);

  size_t last = 1;
  for (int i = 3;; i++)
  {
    size_t curr = PmergeMe::jacobsthal(i);
    if (curr > limit)
	{
      for (size_t j = limit - 1; j >= last; j--)
        jacobOrder.push_back(j);
      break;
    }
    for (size_t j  = curr - 1; j >= last; j--)
      jacobOrder.push_back(j);
    last = curr;
    if (last >= limit)
      break;
  }
  return (jacobOrder);
}

template <typename T, typename OrderT>
void insertContainer(T &mainChain, T &pend, OrderT &jacobOrder) {
  if (pend.empty())
    return;

  mainChain.insert(mainChain.begin(), pend.front());

  for (size_t i = 0; i < jacobOrder.size(); i++) {
    size_t index = jacobOrder[i];
    typename T::value_type num = pend[index];

    typename T::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), num);
    mainChain.insert(it, num);
  }
}

template <typename T, typename PairT> void sortContainer(T &t) {
  if (t.size() <= 1)
    return;

  bool hasStraggler = false;
  typename T::value_type straggler = 0;

  if (t.size() % 2 != 0) {
    hasStraggler = true;
    straggler = t.back();
    t.pop_back();
  }

  PairT pairs;

  for (size_t i = 0; i < t.size(); i += 2) {
    if (t[i] > t[i + 1])
      pairs.push_back(std::make_pair(t[i], t[i + 1]));
    else
      pairs.push_back(std::make_pair(t[i + 1], t[i]));
  }

  T largerNums;
  for (size_t i = 0; i < pairs.size(); i++)
    largerNums.push_back(pairs[i].first);

  sortContainer<T, PairT>(largerNums);

  T mainChain = largerNums;
  T pend;

  T used(pairs.size(), 0);

  for (size_t i = 0; i < mainChain.size(); i++)
  {
    for (size_t j = 0; j < pairs.size(); j++)
	{
      if (pairs[j].first == mainChain[i] && !used[j])
	  {
        used[j] = 1;
        pend.push_back(pairs[j].second);
        break;
      }
    }
  }

  T jacobOrder = build_jacobsthal_sequence<T>(pairs.size());

  insertContainer(mainChain, pend, jacobOrder);

  if (hasStraggler)
  {
    typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
	mainChain.insert(it, straggler);
  }

  t = mainChain;
}

#endif