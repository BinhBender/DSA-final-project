/*
 * Functions I reuse to save time in reprogramming basic validation and the program loop.
 * Comments inside function definitions are the parts that get altered when adapted for a new program.
 */
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "system_data.h"
#include "city.h"
#include "pathfinder.h"
#include "helper.h"
#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

/*
 * Greets the user, asks if they are a  returning or new user.
 * @RETURN True if new user
 */
bool greeting();

/*
 * The menu that allows the user to pick between new or reutrning user,
 * called by Greeting();
 * @RETURN True if new user.
 */
bool user_menu();

/*
 *
 */
bool new_user_greeting();

/*
 * Main Menu for all options user can choose from.
 * Template formatted for 4 options, follow instructions in function to change for more/less.
 */
bool main_menu(); // incomplete


/*
 * Starts the pathfinder from a to b.
 * @PARAMS PathFinder pf, the graph
*/
void start_route(PathFinder&);

/*
 * Route Menu, set your starting location and destination.
 * @PARAM Bool start, true if user has set a starting location
 * @PARAM Bool end, true if user has set a destination
 */

void route_menu(bool &start, bool &end); // incomplete

/*
 * Sensitivity  Menu, set your Sensitivity levels, default is average.
 *
 */

void sensitivity_menu(); // incomplete

/*
 *Secret menu to update the PM2.5 levels of the cities or
 *generate new paths between the cities
 */
void Debug_Menu(PathFinder&);
/*
 * Asks the user if they would like to try  the again.
 * @RETURN True or false
 */
bool repeat();

/*
 * Warmly ends the program.
 */
void outro();

/*
 * Unserializes the city PM2.5 data and puts it into SystemData::PM25
 */
void initPMTable();

/*
 * Unserializes city coordinate data and puts it into SystemData::cityCoordinates
 */
void initcityCoords();

/*
 * Unserializes city connections and puts it into SystemData::CityPaths
 */
void initcityPathReader();

/*
 * Uses the unserialized data, wrapping them into a city class, and storing it in SystemData::IndexToCity
 */
void init();
#endif
