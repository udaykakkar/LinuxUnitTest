#include <CppUTest/CommandLineTestRunner.h>
#include<iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
	CommandLineTestRunner::RunAllTests(argc, argv);
	//getchar();
	return 0;
}
