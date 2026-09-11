/*
=====> Recursion
Recursion is when a function calls itself directly or indirectly.In order to
solve a problem by breaking down into smaller versions of the same problem.

---> A recursive function has 2 essential parts

1. Base case : A condition where it stops calling itself and just returns a
value. Without it infinite recursion happens and your cpu falls into
segmentation fault or  in the stack overflow. So its crucial for a recursive
function to have a base case where we stop further calling itself and get the
desired output. example -> if(count == 10);

2. Recursive Case : This is where the function calls itself with an input which
is smaller or closer to the base case

  */
#include <iostream>

using std::cout;

void fn(int count) {
  if (count == 10)
    return;
  count++;
  cout << "count = " << count << '\n';
  fn(count);

  /*
  This is how it works in the heap
   STORED (push)                    POPPED (pop)

   ______________                  ______________
  |  fn(10)      |  <-- last in   |  fn(10)      |  --> first out
  |______________|                |______________|
         ^                               |
         |                               v
   ______________                  ______________
  |  fn(9)       |                |  fn(9)       |
  |______________|                |______________|
         ^                               |
         |                               v
   ______________                  ______________
  |  ...         |                |  ...         |
  |______________|                |______________|
         ^                               |
         |                               v
   ______________                  ______________
  |  fn(1)       |                |  fn(1)       |
  |______________|                |______________|
         ^                               |
         |                               v
   ______________                  ______________
  |  fn(0)       |                |  fn(0)       |  --> last out
  |______________|                |______________|
         ^                               |
         |                               v
   ______________                  ______________
  |  main()      |                |  main()      |
  |______________|                |______________|

  each call PUSHES on top          each return POPS from the top
  (arrows point UP as new           (arrows point DOWN as frames
   frames get added)                  get removed, top first)
    */
}
int main() {
  int count = 0;
  fn(count);
  cout << "The main count => " << count << '\n';
  return 0;
}
