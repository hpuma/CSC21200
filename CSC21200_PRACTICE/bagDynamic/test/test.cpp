#include "bagDynamic.h"
#include "gtest/gtest.h"

TEST(dynamic, constructor) {
	bag myBag;
	EXPECT_EQ(true, myBag.isEmpty());
	EXPECT_EQ(0, myBag.get_size());
	EXPECT_EQ(30, myBag.get_capacity());
}

TEST(dynamic, addItem) {
	bag myBag;

	myBag.insert(8);
	myBag.insert(9);
	myBag.insert(10);
	myBag.insert(11);
	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(4, myBag.get_size());
	EXPECT_EQ(30, myBag.get_capacity());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}