#include "../include/AI.hpp"
#include "../include/CubeClass.hpp"

AI::AI(Cube& c) : _cube(c), _moves(0), _time(0)
{};

AI::~AI(){};

int	AI::getMoves() const
{
	return _moves;
}

void	AI::incrementMoves()
{
	_moves++;
};

void	AI::resetMoves()
{
	_moves = 0;
};

long long	AI::getTime() const
{
	return _time;
}

void	AI::setTime(long long time)
{
	_time = time;
};

Cube&	AI::getCube()
{
	return _cube;
}

Cube&	AI::getCube() const
