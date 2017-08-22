// TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include <iostream>

int main(int argc, _TCHAR* argv[])
{
   std::cout << "******* gTESTs *******" << std::endl;

   //set the output file here
   testing::GTEST_FLAG(output) = "xml:report.xml";

   testing::GTEST_FLAG(filter) = "*";

   //checks for google test flags
   testing::InitGoogleTest(&argc, argv);
   //runs all tests
   // ret_val = 0 ... Success
   // ret_val = 1 ... Failure
   int ret_val = RUN_ALL_TESTS();
   std::cout << std::endl;

   std::cin.get();
   return ret_val;
}

