CXX = g++
CXXVers = -std=c++17
BUILD_PATH = build

build/%.o : src/%.cpp
		$(CXX) $(CXXVers) $< -c -o $@

main : build/StrColor.o build/Card.o build/CreatureCard.o build/LandCard.o build/EnchantmentCard.o build/GameCards.o build/Deck.o build/Player.o build/Game.o build/DeckCreator.o build/Main.o
		 $(CXX) $(CXXVers) -lstdc++fs -o $@ $^ -lstdc++fs
		 ./$@

clean :
	rm -rf  build/*.o