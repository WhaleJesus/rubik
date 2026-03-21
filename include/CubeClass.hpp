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
		
		void getRow(int face, int row, char out[3]);
		void setRow(int face, int row, char in[3]);
		void getRowRev(int face, int row, char out[3]);
		void setRowRev(int face, int row, char in[3]);
		
		void getCol(int face, int col, char out[3]);
		void setCol(int face, int col, char in[3]);
		void getColRev(int face, int col, char out[3]);
		void setColRev(int face, int col, char in[3]);
		
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
		
		void	display();
		void 	applyMove(const std::string& move);
		void 	applySequence(const std::string& sequence);
};
