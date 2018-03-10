//snake functions from header
#include "stdafx.h"

//process input - set up a function pointer with typedef - use to call an apply force method
void processInput(b2Body& player) {
	forcFunc applied = nullptr;
	//based on keyboard input, assign function
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		applied = &applyForceUp;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		applied = &applyForceLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		applied = &applyForceDown;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		applied = &applyForceRight;
	}
	if (applied != nullptr) {
		applied(player); //call function pointer
		score--;//lower score every move
	}

	//make null
	applied = nullptr;
}

//call applyforcetoccenter, move up in coord system
void applyForceUp(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(0, -10000.0f), true);
}

//call applyforcetoccenter
void applyForceDown(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(0, 10000), true);
}

//call applyforcetoccenter
void applyForceLeft(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(-30000, 0), true);
}

//call applyforcetoccenter
void applyForceRight(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(30000, 0), true);
}

//set velocity to 0 - stop snake
void stopMoving(b2Body& player) {
	b2Vec2 newVel(0.0f, 0.0f);
	player.SetLinearVelocity(newVel);
}

//reverse gravity, set to negative current gravity
void reverseGravity(b2World& world) {
	b2Vec2 newGrav = -(world.GetGravity());
	world.SetGravity(newGrav);
}

//prompt user, create array, add -1000,-1000 to end
void setupTargets(int cnt, int windowW, int windowH) {
	int count = 0;
	cout << "How many targets? (1 - " << cnt << "): ";
	while (count < 1 || count > cnt) {
		cin >> count;
		if (count < 1 || count > cnt) {
			cout << "\nPlease enter a suitable number (1 - " << cnt << "): " << endl;
		}
	}

	targetLocations = new b2Vec2[count + 1];

	srand(time(NULL)); 
	
	for (int i = 0; i < (count + 1); i++) {
		
		b2Vec2 newPos(rand() % windowW, rand() % windowH);
		targetLocations[i] = newPos;

		if (i == count) { //add -1000,-1000 to end
			b2Vec2 pos(-1000, -1000);
			targetLocations[i] = pos;
		}
	}

	currentLocation = targetLocations[currentTarget];

}

bool selectNextTarget() {

	//increment, move through targetLocations
	currentTarget++;
	currentLocation = targetLocations[currentTarget];

	//when at the end return false, so the window closes and score is displayed in console - game is over
	if (currentLocation.x == -1000 && currentLocation.y == -1000) {
		return false;
	}

	return true;
	
}