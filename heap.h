#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data; //to hold heap elements 
  int m_arity; //ary-ness of the heap 
  PComparator comp; //comparator functor 




};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_arity(m), comp(c) {}
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data.push_back(item);
  size_t idx = data.size() - 1; //start at last index (new items)
  while (idx > 0) {
    size_t parentIdx = (idx - 1) / m_arity;
    if (comp(data[idx], data[parentIdx])) { //compare elements, returns true depending on how its defined
      std::swap(data[idx], data[parentIdx]);
      idx = parentIdx; //trickle up

    } 
    else { //it follows heap property
      break;
    }
  }
}
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  return data.front();
  // If we get here we know the heap has at least 1 item

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  data[0] = data.back(); //swapping them 
  data.pop_back();
  size_t idx = 0;
  while (true) {
    size_t childidx = idx *m_arity + 1;
    //if it has no child ->
    if (childidx >= data.size()) break;

    size_t minchild = childidx;
    for (int i = 1; i <m_arity && childidx + i < data.size(); ++i) {
      if (comp(data[childidx + i], data[minchild])) {
        minchild = childidx + i;
      }
    }
    if (comp(data[minchild], data[idx])) {
      std::swap(data[minchild], data[idx]);
      idx = minchild;
    }
    else {
      break;
    }
  }
}
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data.empty();
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data.size();
}




#endif

