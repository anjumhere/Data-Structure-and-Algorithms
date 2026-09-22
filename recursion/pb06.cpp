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
// QUESTION 2: Combination Sum
// ============================================================================
void solveQ2_CombinationSum(const std::vector<int> &candidates, int target,
                            int index, std::vector<int> &currentComb,
                            std::vector<std::vector<int>> &result) {
  /*
   * HOW THIS IS SOLVED (Unlimited Element Selection Backtracking):
   * 1. Base Case 1: If target == 0, we found a valid combination that sums to
   * target. Save 'currentComb' into 'result' and return.
   * 2. Base Case 2: If target < 0 or index == candidates.size(), the current
   * branch is invalid or out of bounds. Return immediately.
   * 3. Recursive Step - Choice 1 (Reuse current element): If candidates[index]
   * <= target, add it to 'currentComb' and recurse WITHOUT incrementing 'index'
   * (since reuse is allowed).
   * 4. Recursive Step - Choice 2 (Skip current element): Recurse by
   * incrementing 'index' to index + 1 to move on to the next number, ensuring
   * no duplicate combinations are produced.
   */
  if (target == 0) {
    result.push_back(currentComb);
    return;
  }
  if (target < 0 || index == static_cast<int>(candidates.size())) {
    return;
  }

  // Option 1: Take candidate[index] (if valid) and keep same index for reuse
  if (candidates[index] <= target) {
    currentComb.push_back(candidates[index]);
    solveQ2_CombinationSum(candidates, target - candidates[index], index,
                           currentComb, result);
    currentComb.pop_back(); // Backtrack
  }

  // Option 2: Skip candidate[index] and move to next
  solveQ2_CombinationSum(candidates, target, index + 1, currentComb, result);
}

// ============================================================================
// QUESTION 3: Word Break
// ============================================================================
bool solveQ3_WordBreak(const std::string &s, int start,
                       const std::vector<std::string> &dict) {
  /*
   * HOW THIS IS SOLVED (String Partitioning Recursion):
   * 1. Base Case: If 'start' reaches s.length(), the entire string s has been
   * successfully partitioned into valid dictionary words. Return true.
   * 2. Recursive Step: Iterate through every possible end index 'end' from
   * (start + 1) to s.length().
   * 3. Extract prefix substring s.substr(start, end - start).
   * 4. If this prefix exists in 'dict', recursively check if the remainder
   * s[end...] can also be broken down.
   * 5. If any recursive call returns true, propagate true up. If loop finishes
   * with no match, return false.
   */
  if (start == static_cast<int>(s.length())) {
    return true;
  }

  for (int end = start + 1; end <= static_cast<int>(s.length()); ++end) {
    std::string prefix = s.substr(start, end - start);
    bool inDict = (std::find(dict.begin(), dict.end(), prefix) != dict.end());

    if (inDict && solveQ3_WordBreak(s, end, dict)) {
      return true;
    }
  }

  return false;
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

  // Test Q2
  std::cout << "\n--- Q2: Combination Sum ---\n";
  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  std::vector<int> comb;
  std::vector<std::vector<int>> combResult;
  solveQ2_CombinationSum(candidates, target, 0, comb, combResult);
  std::cout << "Combinations for target 7 using {2, 3, 6, 7}:\n";
  for (const auto &c : combResult) {
    std::cout << "  [ ";
    for (int x : c)
      std::cout << x << " ";
    std::cout << "]\n";
  }

  // Test Q3
  std::cout << "\n--- Q3: Word Break ---\n";
  std::string s = "leetcode";
  std::vector<std::string> dict = {"leet", "code"};
  bool canBreak = solveQ3_WordBreak(s, 0, dict);
  std::cout << "Can '" << s << "' be broken down using {\"leet\", \"code\"}? "
            << (canBreak ? "Yes" : "No") << "\n";

  return 0;
}