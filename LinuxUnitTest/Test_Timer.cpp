extern "C" {
#include "timer.h"
#include "timefn.h"
}
 
#include "CppUTest/TestHarness.h"
 
static Time the_time;
static const int start_sec = 123;
static const int start_nsec = 456789000;
static const int delay_sec = 8;
static const int delay_nsec = 111111000; // start_nsec + delay_nsec < 10^9
 
TEST_GROUP(Timer)
{
    /* Class variables available to all tests in the group */
	Timer timer;
	Delay remaining;
 
    /* Standard setup/teardown methods of xUnit tests */
	void setup() {
		timer = timer_new();
		time_set(&the_time, start_sec, start_nsec);
		/* [...] */
	}
 
	void teardown() {
		timer_free(timer);
		/* [...] */
	}
 
    /* Helper functions specific to the test group */
	void start_timer_with_delay(long sec, long nsec)
	{
		timer_set_real_delay(timer, sec, nsec);
		timer_start(timer);
	}
 
	void ensure_remaining_is(long sec, long nsec)
	{
		CHECK_EQUAL(sec, delay_get_seconds(remaining));
		CHECK_EQUAL(nsec, delay_get_nanoseconds(remaining));
	}
}
;
 
TEST(Timer, NewIsNotStarted)
{
	CHECK(!timer->started);
}
/* [...] */
TEST(Timer, GetRemainingTimeWithNanosecondPrecision_ShiftOfSeconds)
{
	start_timer_with_delay(delay_sec, delay_nsec);
	time_set(&the_time, start_sec + delay_sec - 5, start_nsec + delay_nsec + 1000);
 
	remaining = timer_get_remaining_time(timer);
 
	ensure_remaining_is(4, 999999000);
}