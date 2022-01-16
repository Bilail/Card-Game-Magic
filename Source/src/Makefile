CXX = g++
CXXVers = -std=c++17

build/%.o : %.cpp
		$(CXX) $(CXXVers) $< -c -o $@

main : ../build/Util.o build/StrColor.o build/Card.o build/CreatureCard.o build/LandCard.o build/GameCards.o build/Deck.o build/Player.o build/Game.o build/Main.o
		 $(CXX) $(CXXVers) $^ -o $@
		 ./$@