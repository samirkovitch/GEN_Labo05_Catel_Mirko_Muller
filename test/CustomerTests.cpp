

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include "../src/Customer.h"


TEST(customer_Test, statement)
{
    Customer customer("Customer");
    customer.addRental( Rental( Movie("film1"), 1));
    customer.addRental( Rental( Movie( "film2", Movie::NEW_RELEASE ), 2));
    customer.addRental( Rental( Movie("film3", Movie::CHILDRENS), 3 ));

    std::string expected = "Rental Record for Customer\n\tfilm1\t2\n\tfilm2\t6\n\tfilm3\t1.5\nAmount owed is 9.5\nYou earned 4 frequent renter points";

    EXPECT_EQ(customer.statement(),expected);
}

