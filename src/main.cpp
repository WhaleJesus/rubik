#include "../include/rubik.hpp"
#include "../include/CubeClass.hpp"

#include <cstdlib>

void	exit_error(std::string msg)
{
	std::cout << "Error: " << msg << std::endl;
	exit(0);
}

size_t ft_strlen(char *s)
{
	size_t i = 0;

	while (s[i])
		i++;
	return (i);
}

int	strContains(const char *s, char c) 
{
	size_t i = 0;
	
	while (s[i])
	{
		if (s[i] == c) 
			return (1);
		i++;
	}
	return (0);
}

void parseInput(char **av, Cube *c) 
{
	size_t	len = ft_strlen(av[1]);
	char	*s = av[1];
	int		backwards = 0;

	const char	*faces = "UDFBLR";

	for (size_t i = 0; i < len; i++)
	{
		backwards = 1;
		if (!strContains(faces, s[i]) && s[i] != '\'' && s[i] != ' ' && s[i] != '2')
			exit_error("Wrong input");
		if (i + 1 < len && s[i + 1] == '\'')
			backwards = -1;
		else if (i + 1 < len && s[i + 1] == '2')
			backwards = 2;
		if (s[i] == 'U')
			c->moveU(backwards);
		else if (s[i] == 'D')
			c->moveD(backwards);
		else if (s[i] == 'F')
			c->moveF(backwards);
		else if (s[i] == 'B')
			c->moveB(backwards);
		else if (s[i] == 'L')
			c->moveL(backwards);
		else if (s[i] == 'R')
			c->moveR(backwards);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error("Wrong number of args");
		
	Cube cube;

	parseInput(av, &cube);
	cube.display();
}
