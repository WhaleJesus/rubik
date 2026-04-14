#pragma once

class Cube;

typedef struct s_cords
{
	int	face;
	int	row;
	int	col;
}	t_cords;

class AI
{
	private:
		int			_moves;
		long long	_time;
		Cube&		_cube;

	public:
		AI(Cube& c);
		~AI();

		int			getMoves() const;
		void		incrementMoves();
		void		resetMoves();

		long long	getTime() const;
		void		setTime(long long time);

		Cube&		getCube();
		const Cube&	getCube() const;

		t_cords		findCenterColor(char c);
};
