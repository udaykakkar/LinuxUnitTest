#include "CppUTest/TestHarness.h"
#include "Printer.h"
#include "MockPrinter.h"

TEST_GROUP(Printer)
{
	Printer* printer;
	MockPrinter* mockPrinter;

	void setup()
	{
		mockPrinter = new MockPrinter();
		printer = mockPrinter;
	}
	void teardown()
	{
		delete printer;
	}
}
;

TEST(Printer, PrintConstCharStar)
{
	printer->Print("hello");
	printer->Print("hello\n");
	const char* expected = "hellohello\n";
	CHECK_EQUAL(expected, mockPrinter->getOutput());
}

TEST(Printer, PrintLong)
{
	printer->Print(1234);
	const char* expected = "1234";
	CHECK_EQUAL(expected, mockPrinter->getOutput());
}

TEST(Printer, StreamOperators)
{
	*printer << "n=" << 1234;
	const char* expected = "n=12345";
	CHECK_EQUAL(expected, mockPrinter->getOutput());
}