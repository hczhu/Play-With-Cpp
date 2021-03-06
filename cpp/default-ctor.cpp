
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
// #include <gtest/gmock.h>

template<typename T>
class _DisplayType;

template<typename T>
void _displayType(T&& t);

#define PEEK(x) LOG(INFO) << #x << ": [" << (x) << "]"

/* template end */

struct A {
  int a;
  int b = 1;
  int c{-2};
  std::string haha = "haha";
};

TEST(Foo, Bar) {
  A a;
  EXPECT_EQ("haha", a.haha);

  const A& aa = A();
  EXPECT_EQ("haha", aa.haha);

  A aaa{
    .a = 10,
    .b = 20,
  };
  EXPECT_EQ(10, aaa.a);
  EXPECT_EQ(-2, aaa.c);
  EXPECT_EQ("haha", aaa.haha);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  return RUN_ALL_TESTS();
}

