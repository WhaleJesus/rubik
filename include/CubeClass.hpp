#pragma once
#include <iostream>


enum Face { U, D, F, B, L, R };

class Cube
{
	private:
		char	_faces[6][9];
	public:
		Cube();
		~Cube();

		char	get(int face, int row, int col) const;	
		void	rotateFaceClockwise(int f);
		void	moveU();
		void	moveU(int direction);
		void	moveD();
		void	moveD(int direction);
		void	moveR();
		void	moveR(int direction);
		void	moveL();
		void	moveL(int direction);
		void	moveF();
		void	moveF(int direction);
		void	moveB();
		void	moveB(int direction);
		
		void	printRow(int face, int start);
		void	printRowRaw(int face, int start);
		void	display();
		void 	applyMove(const std::string& move);
		void 	applySequence(const std::string& sequence);
};
