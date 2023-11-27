#include "sortedSingle.h"
#include "..\\catch_amalgamated.hpp"
#include <sstream>
#include <iostream>

using namespace std;

/**************************** part a ****************************************/

TEST_CASE("sortedSingle::sortedSingle - the constructor")
{
    sortedSingle list1;
    REQUIRE(list1.empty() == true);
    REQUIRE(list1.size() == 0);
}


TEST_CASE("sortedSingle::~sortedSingle - the destructor")
{
    sortedSingle list1;
    REQUIRE(list1.empty() == true);
}


/* empty */
TEST_CASE("sortedSingle::empty - determine if a list is empty")
{
    sortedSingle list1;
    list1.insert(9);
    REQUIRE(list1.empty() == false);
}


TEST_CASE("sortedSinge::empty - determines if a list is empty")
{
    sortedSingle list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    REQUIRE(list1.empty() == false);
}


/* find */
TEST_CASE("sortedSingle::find - find 1,2")
{
    sortedSingle list1;
    list1.insert(4);
    list1.insert(1);
    REQUIRE(list1.find(1) == true);
    REQUIRE(list1.find(2) == false);
}


TEST_CASE("sortedSingle::find - find 1,2,3")
{
    sortedSingle list1;
    list1.insert(4);
    list1.insert(1);
    list1.insert(3);
    list1.insert(9);
    list1.insert(0);
    REQUIRE(list1.find(1) == true);
    REQUIRE(list1.find(2) == false);
    REQUIRE(list1.find(3) == true);
}


/* size */
TEST_CASE("sortedSingle::size - size of 3")
{
    sortedSingle list;
    list.insert(2);
    list.insert(4);
    list.insert(3);

    int size = list.size();

    REQUIRE(list.size() == 3);
}


TEST_CASE("sortedSingle::size - size of 0")
{
    sortedSingle list;

    REQUIRE(list.size() == 0);
}


/* retrieve position */
TEST_CASE("sortedSingle::retrievePosition - position = 2")
{
    sortedSingle list;

    REQUIRE(list.retrievePosition(2) == 0);

    list.insert(1);
    list.insert(2);
    list.insert(3);

    REQUIRE(list.retrievePosition(2) == 2);
}


TEST_CASE("sortedSingle::retrievePosition - position = 1,2,3,4,5,6")
{
    sortedSingle list;

    REQUIRE(list.retrievePosition(1) == 0);
    REQUIRE(list.retrievePosition(2) == 0);
    REQUIRE(list.retrievePosition(3) == 0);
    REQUIRE(list.retrievePosition(4) == 0);
    REQUIRE(list.retrievePosition(5) == 0);
    REQUIRE(list.retrievePosition(6) == 0);

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    REQUIRE(list.retrievePosition(1) == 1);
    REQUIRE(list.retrievePosition(2) == 2);
    REQUIRE(list.retrievePosition(3) == 3);
    REQUIRE(list.retrievePosition(4) == 4);
    REQUIRE(list.retrievePosition(5) == 5);
    REQUIRE(list.retrievePosition(6) == 6);

}


/**************************** part b ****************************************/
/* insert */

TEST_CASE("sortedSingle::insert - insert three number")
{
    sortedSingle list;
    ostringstream sout;

    list.insert(40);
    list.insert(30);
    list.insert(20);
    list.insert(10);

    list.insert(25);
    list.insert(60);

    list.print(sout);
    REQUIRE(sout.str() == "10, 20, 25, 30, 40, 60");



    REQUIRE(list.find(10) == true);
    REQUIRE(list.find(22) == false);
    REQUIRE(list.find(30) == true);
    REQUIRE(list.size() == 6);
}


TEST_CASE("sortedSingle::print")
{
    sortedSingle list;
    string seperator = ", ";
    stringstream out;

    list.insert(1);
    list.insert(2);

    list.print(out, seperator);

    REQUIRE(out.str() == "1, 2");

}


/**************************** part c ****************************************/
TEST_CASE("sortedSingle::remove - middle")
{
    sortedSingle list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.remove(20);

    REQUIRE(list.size() == 2);
    REQUIRE(list.find(20) == false);
}


TEST_CASE("sortedSingle::remove - beginning")
{
    sortedSingle list;
    stringstream out, out2;
    string seperator = " ";

    list.insert(15);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(25);

    list.print(out, seperator);

    REQUIRE(out.str() == "10 15 20 25 30");
    REQUIRE(list.size() == 5);

    list.remove(10);
    list.print(out2, seperator);

    REQUIRE(out2.str() == "15 20 25 30");
    REQUIRE(list.size() == 4);
}


TEST_CASE("sortedSingle::remove - end")
{
    sortedSingle list;
    stringstream out, out2;
    string seperator = " ";

    list.insert(15);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(25);

    list.print(out, seperator);

    REQUIRE(out.str() == "10 15 20 25 30");
    REQUIRE(list.size() == 5);

    list.remove(30);
    list.print(out2, seperator);

    REQUIRE(out2.str() == "10 15 20 25");
    REQUIRE(list.size() == 4);
}


TEST_CASE("sortedSingle::clear - 1")
{
    sortedSingle list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.clear();

    REQUIRE(list.size() == 0);
}


TEST_CASE("sortedSingle::clear - 2")
{
    sortedSingle list;

    list.clear();

    REQUIRE(list.size() == 0);
}


TEST_CASE("sortedSingle::clear - 3")
{
    sortedSingle list;

    list.insert(10);
    list.clear();

    REQUIRE(list.size() == 0);
}