
#include <algorithm>
#include <array>
#include <atomic>
#include <cassert>
#include <cmath>
#include <complex>
#include <condition_variable>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <valarray>
#include <vector>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

template<typename T>
class _DisplayType;

template<typename T>
void _displayType(T&& t);

#define PEEK(x) LOG(INFO) << #x << ": [" << (x) << "]"

/* template end */

class Base {
 public:
  Base(Base* b = nullptr) : base_(b ? b : this) { }
  virtual ~Base() = default;
  virtual int callFoo() {
    return base_->foo();
  }
  virtual int foo() {
    return 0;
  }
  Base* base_ = nullptr;
};

class Derived : public Base {
 public:
  Derived() : Base(this) { }
  int foo() {
    return 1;
  }
};

TEST(Foo, Bar) {
  Derived dd;
  EXPECT_EQ(1, dd.callFoo());
  Base* bb = &dd;
  EXPECT_EQ(1, bb->callFoo());
  EXPECT_EQ(0, Base().callFoo());
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  return RUN_ALL_TESTS();
}

