#include "bagDynamic.h"
#include "gtest/gtest.h"

TEST(dynamic, constructor) {
	bag myBag;
	EXPECT_EQ(true, myBag.isEmpty());
	EXPECT_EQ(0, myBag.get_size());
	EXPECT_EQ(30, myBag.get_capacity());
}

TEST(dynamic, copyConstructor){
	bag myBag;
	EXPECT_EQ(true, myBag.isEmpty());
	EXPECT_EQ(0, myBag.get_size());
	EXPECT_EQ(30, myBag.get_capacity());
	myBag.insert(0);
	myBag.insert(0);
	myBag.insert(2);
	myBag.insert(2);
	myBag.insert(3);
	myBag.insert(4);
	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(6, myBag.get_size());
	EXPECT_EQ(30, myBag.get_capacity());	

	bag newBag(myBag);
	EXPECT_EQ(false, newBag.isEmpty());
	EXPECT_EQ(6, newBag.get_size());
	EXPECT_EQ(30, newBag.get_capacity());
}

TEST(dynamic, erase){
	bag myBag;
	myBag.insert(1);
	myBag.insert(0);
	myBag.insert(2);
	myBag.insert(2);
	myBag.insert(1);
	myBag.insert(3);
	myBag.insert(1);

	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(7, myBag.get_size());
	EXPECT_EQ(3, myBag.erase(1));
	EXPECT_EQ(4, myBag.get_size());

	EXPECT_EQ(2, myBag.erase(2));
	EXPECT_EQ(2, myBag.get_size());

	EXPECT_EQ(0, myBag.erase(17));
	EXPECT_EQ(2, myBag.get_size());

}

TEST(dynamic, eraseOne){
	bag myBag;
	myBag.insert(0);
	myBag.insert(0);
	myBag.insert(2);
	myBag.insert(2);
	myBag.insert(1);
	myBag.insert(3);
	myBag.insert(1);
	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(7, myBag.get_size());

	EXPECT_EQ(true, myBag.eraseOne(2));
	EXPECT_EQ(false, myBag.eraseOne(22));
	EXPECT_EQ(6, myBag.get_size());

	EXPECT_EQ(true, myBag.eraseOne(0));
	EXPECT_EQ(true, myBag.eraseOne(1));
	EXPECT_EQ(false, myBag.eraseOne(11));
	EXPECT_EQ(4, myBag.get_size());
}

TEST(dynamic, insert){
	bag myBag;

	myBag.insert(8);
	myBag.insert(8);
	myBag.insert(9);
	myBag.insert(10);
	myBag.insert(10);
	myBag.insert(11);
	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(6, myBag.get_size());
	EXPECT_EQ(30, myBag.get_capacity());
	EXPECT_EQ(2, myBag.count(8));
	EXPECT_EQ(2, myBag.count(10));
	EXPECT_EQ(0, myBag.count(27));
	EXPECT_EQ(true, myBag.find(9));
}

TEST(dynamic, getSize){
	bag myBag;

	myBag.insert(8);
	myBag.insert(8);
	myBag.insert(9);
	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(3, myBag.get_size());

	EXPECT_EQ(true, myBag.eraseOne(9));
	EXPECT_EQ(false, myBag.isEmpty());
	EXPECT_EQ(2, myBag.erase(8));
	EXPECT_EQ(0, myBag.get_size());

	
}

TEST(dynamic, find){
	bag myBag;
	myBag.insert(0);
	myBag.insert(0);
	myBag.insert(2);
	myBag.insert(2);
	myBag.insert(0);
	myBag.insert(1);
	myBag.insert(3);
	myBag.insert(1);
	myBag.insert(4);

	EXPECT_EQ(9, myBag.get_size());
	EXPECT_EQ(true, myBag.find(0));
	EXPECT_EQ(true, myBag.find(1));
	EXPECT_EQ(true, myBag.find(2));
	EXPECT_EQ(true, myBag.find(3));
	EXPECT_EQ(true, myBag.find(4));

	myBag.eraseOne(0);
	myBag.eraseOne(3);
	myBag.eraseOne(4);
	EXPECT_EQ(6, myBag.get_size());
	EXPECT_EQ(true, myBag.find(0));
	EXPECT_EQ(false, myBag.find(3));
	EXPECT_EQ(false, myBag.find(4));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}