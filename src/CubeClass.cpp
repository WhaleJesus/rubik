#include <iostream>
#include "../include/CubeClass.hpp"
#include "../include/rubik.hpp"

Cube::Cube()
{
	const char	*colors = "WYGBOR";
	for (size_t i = 0; i < 6; i++) {
		for (size_t j = 0; j < 9; j++) {
			_faces[i][j] = *colors;
		}
		colors++;
	}
};

Cube::~Cube(){};

char 	Cube::get(int face, int row, int col) const
{
	return _faces[face][row * 3 + col];
};

void	Cube::rotateFaceClockwise(int f)
{
    char tmp[9];

    tmp[0] = _faces[f][6];
    tmp[1] = _faces[f][3];
    tmp[2] = _faces[f][0];
    tmp[3] = _faces[f][7];
    tmp[4] = _faces[f][4];
    tmp[5] = _faces[f][1];
    tmp[6] = _faces[f][8];
    tmp[7] = _faces[f][5];
    tmp[8] = _faces[f][2];

    for (int i = 0; i < 9; i++)
        _faces[f][i] = tmp[i];
};

void Cube::moveU()
{
    rotateFaceClockwise(U);

    char tmp[3];

	tmp[0] = _faces[F][0];
	tmp[1] = _faces[F][1];
	tmp[2] = _faces[F][2];

	_faces[F][0] = _faces[R][0];
	_faces[F][1] = _faces[R][1];
	_faces[F][2] = _faces[R][2];

	_faces[R][0] = _faces[B][8];
	_faces[R][1] = _faces[B][7];
	_faces[R][2] = _faces[B][6];

	_faces[B][8] = _faces[L][0];
	_faces[B][7] = _faces[L][1];
	_faces[B][6] = _faces[L][2];

	_faces[L][0] = tmp[0];
	_faces[L][1] = tmp[1];
	_faces[L][2] = tmp[2];
}

void Cube::moveU(int direction)
{
    if (direction == 1)			// U
	{
		std::cout << "U";
        moveU();
	}
    else if (direction == -1)   // U'
    {
		std::cout << "U'";
        moveU();
        moveU();
        moveU();
    }
    else if (direction == 2)    // U2
    {
		std::cout << "U2";
        moveU();
        moveU();
    }
	std::cout << std::endl;
}

void Cube::moveD()
{
    rotateFaceClockwise(D);

    char tmp[3];

	tmp[0] = _faces[F][6];
	tmp[1] = _faces[F][7];
	tmp[2] = _faces[F][8];

	_faces[F][6] = _faces[L][6];
	_faces[F][7] = _faces[L][7];
	_faces[F][8] = _faces[L][8];
	
	_faces[L][6] = _faces[B][2];
	_faces[L][7] = _faces[B][1];
	_faces[L][8] = _faces[B][0];
	
	_faces[B][0] = _faces[R][8];
	_faces[B][1] = _faces[R][7];
	_faces[B][2] = _faces[R][6];

	_faces[R][6] = tmp[0];
	_faces[R][7] = tmp[1];
	_faces[R][8] = tmp[2];
}

void Cube::moveD(int direction)
{
    if (direction == 1)
	{
		std::cout << "D";
        moveD();
	}
    else if (direction == -1)
    {
		std::cout << "D'";
        moveD();
        moveD();
        moveD();
    }
    else if (direction == 2)
    {
		std::cout << "D2";
        moveD();
        moveD();
    }
	std::cout << std::endl;
}

void Cube::moveR()
{
    rotateFaceClockwise(R);

    char tmp[3];

	tmp[0] = _faces[F][2];
	tmp[1] = _faces[F][5];
	tmp[2] = _faces[F][8];

	_faces[F][2] = _faces[D][2];
	_faces[F][5] = _faces[D][5];
	_faces[F][8] = _faces[D][8];

	_faces[D][2] = _faces[B][2];
	_faces[D][5] = _faces[B][5];
	_faces[D][8] = _faces[B][8];

	_faces[B][2] = _faces[U][2];
	_faces[B][5] = _faces[U][5];
	_faces[B][8] = _faces[U][8];

	_faces[U][2] = tmp[0];
	_faces[U][5] = tmp[1];
	_faces[U][8] = tmp[2];
}

void Cube::moveR(int direction)
{
    if (direction == 1)
	{
		std::cout << "R";
        moveR();
	}
    else if (direction == -1)
    {
		std::cout << "R'";
        moveR();
        moveR();
        moveR();
    }
    else if (direction == 2)
    {
		std::cout << "R2";
        moveR();
        moveR();
    }
	std::cout << std::endl;
}

void Cube::moveL()
{
    rotateFaceClockwise(L);

    char tmp[3];

	tmp[0] = _faces[F][0]; 
	tmp[1] = _faces[F][3]; 
	tmp[2] = _faces[F][6];

	_faces[F][0] = _faces[U][0];
	_faces[F][3] = _faces[U][3];
	_faces[F][6] = _faces[U][6];

	_faces[U][0] = _faces[B][0];
	_faces[U][3] = _faces[B][3];
	_faces[U][6] = _faces[B][6];

	_faces[B][0] = _faces[D][0];
	_faces[B][3] = _faces[D][3];
	_faces[B][6] = _faces[D][6];

	_faces[D][0] = tmp[0];
	_faces[D][3] = tmp[1];
	_faces[D][6] = tmp[2];
}

void Cube::moveL(int direction)
{
    if (direction == 1)
	{
		std::cout << "L";
        moveL();
	}
    else if (direction == -1)
    {
		std::cout << "L'";
        moveL();
        moveL();
        moveL();
    }
    else if (direction == 2)
    {
		std::cout << "L2";
        moveL();
        moveL();
    }
	std::cout << std::endl;
}

void Cube::moveF()
{
    rotateFaceClockwise(F);

	char tmp[3];
    
	tmp[0] = _faces[U][6];
	tmp[1] = _faces[U][7];
	tmp[2] = _faces[U][8];

	_faces[U][6] = _faces[L][8];
	_faces[U][7] = _faces[L][5];
	_faces[U][8] = _faces[L][2];

	_faces[L][8] = _faces[D][2];
	_faces[L][5] = _faces[D][1];
	_faces[L][2] = _faces[D][0];

	_faces[D][2] = _faces[R][0];
	_faces[D][1] = _faces[R][3];
	_faces[D][0] = _faces[R][6];

	_faces[R][0] = tmp[0];
	_faces[R][3] = tmp[1];
	_faces[R][6] = tmp[2];
}

void Cube::moveF(int direction)
{
    if (direction == 1)
	{
		std::cout << "F";
        moveF();
	}
    else if (direction == -1)
    {
		std::cout << "F'";
        moveF();
        moveF();
        moveF();
    }
    else if (direction == 2)
    {
		std::cout << "F2";
        moveF();
        moveF();
    }
	std::cout << std::endl;
}

void Cube::moveB()
{
	rotateFaceClockwise(B);

	char tmp[3];

	tmp[0] = _faces[R][2];
	tmp[1] = _faces[R][5];
	tmp[2] = _faces[R][8];

	_faces[R][2] = _faces[D][8];
	_faces[R][5] = _faces[D][7];
	_faces[R][8] = _faces[D][6];

	_faces[D][8] = _faces[L][6];
	_faces[D][7] = _faces[L][3];
	_faces[D][6] = _faces[L][0];

	_faces[L][6] = _faces[U][0];
	_faces[L][3] = _faces[U][1];
	_faces[L][0] = _faces[U][2];

	_faces[U][0] = tmp[0];
	_faces[U][1] = tmp[1];
	_faces[U][2] = tmp[2];
}

void Cube::moveB(int direction)
{
    if (direction == 1)
	{
		std::cout << "B";
        moveB();
	}
    else if (direction == -1)
    {
		std::cout << "B'";
        moveB();
        moveB();
        moveB();
    }
    else if (direction == 2)
    {
		std::cout << "B2";
        moveB();
        moveB();
    }
	std::cout << std::endl;
}

void setColor(char c) 
{
	if (c == 'W')
		std::cout << WHITE;
	else if (c == 'O')
		std::cout << ORANGE;
	else if (c == 'G')
		std::cout << GREEN;
	else if (c == 'R')
		std::cout << RED;
	else if (c == 'B')
		std::cout << BLUE;
	else if (c == 'Y')
		std::cout << YELLOW;
	std::cout << c;
}

void Cube::printRow(int face, int start)
{
    for (int i = 0; i < 3; i++)
        setColor(_faces[face][start + i]);
}

void Cube::printRowRaw(int face, int start)
{
    for (int i = 0; i < 3; i++)
        setColor(_faces[face][start + i]);
}

void Cube::display()
{
    // --- U face ---
    for (int i = 0; i < 3; i++)
    {
        std::cout << "     ";
        printRow(U, i * 3);
        std::cout << std::endl;
    }

    // --- Middle layer: L F R B ---
    for (int i = 0; i < 3; i++)
    {
        std::cout << " ";
        printRow(L, i * 3);
        std::cout << " ";
        printRow(F, i * 3);
        std::cout << " ";
        printRow(R, i * 3);
        std::cout << " ";
        printRow(B, i * 3);
        std::cout << std::endl;
    }

    // --- D face ---
    for (int i = 0; i < 3; i++)
    {
        std::cout << "     ";
        printRow(D, i * 3);
        std::cout << std::endl;
    }
}

