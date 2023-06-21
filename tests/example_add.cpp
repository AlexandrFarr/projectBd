#include <gtest/gtest.h>
//#include "../src/example.h"
//#include "../src/example.h"
#include "example.h"
#include "connectpost.h"

TEST(example, add_numbers) {
    double res;
    res = add_numbers(1.0, 2.0);

	EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(res, 42);

}


