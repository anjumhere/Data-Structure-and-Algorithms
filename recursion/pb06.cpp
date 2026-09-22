#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
 * ============================================================================
 * QUESTION LIST
 * ============================================================================
 * Q1: Subset Generation (Power Set)
 *     Given an array of integers, generate all possible subsets (the power
 * set).
 *
 * Q2: Combination Sum
 *     Given an array of distinct integers and a target integer, find all unique
 *     combinations where the numbers sum to the target. (Elements can be
 * reused).
 *
 * Q3: Word Break Problem (Check Possibility)
 *     Given a string and a dictionary of words, determine if the string can be
 *     segmented into a space-separated sequence of one or more dictionary
 * words.
 *
 * Q4: Tower of Hanoi
 *     Given N disks and 3 rods (Source, Auxiliary, Destination), print the
 * sequence of moves to transfer all disks from Source to Destination following
 * standard rules.
 *
 * Q5: Grid Path Counting with Obstacles
 *     Given an m x n matrix where 0 represents an open cell and 1 represents an
 *     obstacle, return the number of unique paths from top-left (0,0) to
 * bottom-right (m-1, n-1).
 * ============================================================================
 */

// ============================================================================
// QUESTION 1: Subset Generation (Power Set)
// ============================================================================
void solveQ1_Subsets(const std::vector<int> &nums, int index,
                     std::vector<int> &current,
                     std::vector<std::vector<int>> &result) {
  /*
   * HOW THIS IS SOLVED (Pick / Don't Pick Pattern):
   * 1. Base Case: When 'index' reaches nums.size(), we have made a binary
   * choice (include or exclude) for every element in the array. Save 'current'
   * into 'result'.
   * 2. Recursive Step - Choice 1 (Exclude): Advance to index + 1 without
   * pushing nums[index].
   * 3. Recursive Step - Choice 2 (Include): Push nums[index] to 'current',
   * recurse to index + 1, and then backtrack by popping nums[index] so the
   * vector remains clean for future paths.
   * 4. This branches 2^N times, generating all possible subsets cleanly.
   */
  if (index == static_cast<int>(nums.size())) {
    result.push_back(current);
    return;
  }

  // Option 1: Exclude nums[index]
  solveQ1_Subsets(nums, index + 1, current, result);

  // Option 2: Include nums[index]
  current.push_back(nums[index]);
  solveQ1_Subsets(nums, index + 1, current, result);

  // Backtrack
  current.pop_back();
}

// ============================================================================
// MAIN FUNCTION (Test Cases)
// ============================================================================
int main() {
  std::cout << "===========================================\n";
  std::cout << " testing 5 Moderate Recursion Solutions\n";
  std::cout << "===========================================\n\n";

  // Test Q1
  std::cout << "--- Q1: Subsets ---\n";
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> current;
  std::vector<std::vector<int>> subsetsResult;
  solveQ1_Subsets(nums, 0, current, subsetsResult);
  std::cout << "Subsets of {1, 2, 3}:\n";
  for (const auto &subset : subsetsResult) {
    std::cout << "  { ";
    for (int x : subset)
      std::cout << x << " ";
    std::cout << "}\n";
  }

  return 0;
}