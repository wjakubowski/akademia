#ifndef TESTS_H
#define TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "list.h"

using namespace testing;
using namespace std;

TEST(constructors, emptyConstructor)
{
    List list;
    EXPECT_EQ(list.getSize(),0);
}

TEST(methods, insertTest)
{
    int value = 70324;
    List list;
    EXPECT_EQ(list.getSize(),0);
    list.insert(value);
    EXPECT_EQ(list.getSize(),1);
    EXPECT_EQ(list.getIndex(0),value);
    EXPECT_ANY_THROW(list.getIndex(1););

}

TEST(constructors, constructorFromTable)
{
    int table[]{1,2,3,4};
    unsigned tableSize = sizeof(table)/sizeof(*table);
    EXPECT_EQ(tableSize, 4);
    List list(table,tableSize);
    EXPECT_EQ(list.getSize(),tableSize);
    for(unsigned i=0; i<tableSize; ++i)
        EXPECT_EQ(list.getIndex(i), table[i]);
}

TEST(methods, containsElement)
{
    List list;
    int value = 4233;
    EXPECT_FALSE(list.contains(value));
    list.insert(value);
    EXPECT_TRUE(list.contains(value));

    value = 3222;
    EXPECT_FALSE(list.contains(value));
    list.insert(value);
    EXPECT_TRUE(list.contains(value));
}

TEST(methods, reverseNodes)
{
    int table[]{1,2,3,4};
    unsigned tableSize = sizeof(table)/sizeof(*table);
    List list(table,tableSize);
    list.reverse();
    for(unsigned i=0; i<tableSize; ++i)
        EXPECT_EQ(list.getIndex(i), table[tableSize-i-1]);
}

TEST(methods, toString)
{
    int table[]{1,2,3,4};
    unsigned tableSize = sizeof(table)/sizeof(*table);
    List list(table,tableSize);
    EXPECT_EQ(list.toString(), "[1 -> 2 -> 3 -> 4 -> ]");
}

TEST(methods, equals)
{
    int table[]{1,2,3,4};
    unsigned tableSize = sizeof(table)/sizeof(*table);
    List list1(table,tableSize);
    EXPECT_TRUE(List::equal(list1, table, tableSize));
    List list2(table,tableSize);
    EXPECT_TRUE(List::equal(list1, list2));
    list1.insert(7,2);
    EXPECT_FALSE(List::equal(list1, table, tableSize));
    EXPECT_FALSE(List::equal(list1, list2));
}

TEST(methods, insertOnEmpty)
{
    int tableBefore1[]{};
    int tableAfter1[]{7};
    List list1(tableBefore1, 0);
    EXPECT_TRUE(List::equal(list1,tableBefore1,0));
    list1.insert(7,0);
    EXPECT_TRUE(List::equal(list1,tableAfter1,1));
}


TEST(methods, insertOnFirstPosition)
{
    int tableBefore2[]{1,2,3};
    int tableAfter2[]{7,1,2,3};
    List list2(tableBefore2, 3);
    EXPECT_TRUE(List::equal(list2,tableBefore2,3));
    list2.insert(7,0);
    EXPECT_TRUE(List::equal(list2,tableAfter2,4));
}

TEST(methods, insertOnMidlePosition)
{
    int tableBefore3[]{1,2,3};
    int tableAfter3[]{1,7,2,3};
    List list3(tableBefore3, 3);
    EXPECT_TRUE(List::equal(list3,tableBefore3,3));
    list3.insert(7,1);
    EXPECT_TRUE(List::equal(list3,tableAfter3,4));
}

TEST(methods, insertOnLastPosition)
{
    int tableBefore4[]{1,2,3};
    int tableAfter4[]{1,2,3,7};
    List list4(tableBefore4, 3);
    EXPECT_TRUE(List::equal(list4,tableBefore4,3));
    list4.insert(7);
    EXPECT_TRUE(List::equal(list4,tableAfter4,4));
}

TEST(methods, removeTheOnlyElement)
{
    int tableBefore1[]{1};
    int tableAfter1[]{};
    List list1(tableBefore1, 1);
    EXPECT_TRUE(List::equal(list1,tableBefore1,1));
    list1.remove();
    EXPECT_TRUE(List::equal(list1,tableAfter1,0));
}

TEST(methods, removeOnFirstPosition)
{
    int tableBefore2[]{1,2,3};
    int tableAfter2[]{2,3};
    List list2(tableBefore2, 3);
    EXPECT_TRUE(List::equal(list2,tableBefore2,3));
    list2.remove(0);
    EXPECT_TRUE(List::equal(list2,tableAfter2,2));
}

TEST(methods, removeOnMidlePosition)
{
    int tableBefore3[]{1,2,3};
    int tableAfter3[]{1,3};
    List list3(tableBefore3, 3);
    EXPECT_TRUE(List::equal(list3,tableBefore3,3));
    list3.remove(1);
    EXPECT_TRUE(List::equal(list3,tableAfter3,2));
}

TEST(methods, removeOnLastPosition)
    {
    int tableBefore4[]{1,2,3};
    int tableAfter4[]{1,2};
    List list4(tableBefore4, 3);
    EXPECT_TRUE(List::equal(list4,tableBefore4,3));
    list4.remove();
    EXPECT_TRUE(List::equal(list4,tableAfter4,2));
}



#endif // TESTS_H
