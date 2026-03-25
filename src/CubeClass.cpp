#include <iostream>
#include "../include/CubeClass.hpp"

Cube::Cube()
{
	const char	*colors = "UDFBLR";
	for (size_t i = 0; i < 6; i++) {
		for (size_t j = 0; j < 9; j++) {
			_faces[i][j] = *colors;
		}
		colors++;
	}
};

Cube::~Cube(){};

void Cube::getRow(int face, int row, char out[3])
{
    for (int i = 0; i < 3; i++)
        out[i] = _faces[face][row * 3 + i];
}

void Cube::setRow(int face, int row, char in[3])
{
    for (int i = 0; i < 3; i++)
        _faces[face][row * 3 + i] = in[i];
}

void Cube::getRowRev(int face, int row, char out[3])
{
    for (int i = 0; i < 3; i++)
    {
        out[i] = _faces[face][row * 3 + (2 - i)];
    }
}

void Cube::setRowRev(int face, int row, char in[3])
{
    for (int i = 0; i < 3; i++)
    {
        _faces[face][row * 3 + (2 - i)] = in[i];
    }
}

void Cube::getCol(int face, int col, char out[3])
{
	for (int i = 0; i < 3; i++)
	{
		out[i] = _faces[face][col + i * 3];
	}
};

void Cube::setCol(int face, int col, char in[3])
{
	for (int i = 0; i < 3; i++)
	{
		_faces[face][col + i * 3] = in[i];
	}
};

void Cube::getColRev(int face, int col, char out[3])
{
    for (int i = 0; i < 3; i++)
    {
        out[i] = _faces[face][col + (2 - i) * 3];
    }
}

void Cube::setColRev(int face, int col, char in[3])
{
    for (int i = 0; i < 3; i++)
    {
        _faces[face][col + (2 - i) * 3] = in[i];
    }
}

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
    char buf[3];

    getRow(F, 0, tmp);
	getRow(R, 0, buf);
    setRow(F, 0, buf);
	getRow(B, 0, buf);
    setRow(R, 0, buf);
	getRow(L, 0, buf);
    setRow(B, 0, buf);
    setRow(L, 0, tmp);
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
    char buf[3];

    getRow(F, 2, tmp);
	getRow(L, 2, buf);
    setRow(F, 2, buf);
	getRow(B, 2, buf);
    setRow(L, 2, buf);
	getRow(R, 2, buf);
    setRow(B, 2, buf);
    setRow(R, 2, tmp);
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
    char buf[3];

    getCol(F, 2, tmp);
	getCol(D, 2, buf);
    setCol(F, 2, buf);
	getCol(B, 2, buf);
    setCol(D, 2, buf);
	getCol(U, 2, buf);
    setCol(B, 2, buf);
    setCol(U, 2, tmp);
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
    char buf[3];

    getCol(F, 0, tmp);
	getCol(U, 0, buf);
    setCol(F, 0, buf);
	getCol(B, 0, buf);
    setCol(U, 0, buf);
	getCol(D, 0, buf);
    setCol(B, 0, buf);
    setCol(D, 0, tmp);
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




void	Cube::display()
{
	const char	*faces = "UDFBLR";
	for (size_t i = 0; i < 6; i++) {
		std::cout << *faces << std::endl;
		faces++;
		for (size_t j = 0; j < 9; j++) {
			std::cout << _faces[i][j];
			if ((j + 1) % 3 == 0)
				std::cout << std::endl;
		}
	}
};

