/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 *
 * https://leetcode.com/problems/exam-room/description/
 *
 * algorithms
 * Medium (37.43%)
 * Total Accepted:    13.5K
 * Total Submissions: 35.6K
 * Testcase Example:
 * '["ExamRoom","seat","seat","seat","seat","leave","seat"]\n[[10],[],[],[],[],[4],[]]'
 *
 * In an exam room, there are N seats in a single row, numbered 0, 1, 2, ...,
 * N-1.
 *
 * When a student enters the room, they must sit in the seat that maximizes the
 * distance to the closest person.  If there are multiple such seats, they sit
 * in the seat with the lowest number.  (Also, if no one is in the room, then
 * the student sits at seat number 0.)
 *
 * Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat()
 * returning an int representing what seat the student sat in, and
 * ExamRoom.leave(int p) representing that the student in seat number p now
 * leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have
 * a student sitting in seat p.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"],
 * [[10],[],[],[],[],[4],[]]
 * Output: [null,0,9,4,2,null,5]
 * Explanation:
 * ExamRoom(10) -> null
 * seat() -> 0, no one is in the room, then the student sits at seat number 0.
 * seat() -> 9, the student sits at the last seat number 9.
 * seat() -> 4, the student sits at the last seat number 4.
 * seat() -> 2, the student sits at the last seat number 2.
 * leave(4) -> null
 * seat() -> 5, the student sits at the last seat number 5.
 *
 *
 * ​​​​​​​
 *
 * Note:
 *
 *
 * 1 <= N <= 10^9
 * ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times
 * across all test cases.
 * Calls to ExamRoom.leave(p) are guaranteed to have a student currently
 * sitting in seat number p.
 *
 *
 */

#include <list>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class ExamRoom {
  list<int> seated;
  int size;

 public:
  ExamRoom(int N) { size = N; }

  int seat() {
    if (seated.size() == 0) {
      seated.push_back(0);
      return 0;
    }

    int d = -1, p = -1;
    auto it1 = seated.begin();
    auto it3 = seated.begin();
    if (*it1 > 0) {
      d = *it1;
      p = 0;
      it3 = it1;
    }
    auto it2 = it1;
    ++it2;

    while (true) {
      if (it2 == seated.end()) {
        if (*it1 <= size - 1) {
          int d2 = size - 1 - *it1;
          if (d2 > d) {
            p = size - 1;
            d = d2;
            it3 = it2;
          }
        }
        break;
      }

      if (*it2 - *it1 > 1) {
        int p2 = (*it1 + *it2) / 2;
        int d2 = (*it2 - *it1) / 2;
        if (d2 > d) {
          p = p2;
          d = d2;
          it3 = it2;
        }
      }

      ++it1;
      ++it2;
    }

    seated.insert(it3, p);

    return p;
  }

  void leave(int p) {
    for (auto it = seated.begin(); it != seated.end(); ++it) {
      if (*it == p) {
        seated.erase(it);
        return;
      }
    }
  }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
