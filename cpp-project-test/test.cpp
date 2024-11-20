#include "catch_amalgamated.hpp"
#include "cpp_project.h"



TEST_CASE( "cpp_project::getValue() Test", "[single-file]" ) {
    REQUIRE( cpp_project::getValue() == 99 );
}