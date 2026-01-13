/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:00:44 by csolari           #+#    #+#             */
/*   Updated: 2025/10/24 19:20:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	open_files(std::string inFileName, std::string outFileName, std::ifstream *inFile, std::ofstream *outFile)
{
	(*inFile).open(inFileName.c_str(), std::fstream::in);
	(*outFile).open(outFileName.c_str(), std::fstream::out);
	if (!(*inFile) || !(*outFile))
	{
		std::cout << "Error while opening files" << std::endl;
		(*inFile).close();
		(*outFile).close();
		return (0);
	}
	return (1);
}


void	search_and_replace(char *argv[], std::ifstream *inFile, std::ofstream *outFile)
{
	std::string		toFind;
	std::string		toReplace;
	std::string		line;
	size_t 			pos = 0;

	toFind = argv[2];
	toReplace = argv[3];
	while (getline(*inFile, line))
	{
		pos = line.find(toFind);
		while(pos != std::string::npos)
		{
			line.erase(pos, toFind.length());
			line.insert(pos, toReplace);
			pos = line.find(toFind);
		}
		(*outFile) << line << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::string		inFileName;
	std::string		outFileName;
	std::ifstream	inFile;
	std::ofstream	outFile;
	
	if (argc != 4)
		return (std::cout << "Wrong number of arguments" << std::endl, 1);
	for (int i = 1; i < argc; i++)
	{
		if(!argv[i][0])
			return (std::cout << "Invalid argument" << std::endl, 1);
	}
	inFileName = argv[1];
	outFileName = inFileName + ".replace";
	if (!open_files(inFileName, outFileName, &inFile, &outFile))
		return (1);
	search_and_replace(argv, &inFile, &outFile);
	inFile.close();
	outFile.close();
	return (0);
}
