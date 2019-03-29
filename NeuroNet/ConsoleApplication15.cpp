// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Perceptron.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

int main()
{
	using namespace perceptron;
	srand(time(NULL));
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	
	Perceptron brain(10, 8);

	for (int x = 0; x < 500; x++)
	{
		for (int y = 0; y < 500; y++)
		{
			value_t v = value_t(sampling);
			val_conteiner_t input = {value_t(x -250)*200, v, v, v, v, v, v, value_t(y - 250)*200};
			val_conteiner_t output = brain.compute(input);
			float a = output[0];
			float b = output[1];
			float c = output[2];
			a = a / sampling / 2 + 0.5;
			b = b / sampling / 2 + 0.5;
			c = c / sampling / 2 + 0.5;
			SetPixel(mydc, x, y, RGB(a * 255, b * 255, c * 255));
		}
	}
	
	ReleaseDC(myconsole, mydc);
	std::cin.get();
}

