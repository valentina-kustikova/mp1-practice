#pragma once

enum exeption_type { ContainerIsFull, ContainerIsEmpty, BadContainerSize, BadIndex };

struct Exeption
{
	exeption_type exp_type;

	Exeption(exeption_type type)
	{
		exp_type = type;
	}
};