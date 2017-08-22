#ifndef TESTSTOCK__HPP
#define TESTSTOCK__HPP

#include "Stock.hpp"
#include <gtest/gtest.h>
#include "MockTrade.h"

namespace nsTestStock {

   //--------------------------------------------------------------------------
   // TestStock
   //--------------------------------------------------------------------------
   class TestStock : public testing::Test
   {
   public:
      // Constructor
      TestStock() {};

      // Destructor
      virtual ~TestStock() {};

      // SetUp
      // prepares the TestEnvironment before every test
      // params:
      // return:
      virtual void SetUp() override;

      // TearDown
      // destroys the TestEnvironment after every test
      // params:
      // return:
      virtual void TearDown() override;

   protected:
      // Member Variables
      Stock* mpSUT;
      MockTrade* mpTradeMock;
   private:
      // Member Variables
   };

} // namespace nsTestStock

#endif //TESTSTOCK_HPP