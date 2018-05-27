//#include "Game.hpp"
//#include "Player.hpp"
//#include "main.hpp"
//
//
//Game::Game() : player_1_{ "P1" }, player_2_{ "P2" }, game_rounds_{ 3 }, winner_{ tie }
//{
//}
//
//Game::Game(Player player_1, Player player_2, short game_rounds, Winner winner) : player_1_{player_1}, player_2_{ player_2 }, game_rounds_{game_rounds}, winner_{winner}
//{
//	setup_game(player_1, player_2);
//}
//
//void Game::setup_game(Player player_1, Player player_2)
//{
//
//	std::string input_stream;
//
//	// ASK FOR PLAYER NAMES
//	std::cout << "Player 1, please enter your unique name!\n\t" << std::endl;
//	std::cin >> input_stream;
//	player_1.set_name(input_stream);
//
//	do {
//		std::cout << "Player 2, please enter your unique name!\n\t" << std::endl;
//		std::cin >> input_stream;
//		player_2.set_name(input_stream);
//	} while (player_2.read_name() == player_1.read_name());
//
//
//}
//
//
//Game::~Game()
//{
//}
