#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

/**
 * @brief Unit Test case for inferBreach
 * 
 */


TEST_CASE("infers the breach according to limits TOO_LOW") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits TOO_HIGH") {
  REQUIRE(inferBreach(45, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits NORMAL") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}


/**
 * @brief Unit Test case for classifyTemperatureBreach
 * 
 */
TEST_CASE("Classify Temperature Breach according to Cooling Type PASSIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
}

TEST_CASE("Classify Temperature Breach according to Cooling Type HI_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 39) == NORMAL);
}

TEST_CASE("Classify Temperature Breach according to Cooling Type MED_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}

/**
 * @brief Unit Test case for checkAndAlert
 * 
 */

TEST_CASE("Check the temperature And Alert to controller") {

  AlertTarget target;
  BatteryCharacter batchar;

  batchar.coolingType = MED_ACTIVE_COOLING;
  target=TO_CONTROLLER;
  REQUIRE(target==TO_CONTROLLER);
  checkAndAlert(target, batchar, 45);
}

TEST_CASE("Check the temperature And Alert via Mail") {

  AlertTarget target;
  BatteryCharacter batchar;

  batchar.coolingType = MED_ACTIVE_COOLING;
  target=TO_EMAIL;
  REQUIRE(target==TO_EMAIL);
  checkAndAlert(target, batchar, 50);
}

/**
 * @brief Unit Test case for sendToController
 * 
 */
TEST_CASE(" Sent to controller check") {

  BreachType Btype=TOO_HIGH;
 
  REQUIRE(Btype==TOO_HIGH);

  sendToController(TOO_HIGH);
}

/**
 * @brief Unit Test case for sendToEmail
 * 
 */

TEST_CASE(" Sent to Email check") {

  BreachType Btype=TOO_HIGH;
 
  REQUIRE(Btype==TOO_HIGH);
  sendToEmail(TOO_HIGH);

  Btype=TOO_LOW;
  REQUIRE(Btype==TOO_LOW);
  sendToEmail(TOO_LOW);

  Btype=NORMAL;
  REQUIRE(Btype==NORMAL);
  sendToEmail(NORMAL);
}
