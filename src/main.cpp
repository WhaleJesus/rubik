#include "../include/rubik.hpp"
#include "../include/CubeClass.hpp"

int	main(void)
{
	Cube cube;

	cube.moveF(1);
	cube.display();
	cube.moveR(1);
	cube.display();
}
