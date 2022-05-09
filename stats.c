#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;
}

int emailAlertCallCount = 0;

int ledAlertCallCount = 0;

void emailAlerter(void)
{
    emailAlertCallCount = 1;
}

void ledAlerter(void)
{
    ledAlertCallCount = 1;
}
