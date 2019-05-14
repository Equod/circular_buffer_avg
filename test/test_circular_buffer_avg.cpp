//
// Created by illya on 14/05/19.
//

//#CATCH_CONFIG_MAIN

#include <CircularBufferAvg.hpp>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("CircularBufferAvg", "[circular_buffer_avg]") {
  circular_buffer_avg::CircularBufferAvg<int, 5> buffer;
  SECTION("Empty buffer has avg = 0") {
    REQUIRE(buffer.GetAvg() == 0);
  }
  SECTION("Adding always 0 it avg remains 0") {
    buffer.Clear();
    for (int i = 0; i < 100; ++i) {
      REQUIRE(buffer.AddValue(0) == 0);
    }
  }
  SECTION("Simple avg") {
    buffer.Clear();
    for (const auto val : { 1, 2, 3 }) {
      buffer.AddValue(val);
    }
    REQUIRE(buffer.GetAvg() == 2);
  }

  SECTION("Buffer drops old avg after wrap") {
    buffer.Clear();
    for (int i = 0; i < 5; ++i) {
      buffer.AddValue(100);
    }
    REQUIRE(buffer.GetAvg() == 100.);
    for (int i = 0; i < 5; ++i) {
      buffer.AddValue(42);
    }
    REQUIRE(buffer.GetAvg() == Approx(42).epsilon(0.000000001));
  }
}
